
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Jumper::Jumper() {
	// GameObject setting
	this->status->hp = this->hp;
	this->status->damage = 30;
	// scale in real pixel
	this->transform->scale = glm::vec3(47.0f,32.0f,1.0f);
	// Collider (this,offsetX,offsetY,sizeX,sizeY) size is in real pixel && Collider is trigger ?
	this->collGroundCheck = new BoxCollider(this,0.0f,0.14f,4.0f,4.0f);
	this->collGroundCheck->trigger = true;
	this->collGroundCheck->tag = "ground_check";
	this->collCeilingCheck = new BoxCollider(this,0.0f,-0.05f,4.0f,4.0f);
	this->collCeilingCheck->trigger = true;
	this->collCeilingCheck->tag = "ceiling_check";
	this->collHorizonCheck = new BoxCollider(this,0.0f,0.05f,28.0f,20.0f);
	this->collHorizonCheck->trigger = true;
	this->collHorizonCheck->tag = "enemy";
	// Animation (divideX, divideY, sampleTime) || Slice (ID,positionX,positionY,sizeX,sizeY) all in real pixel
	this->animIdle = new Animation("enemy_jumper_idle", 4,1,15);
	this->animJump = new Animation("enemy_jumper_jump", 1,1,60);
	// GameObject
	this->orb = new Orb();
	this->orb->active = false;
	this->orb->status->hp = this->score;
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Jumper::~Jumper() {
	// Animation
	delete this->animIdle;
	delete this->animJump;
	// Collider
	delete this->collGroundCheck;
	delete this->collCeilingCheck;
	delete this->collHorizonCheck;
	// GameObject
	delete this->orb;
}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void Jumper::start() {
	this->target = getGame()->player;
	// set sprite texture and slice | Animation start
	this->animIdle->start();
	this->animJump->start();
	this->orb->sprite->setSlice(16.0f,0.0f,16.0f,16.0f);
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void Jumper::update() {
	/* Death
	..............................................................................*/
	if (this->status->hp <= 0) {
		this->active = false;
		getGame()->resources->getAudio("enemy_destroy")->play();
		instantiate(getGame()->publicObjects["enemy_destroy"], this->transform);
		instantiate(this->orb, this->transform);
	}

	/* Transform
	..............................................................................*/
	if (!this->air) {
		if (getGame()->timer->currentTime > this->lastJump + this->jumpColdDown) {
			if (this->target->transform->position.x > this->transform->position.x) {
				this->right = true;
			}
			else {
				this->right = false;
			}
			this->verticalSpeed = this->jumpPower;
			this->air = true;
			this->lastJump = getGame()->timer->currentTime;
		}
	}
	else {
		if (!this->right) {
			this->transform->position.x -= this->speed * getGame()->timer->deltaTime;
		}
		else {
			this->transform->position.x += this->speed * getGame()->timer->deltaTime;
		}
	}

	/* Gravity
	..............................................................................*/
	this->verticalSpeed -= this->gravity * getGame()->timer->deltaTime;
	if (this->verticalSpeed <= - 0.9f * this->jumpPower) {
		this->verticalSpeed = - 0.9f * this->jumpPower;
	}
	this->transform->position.y -= this->verticalSpeed * getGame()->timer->deltaTime;
	if (this->verticalSpeed < -1.0f) {
		this->air = true;
	}


	/* Animation
	..............................................................................*/
	// Animation SetTexture() || Sprite SetTexture()
	if (this->air) {
		this->animJump->update(this->sprite);
	}
	else {
		this->animIdle->update(this->sprite);
	}
}


/*------------------------------------------------------------------------------
< onTriggerEnter >
------------------------------------------------------------------------------*/
void Jumper::onTriggerEnter(BoxCollider* other) {
	/* Transform if tag = "ground"
	..............................................................................*/
	if (other->tag == "ground") {
		if (this->collGroundCheck->enter == true) {
			this->transform->position.y = other->gameObject->transform->position.y + other->offset.y - other->halfSize.y * PIXEL_TO_UNIT - this->collGroundCheck->offset.y - this->collGroundCheck->halfSize.y * PIXEL_TO_UNIT;
			this->air = false;
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
	/* Damage if tag = "bullet"
	..............................................................................*/
	if (other->tag == "bullet") {
		this->sprite->flash(0.5f);
		this->status->hp -= other->gameObject->status->damage;
	}
}


/*------------------------------------------------------------------------------
< reset >
------------------------------------------------------------------------------*/
void Jumper::reset() {
	this->active = true;
	this->status->hp = this->hp;
	this->right = false;
	this->air = true;
	this->verticalSpeed = 0.0f;
	this->lastJump = 0;
	this->orb->active = false;
}
