
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Player::Player() {
	// GameObject setting
	this->active = false;
	this->status->hp = this->hp;
	this->transform->position.z = 2.0f;
	// Input
  this->input = Input::getInstance();
	// scale in real pixel
	this->transform->scale = glm::vec3(80.0f,80.0f,1.0f);

	// Collider (this,offsetX,offsetY,sizeX,sizeY) size is in real pixel && Collider is trigger ?
	this->collGroundCheck = new BoxCollider(this,0.0f,0.21f,8.0f,4.0f);
	this->collGroundCheck->trigger = true;
	this->collGroundCheck->tag = "ground_check";
	this->collCeilingCheck = new BoxCollider(this,0.0f,-0.05f,4.0f,4.0f);
	this->collCeilingCheck->trigger = true;
	this->collCeilingCheck->tag = "ceiling_check";
	this->collHorizonCheck = new BoxCollider(this,0.0f,0.08f,24.0f,28.0f);
	this->collHorizonCheck->trigger = true;
	this->collHorizonCheck->tag = "player";
	// Animation (textureName, divideX, divideY, sampleTime)
	this->animIdle = new Animation("player_idle", 3,1,15);
	this->animShoot = new Animation("player_shoot", 3,1,4);
	this->animRun = new Animation("player_run_shoot", 10,1,4);
	this->animJump = new Animation("player_jump", 6,1,4);
	this->animDuck = new Animation("player_duck", 1,1,60);
	this->animDuckShoot = new Animation("player_duck_shoot", 3,1,4);
	this->animHurt = new Animation("player_hurt", 1,1,60);
	// OffsetObject
	this->leftShoot = new OffsetObject(this,-0.2f,-0.015f);
	this->rightShoot = new OffsetObject(this,0.2f,-0.015f);
	this->leftDuckShoot = new OffsetObject(this,-0.2f,0.1f);
	this->rightDuckShoot = new OffsetObject(this,0.2f,0.1f);
	// Bullet
	for (int i = 0; i < 16; i++) {
		this->bullets.push_back(new Bullet());
		this->bullets.back()->status->damage = this->bulletDamage;
	}
	// UIObject
	this->uiEnergy = new UIObject(-200.0f + 6.5f + 49.5f, -120.0f + 19.5f,100.0f,1.0f);
	this->uiEnergy->transform->position.z += 1.0f;
	this->uiEnergyBG = new UIObject(-144.0f,-104.0f,112.0f,32.0f);
	this->score = new Score();
	// Orb
	this->orb = new Orb();
	this->orb->collider->tag = "my_orb";
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Player::~Player() {
	// BoxCollider
	delete this->collGroundCheck;
	delete this->collCeilingCheck;
	delete this->collHorizonCheck;
	// Animation
	delete this->animIdle;
	delete this->animShoot;
	delete this->animRun;
	delete this->animJump;
	delete this->animDuck;
	delete this->animDuckShoot;
	delete this->animHurt;
	// OffsetObject
	delete this->leftShoot;
	delete this->rightShoot;
	delete this->leftDuckShoot;
	delete this->rightDuckShoot;
	// Bullet
	deleteVector(this->bullets);
	// UIObject
	delete this->uiEnergy;
	delete this->uiEnergyBG;
	delete this->score;
	// Orb
	delete this->orb;
}


/*------------------------------------------------------------------------------
< Start >
------------------------------------------------------------------------------*/
void Player::start() {
	// set sprite texture and slice | Animation start
	this->animIdle->start();
	this->animShoot->start();
	this->animRun->start();
	this->animJump->start();
	this->animDuck->start();
	this->animDuckShoot->start();
	this->animHurt->start();
	this->uiEnergyBG->sprite->texture = this->resources->getTexture("ui_player_energy");
	this->orb->sprite->setSlice(48.0f,0.0f,16.0f,16.0f);
}


/*------------------------------------------------------------------------------
< Update > before gameObject draw()
------------------------------------------------------------------------------*/
void Player::update() {
	/* HP
	..............................................................................*/
	if (!this->freeze) {
		this->status->hp += this->energyRegain * this->timer->deltaTime;
	}
	else {
		if (this->timer->currentTime > this->lastFreeze + this->freezeColdDown) {
			this->freeze = false;
		}
	}
	if (this->status->hp < 0) this->status->hp = 0;
	if (this->status->hp > this->hp) this->status->hp = this->hp;

	/* UIObject
	..............................................................................*/
  this->uiEnergy->offset = glm::vec2(-200.0f + 6.0f + 0.5f * this->status->hp,  -120.0f + 20.0f);
  this->uiEnergy->transform->scale = glm::vec3(this->status->hp * 1.0f, 2.0f, 1.0f);
	if (!this->freeze) {
		if (this->status->hp > 0.6f * this->hp) {
			this->uiEnergy->sprite->setColor(0,255,255,255);
		}
		else if (this->status->hp > 0.2f * this->hp) {
			this->uiEnergy->sprite->setColor(255,192,0,255);
		}
		else {
			this->uiEnergy->sprite->setColor(255,79,108,255);
		}
	}
	else {
		this->uiEnergy->sprite->setColor(100,100,100,255);
	}

	/* Transform
	..............................................................................*/
	if (!this->hurt) {
		// move
		if (this->input->getButtonPress(GLFW_KEY_LEFT) || this->input->getButtonPress(GLFW_KEY_A)) {
			this->move = true;
			this->right = false;
			this->sprite->flipX = !this->right;
			this->transform->position.x -= this->speed * this->timer->deltaTime;
		}
		else if (this->input->getButtonPress(GLFW_KEY_RIGHT) || this->input->getButtonPress(GLFW_KEY_D)) {
			this->move = true;
			this->right = true;
			this->sprite->flipX = !this->right;
			this->transform->position.x += this->speed * this->timer->deltaTime;
		}
		else {
			this->move = false;
		}
		// jump
		if (this->input->getButtonPress(GLFW_KEY_SPACE) || this->input->getButtonPress(GLFW_KEY_J)) {
			if (!this->air) {
				this->verticalSpeed = this->jumpPower;
				this->air = true;
			}
		}
		// duck
		if (this->input->getButtonPress(GLFW_KEY_DOWN) || this->input->getButtonPress(GLFW_KEY_S)) {
			if (!this->air) {
				this->duck = true;
			}
		}
		else {
			this->duck = false;
		}
	}
	else {
		if (this->right) {
			this->transform->position.x -= this->backSpeed * this->timer->deltaTime;
		}
		else {
			this->transform->position.x += this->backSpeed * this->timer->deltaTime;
		}
	}

	/* Death
	..............................................................................*/
	if (this->status->hp <= 0 && !this->hurt && this->visible) {
		this->visible = false;
//		this->resources->audPlayerDestroy->Play();
		instantiate(getGame()->publicObjects["player_destroy"], this->transform);
	}

	/* GameOver
	..............................................................................*/
	if (this->status->hp <= 0 && this->timer->currentTime > this->lastHurt + this->gameOverDelay) {
		this->active = false;
		this->uiEnergy->active = false;
		this->uiEnergyBG->active = false;
		getGame()->sceneManager->setActiveScene("SceneGameOver");
		this->lastGameOver = this->timer->currentTime;
		// Score
		for (unsigned int i = 0; i < this->score->numbers.size(); i++) {
			this->score->numbers[i]->active = false;
			this->score->numbers[i]->sprite->setSlice(0,0,this->score->size.x,this->score->size.y);
		}
		this->score->numbers[0]->active = true;

		this->orb->status->hp = this->score->score;
		this->score->score = 0;
		this->score->willAddScore = 0;
		instantiate(this->orb, this->transform);
	}

	/* Gravity
	..............................................................................*/
	this->verticalSpeed -= this->gravity * this->timer->deltaTime;
	if (this->verticalSpeed <= - 0.8f * this->jumpPower) {
		this->verticalSpeed = - 0.8f * this->jumpPower;
	}
	this->transform->position.y -= this->verticalSpeed * this->timer->deltaTime;
	if (this->verticalSpeed < -1.0f) {
		this->air = true;
	}


	/* Fire
	..............................................................................*/
	if (!this->hurt) {
		if (this->input->getButtonPress(GLFW_KEY_F) || this->input->getButtonPress(GLFW_KEY_K)) {
			if (this->timer->currentTime > this->lastShoot + this->shootColdDown) {
				if (this->status->hp > this->shootEnergy) {
					this->shoot = true;
					this->status->hp -= this->shootEnergy;
//					for (unsigned int i = 0; i < this->resources->audShoot.size(); i++) {
//						if (!this->resources->audShoot[i]->Playing()) {
//							this->resources->audShoot[i]->Play();
//							break;
//						}
//					}
					for (unsigned int i = 0; i < this->bullets.size(); i++) {
						if (!this->bullets[i]->active) {
							this->lastShoot = this->timer->currentTime;
							this->bullets[i]->status->birthTime = this->timer->currentTime;
							this->bullets[i]->right = this->right;
							this->bullets[i]->active = true;
							if (this->right) {
								if (this->duck && !this->move && !this->air) {
									this->bullets[i]->transform->position = this->rightDuckShoot->transform->position;
								}
								else {
									this->bullets[i]->transform->position = this->rightShoot->transform->position;
								}
							}
							else {
								if (this->duck && !this->move && !this->air) {
									this->bullets[i]->transform->position = this->leftDuckShoot->transform->position;
								}
								else {
									this->bullets[i]->transform->position = this->leftShoot->transform->position;
								}
							}
							break;
						}
					}
				}
				else {
//					this->resources->audPlayerNoAmmo->Play();
				}
			}
		}
	}


	/* flag
	..............................................................................*/

	// Shoot Flag
	if (this->timer->currentTime > this->lastShoot + this->shootDuration) {
		this->shoot = false;
	}

	// Hurt Flag
	if (this->status->hp > 0) {
		if (this->timer->currentTime > this->lastHurt + this->hurtFreeze) {
			this->hurt = false;
		}
	}
	else {
		if (this->timer->currentTime > this->lastHurt + this->deathDelay) {
			this->hurt = false;
		}
	}


	/* Animation update sprite
	..............................................................................*/
	if (!this->hurt) {
		if (this->air) {
			this->animJump->update(this->sprite);
		}
		else {
			if (this->move) {
				this->animRun->update(this->sprite);
			}
			if (!this->move) {
				if (this->duck) {
					if (this->shoot) {
						this->animDuckShoot->update(this->sprite);
					}
					else {
						this->animDuck->update(this->sprite);
					}
				}
				else {
					if (this->shoot) {
						this->animShoot->update(this->sprite);
					}
					else{
						this->animIdle->update(this->sprite);
					}
				}
			}
		}
	}
	else {
		this->animHurt->update(this->sprite);
	}
}


/*------------------------------------------------------------------------------
< On Trigger Enter >
------------------------------------------------------------------------------*/
void Player::onTriggerEnter(BoxCollider* other) {
	/* Transform if tag = "ground"
	..............................................................................*/
	if (other->tag == "ground" || other->tag == "death_wall") {
		if (this->collGroundCheck->enter == true) {
			this->transform->position.y = other->gameObject->transform->position.y + other->offset.y - other->halfSize.y * PIXEL_TO_UNIT - this->collGroundCheck->offset.y - this->collGroundCheck->halfSize.y * PIXEL_TO_UNIT;
			this->air = false;
			if (this->verticalSpeed <= -0.2f * this->jumpPower) {
				// this->resources->audLanding->Play();
			}
			this->verticalSpeed = 0.0f;
		}
		if (this->collHorizonCheck->enter == true) {
			if (this->transform->position.x > other->gameObject->transform->position.x) {
				this->transform->position.x = other->gameObject->transform->position.x + other->offset.x + other->halfSize.x * PIXEL_TO_UNIT - this->collHorizonCheck->offset.x + this->collHorizonCheck->halfSize.x * PIXEL_TO_UNIT;
			}
			if (this->transform->position.x < other->gameObject->transform->position.x) {
				this->transform->position.x = other->gameObject->transform->position.x + other->offset.x - other->halfSize.x * PIXEL_TO_UNIT - this->collHorizonCheck->offset.x - this->collHorizonCheck->halfSize.x * PIXEL_TO_UNIT;
			}
		}
		if (this->collCeilingCheck->enter == true) {
			this->transform->position.y = other->gameObject->transform->position.y + other->offset.y + other->halfSize.y * PIXEL_TO_UNIT - this->collCeilingCheck->offset.y + this->collCeilingCheck->halfSize.y * PIXEL_TO_UNIT;
			this->verticalSpeed = 0.0f;
		}
	}
	/* Shield if tag = "enemy"
	..............................................................................*/
	if (other->tag == "enemy" || other->tag == "death_wall" || other->tag == "ball_enemy") {
		if (this->status->hp > 0 && this->timer->currentTime > this->lastHurt + this->hurtColdDown) {
			this->hurt = true;
			this->lastHurt = this->timer->currentTime;
			this->freeze = true;
			this->lastFreeze = this->timer->currentTime;
			this->status->hp -= other->gameObject->status->damage;
			if (this->status->hp <= 0) {
				// this->resources->audPlayerDeath->Play();
			}
			else {
				// this->resources->audPlayerHurt->Play();
			}
			if (other->gameObject->transform->position.x > this->transform->position.x) {
				this->right = true;
			}
			else {
				this->right = false;
			}
			this->verticalSpeed = 0.5f * this->jumpPower;
			this->sprite->flash(this->hurtColdDown);
		}
	}

	/* add score if tag = "orb"
	..............................................................................*/
	if (other->tag == "orb") {
		this->score->willAdd((unsigned int)other->gameObject->status->hp);
	}
	if (other->tag == "my_orb") {
		this->score->willAdd((unsigned int)other->gameObject->status->hp);
		// this->resources->audOrbReturn->Play();
	}
	/*  if tag = "item"
	..............................................................................*/
	if (other->tag == "item") {
		if (other->gameObject->status->tag == "dark") {
			this->energyRegain += 5.0f;
			this->hurtColdDown += 0.5f;
		}
		if (other->gameObject->status->tag == "gold") {
			this->energyRegain += 10.0f;
		}
		if (other->gameObject->status->tag == "sliver") {
			this->shootColdDown = 0.05f;
		}
		if (other->gameObject->status->tag == "bronze") {
			this->hurtColdDown += 1.0f;
		}
	}
}


/*------------------------------------------------------------------------------
< fixedUpdate >
------------------------------------------------------------------------------*/
void Player::fixedUpdate() {

}


/*------------------------------------------------------------------------------
< reset >
------------------------------------------------------------------------------*/
void Player::reset() {
	this->status->hp = this->hp;
	this->active = true;
	this->visible = true;
	this->uiEnergy->active = true;
	this->uiEnergyBG->active = true;
	this->score->active = true;
}
