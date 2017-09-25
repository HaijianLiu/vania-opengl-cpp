
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Boss::Boss() {
	// GameObject setting
	this->status->hp = this->sleepHP;
	this->status->damage = 30;
	// scale in real pixel
	this->transform->scale = glm::vec3(128.0f,128.0f,1.0f);
	// Collider (this,offsetX,offsetY,sizeX,sizeY) size is in real pixel && Collider is trigger ?
	this->collider = new BoxCollider(this,0.0f,0.0f,64.0f,64.0f);
	this->collider->tag = "boss";
	// OffsetObject
	this->leftTarget = new OffsetObject(this,-2.0f,0.01f);
	this->rightTarget = new OffsetObject(this,2.0f,0.01f);
	// GameObject
	for (unsigned int i = 0; i < 4; i++) {
		this->bullets.push_back(new BossBullet());
	}
	for (unsigned int i = 0; i < 7; i++) {
		this->deathWallsLeft.push_back(new BossDeathWall());
		this->deathWallsLeft.back()->right = false;
	}
	this->deathBite = new BossDeathBite();
	this->core = new BossCore();
	for (unsigned int i = 0; i < 7; i++) {
		this->deathWallsRight.push_back(new BossDeathWall());
	}
	// UIObject
	this->uiLife = new UIObject(0.0f, 0.0f, 100.0f, 2.0f);
	this->uiLife->transform->position.z += 1.0f;
	this->uiLife->active = false;
	this->uiBossBG = new UIObject(200.0f - 56.0f, -120.0f + 16.0f, 112.0f, 32.0f);
	this->uiBossBG->active = false;
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Boss::~Boss() {
	// Collider
	delete this->collider;
	// OffsetObject
	delete this->leftTarget;
	delete this->rightTarget;
	// GameObject
	delete this->core;
	deleteVector(this->deathWallsRight);
	deleteVector(this->deathWallsLeft);
	deleteVector(this->bullets);
	delete this->deathBite;
	// UIObject
	delete this->uiLife;
	delete this->uiBossBG;
}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void Boss::start() {
	// target
	this->target = getGame()->player;
	this->core->parent = this;
	this->core->target = this->target;
	this->deathBite->target = this->target;

	// DeathWall
	for (unsigned int i = 0; i < this->deathWallsRight.size(); i++) {
		this->deathWallsRight[i]->transform->position.x = this->transform->position.x + 2.24f;
		this->deathWallsRight[i]->transform->position.y = this->transform->position.y - 0.96f + 0.32f * i;
		this->deathWallsRight[i]->startPosition = this->deathWallsRight[i]->transform->position;
	}
	for (unsigned int i = 0; i < this->deathWallsLeft.size(); i++) {
		this->deathWallsLeft[i]->transform->position.x = this->transform->position.x - 2.24f;
		this->deathWallsLeft[i]->transform->position.y = this->transform->position.y - 0.96f + 0.32f * i;
		this->deathWallsLeft[i]->startPosition = this->deathWallsLeft[i]->transform->position;
	}

	// set sprite texture and slice | Animation start
	this->sprite->texture = getGame()->resources->getTexture("boss_body");
	this->uiBossBG->sprite->texture = getGame()->resources->getTexture("ui_boss_energy");
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void Boss::update() {
	/* Core Transform
	..............................................................................*/
	if (this->currentSkill == DEATH_AREA_LEFT) {
		this->core->sprite->setColor(255,0,0,255);
		this->core->target = this->leftTarget;
	}
	if (this->currentSkill == DEATH_AREA_RIGHT) {
		this->core->sprite->setColor(255,0,0,255);
		this->core->target = this->rightTarget;
	}
	if (this->currentSkill == DEATH_BITE) {
		this->core->sprite->setColor(189,29,255,255);
	}
	if (this->currentSkill == NONE_SKILL) {
		this->core->sprite->setColor(255,255,255,255);
		this->core->target = this->target;
	}
	this->core->followTarget();

	/* awake
	..............................................................................*/
	if (this->awake && this->alive) {
		/* Phase
		..............................................................................*/
		if (this->status->hp > 0.8f * this->hp) {
			this->phase = 0;
		}
		else if (this->status->hp > 0.5f * this->hp) {
			this->phase = 1;
		}
		else {
			this->phase = 2;
		}

		/* checkSkill
		..............................................................................*/
		if (this->phase > 0) {
			Boss::checkSkill();
		}

		/* UIObject
		..............................................................................*/
		this->uiLife->active = true;
		this->uiBossBG->active = true;
		this->uiLife->offset = glm::vec2(200.0f - 6.0f - 50.0f * this->status->hp / this->hp,  -120.0f + 20.0f);
		this->uiLife->transform->scale = glm::vec3(this->status->hp / this->hp * 100.0f, 2.0f, 1.0f);
		this->uiLife->sprite->setColor(255,79,108,255);

		/* body transform
		..............................................................................*/
		this->transform->position.y += 0.003f * sin(getGame()->timer->currentTime * 2.0f);

		/* Bullet
		..............................................................................*/
		if (getGame()->timer->currentTime > this->lastBullet + this->bulletColdDown) {
			this->lastBullet = getGame()->timer->currentTime;
			for (unsigned int i = 0; i < this->bullets.size(); i++) {
				if (!this->bullets[i]->active) {
					this->bullets[i]->active = true;
					this->bullets[i]->status->hp = this->bullets[i]->hp;
					this->bullets[i]->transform->position.x = this->transform->position.x - 1.5f + i;
					this->bullets[i]->transform->position.y = this->transform->position.y - 1.0f;
				}
			}
		}

		/* DeathWall && DeathArea
		..............................................................................*/
		if (this->currentSkill == DEATH_AREA_RIGHT && getGame()->timer->currentTime > this->lastSkill + this->skillDelay) {
			for (unsigned int i = 0; i < this->deathWallsRight.size(); i++) {
				this->deathWallsRight[i]->deathArea(true);
			}
		}
		else {
			if (this->target->transform->position.x - this->transform->position.x  > this->deathWallRange) {
				for (unsigned int i = 0; i < this->deathWallsRight.size(); i++) {
					this->deathWallsRight[i]->forward();
				}
			}
		}
		if (this->currentSkill == DEATH_AREA_LEFT && getGame()->timer->currentTime > this->lastSkill + this->skillDelay) {
			for (unsigned int i = 0; i < this->deathWallsLeft.size(); i++) {
				this->deathWallsLeft[i]->deathArea(false);
			}
		}
		else {
			if (this->transform->position.x - this->target->transform->position.x > this->deathWallRange) {
				for (unsigned int i = 0; i < this->deathWallsLeft.size(); i++) {
					this->deathWallsLeft[i]->forward();
				}
			}
		}

		/* DeathBite
		..............................................................................*/
		if (this->currentSkill == DEATH_BITE && getGame()->timer->currentTime > this->lastSkill + this->skillDelay) {
			this->deathBite->appear();
		}

		/* BGM
		..............................................................................*/
		if (!this->intro) {
			getGame()->resources->getAudio("boss_intro")->play();
			this->intro = true;
		}
		else {
			if (!getGame()->resources->getAudio("boss_main")->playing() && !getGame()->resources->getAudio("boss_intro")->playing()) {
				getGame()->resources->getAudio("boss_main")->play();
			}
		}
	}


	/* Death && Awake
	..............................................................................*/
	if (this->status->hp <= 0 && this->alive) {
		if (!this->awake) {
			if (abs(this->target->transform->position.x - this->transform->position.x) < this->deathWallRange) {
				this->awake = true;
				getGame()->camera->switchTarget(this);
				this->status->hp = this->hp;
				for (unsigned int i = 0; i < this->deathWallsRight.size(); i++) {
					this->deathWallsRight[i]->active = true;
				}
				for (unsigned int i = 0; i < this->deathWallsLeft.size(); i++) {
					this->deathWallsLeft[i]->active = true;
				}
			}
			else {
				this->status->hp = 1.0f;
			}
		}
		else {
			this->visible = false;
			this->alive = false;
			// getGame()->resources->getAudio("boss_main")->stop();
			getGame()->resources->iSoundEngine->stopAllSounds();
			getGame()->resources->getAudio("boss_destroy")->play();
			instantiate(getGame()->publicObjects["enemy_destroy"], this->transform);
			getGame()->camera->switchTarget(this->target);
		}
	}

	if (!this->alive && !getGame()->resources->getAudio("boss_destroy")->playing()) {
		this->active = false;
		getGame()->resources->getAudio("boss_win")->play();
	}
}


/*------------------------------------------------------------------------------
< onTriggerEnter >
------------------------------------------------------------------------------*/
void Boss::onTriggerEnter(BoxCollider* other) {
	/* Damage if tag = "bullet"
	..............................................................................*/
	if (other->tag == "bullet") {
		this->sprite->flash(0.5f);
		this->status->hp -= other->gameObject->status->damage;
	}
}


/*------------------------------------------------------------------------------
< Functions >
------------------------------------------------------------------------------*/
void Boss::checkSkill() {
	// Get Skill every skillColdDown
	if (getGame()->timer->currentTime > this->lastSkill + this->skillColdDown) {
		this->currentSkill = rand() % this->phase;
		this->lastSkill = getGame()->timer->currentTime;

		if (this->currentSkill == DEATH_BITE) {
			if (this->deathBite->active) {
				if (this->phase == 1) {
					this->currentSkill = NONE_SKILL;
				}
				else {
					this->currentSkill = DEATH_AREA;
				}
			}
		}

		if (this->currentSkill == DEATH_AREA) {
			if (rand() % 2 == 0) {
				this->currentSkill = DEATH_AREA_LEFT;
			}
			else {
				this->currentSkill = DEATH_AREA_RIGHT;
			}
		}
	}

	// Check Reset to NONE_SKILL every Update
	if (this->currentSkill == DEATH_BITE) {
		if (getGame()->timer->currentTime > this->lastSkill + this->deathBiteTime) {
			this->currentSkill = NONE_SKILL;
		}
	}

	if (this->currentSkill == DEATH_AREA_LEFT || this->currentSkill == DEATH_AREA_RIGHT) {
		if (getGame()->timer->currentTime > this->lastSkill + this->deathAreaTime) {
			this->currentSkill = NONE_SKILL;
		}
	}
}


/*------------------------------------------------------------------------------
< reset >
------------------------------------------------------------------------------*/
void Boss::reset() {
	if (this->active) {
		this->awake = false;
		this->intro = false;
		this->status->hp = this->sleepHP;
		this->phase = 0;
		this->uiBossBG->active = false;
		this->uiLife->active = false;
		this->currentSkill = NONE_SKILL;
		for (unsigned int i = 0; i < this->bullets.size(); i++) {
			this->bullets[i]->active = false;
		}
		getGame()->resources->iSoundEngine->stopAllSounds();
	}
}
