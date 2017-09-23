
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Crab::Crab() {
	// GameObject setting
	this->status->hp = this->hp;
	this->status->damage = 30;
	// scale in real pixel
	this->transform->scale = glm::vec3(48.0f,32.0f,1.0f);
	// Collider (this,offsetX,offsetY,sizeX,sizeY) size is in real pixel && Collider is trigger ?
	this->collGroundCheck = new BoxCollider(this,0.0f,0.14f,4.0f,4.0f);
	this->collGroundCheck->trigger = true;
	this->collGroundCheck->tag = "ground_check";
	this->collHorizonCheck = new BoxCollider(this,0.0f,0.03f,24.0f,24.0f);
	this->collHorizonCheck->trigger = true;
	this->collHorizonCheck->tag = "enemy";
	// Animation (textureName, divideX, divideY, sampleTime)
	this->animWalk = new Animation("enemy_crab_walk", 4,1,15);
	// GameObject
	this->orb = new Orb();
	this->orb->active = false;
	this->orb->status->hp = this->score;
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Crab::~Crab() {
	// Animation
	delete this->animWalk;
	// Collider
	delete this->collGroundCheck;
	delete this->collHorizonCheck;
	// GameObject
	delete this->orb;
}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void Crab::start() {
	// set sprite texture and slice | Animation start
	this->animWalk->start();
	this->orb->sprite->setSlice(16.0f,0.0f,16.0f,16.0f);
}


/*------------------------------------------------------------------------------
< Update >
------------------------------------------------------------------------------*/
void Crab::update() {
	/* Death
	..............................................................................*/
	if (this->status->hp <= 0) {
		this->active = false;
		// this->resources->audEnemyDestroy->Play();
		instantiate(getGame()->publicObjects["enemy_destroy"], this->transform);
		instantiate(this->orb, this->transform);
	}

	/* Transform
	..............................................................................*/
	// move
	if (!this->right) {
		this->transform->position.x -= this->speed * this->timer->deltaTime;
	}
	else {
		this->transform->position.x += this->speed * this->timer->deltaTime;
	}

	/* Gravity
	..............................................................................*/
	this->verticalSpeed -= this->gravity * this->timer->deltaTime;
	if (this->verticalSpeed <= - 0.9f * this->jumpPower) {
		this->verticalSpeed = - 0.9f * this->jumpPower;
	}
	this->transform->position.y -= this->verticalSpeed * this->timer->deltaTime;
	if (this->verticalSpeed < -1.0f) {
		this->air = true;
	}

	/* Animation update sprite
	..............................................................................*/
	this->animWalk->update(this->sprite);
}


/*------------------------------------------------------------------------------
< onTriggerEnter >
------------------------------------------------------------------------------*/
void Crab::onTriggerEnter(BoxCollider* other) {
	/* Transform if tag = "ground"
	..............................................................................*/
	if (other->tag == "ground" || other->tag == "ai") {
		if (this->collGroundCheck->enter == true) {
			this->transform->position.y = other->gameObject->transform->position.y + other->offset.y - other->halfSize.y * PIXEL_TO_UNIT - this->collGroundCheck->offset.y - this->collGroundCheck->halfSize.y * PIXEL_TO_UNIT;
			this->air = false;
			this->verticalSpeed = 0.0f;
		}
		if (this->collHorizonCheck->enter == true) {
			if (this->transform->position.x > other->gameObject->transform->position.x) {
				this->transform->position.x = other->gameObject->transform->position.x + other->offset.x + other->halfSize.x * PIXEL_TO_UNIT - this->collHorizonCheck->offset.x + this->collHorizonCheck->halfSize.x * PIXEL_TO_UNIT;
				this->right = true;
				this->sprite->flipX = this->right;
			}
			if (this->transform->position.x < other->gameObject->transform->position.x) {
				this->transform->position.x = other->gameObject->transform->position.x + other->offset.x - other->halfSize.x * PIXEL_TO_UNIT - this->collHorizonCheck->offset.x - this->collHorizonCheck->halfSize.x * PIXEL_TO_UNIT;
				this->right = false;
				this->sprite->flipX = this->right;
			}
		}
	}
	/* Damage if tag = "bullet"
	..............................................................................*/
	if (other->tag == "bullet") {
		this->sprite->flash(0.5f);
		this->status->hp -= other->gameObject->status->damage;
	}
}


/*------------------------------------------------------------------------------
< fixedUpdate >
------------------------------------------------------------------------------*/
void Crab::fixedUpdate() {

}
