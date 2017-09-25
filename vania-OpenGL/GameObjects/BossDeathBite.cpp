
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
BossDeathBite::BossDeathBite() {
	// GameObject setting
	this->active = false;
	this->transform->position.z = 1.5f;
	this->status->damage = 30.0f;
	// scale in real pixel
	this->transform->scale = glm::vec3(64.0f,64.0f,1.0f);
	// Collider (this,offsetX,offsetY,sizeX,sizeY) size is in real pixel && Collider is trigger ?
	this->collider = new BoxCollider(this,0.0f,0.0f,32.0f,32.0f);
	this->collider->active = false;
	this->collider->tag = "enemy";
	// Animation (textureName, divideX, divideY, sampleTime)
	this->animBite = new Animation("boss_death_bite_bite", 6,1,10);
	this->animAppear = new Animation("boss_death_bite_appear", 4,1,20);
	this->animDisappear = new Animation("boss_death_bite_disappear", 4,1,20);
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
BossDeathBite::~BossDeathBite() {
	// delete objects
	delete this->animBite;
	delete this->animAppear;
	delete this->animDisappear;
	delete this->collider;
}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void BossDeathBite::start() {
	// set sprite texture and slice | Animation start
	this->animBite->start();
	this->animAppear->start();
	this->animDisappear->start();
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void BossDeathBite::update() {
	if (getGame()->timer->currentTime > this->lastAppear + this->lastTime) {
		this->active = false;
	}

	// Animation SetTexture() || Sprite SetTexture()
	if (getGame()->timer->currentTime < this->lastAppear + this->appearTime) {
		this->collider->active = false;
		this->animAppear->update(this->sprite);
	}
	if (getGame()->timer->currentTime >= this->lastAppear + this->appearTime && getGame()->timer->currentTime <= this->lastAppear + (this->lastTime - this->appearTime)) {
		this->collider->active = true;
		this->animBite->update(this->sprite);
	}
	if (getGame()->timer->currentTime > this->lastAppear + (this->lastTime - this->appearTime)) {
		this->collider->active = false;
		this->animDisappear->update(this->sprite);
	}
}


/*------------------------------------------------------------------------------
< onTriggerEnter >
------------------------------------------------------------------------------*/
void BossDeathBite::onTriggerEnter(BoxCollider* other) {

}


/*------------------------------------------------------------------------------
< Functions >
------------------------------------------------------------------------------*/
void BossDeathBite::appear() {
	if (!this->active) {
		this->transform->position.x = this->target->transform->position.x;
		this->transform->position.y = this->target->transform->position.y;
		this->active = true;
		this->animAppear->lastTime = 0;
		this->animAppear->currentSlice = 0;
		this->animDisappear->lastTime = 0;
		this->animDisappear->currentSlice = 0;
		this->lastAppear = getGame()->timer->currentTime;
	}
}
