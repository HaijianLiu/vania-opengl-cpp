
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
BossDeathWall::BossDeathWall() {
	// Set GameObject
	this->active = false;
	this->transform->position.z = 1.0f;
	this->status->damage = 30.0f;
	// scale in real pixel
	this->transform->scale = glm::vec3(32.0f,32.0f,1.0f);
	// Collider (this,offsetX,offsetY,sizeX,sizeY) size is in real pixel && Collider is trigger ?
	this->collider = new BoxCollider(this,0.0f,0.0f,32.0f,32.0f);
	this->collider->tag = "death_wall";
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
BossDeathWall::~BossDeathWall() {
	// delete objects
	delete this->collider;
}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void BossDeathWall::start() {
	if (!this->right) {
		this->sprite->flipX = true;
	}
	// set sprite texture and slice | Animation start
	this->sprite->texture = getGame()->resources->getTexture("boss_death_wall");
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void BossDeathWall::update() {
	if (this->right) {
		this->transform->position.x += this->speed * getGame()->timer->deltaTime;
		if (this->transform->position.x > this->startPosition.x) {
			this->transform->position.x = this->startPosition.x;
			this->active = false;
		}
	}
	else {
		this->transform->position.x -= this->speed * getGame()->timer->deltaTime;
		if (this->transform->position.x < this->startPosition.x) {
			this->transform->position.x = this->startPosition.x;
			this->active = false;
		}
	}
}


/*------------------------------------------------------------------------------
< onTriggerEnter >
------------------------------------------------------------------------------*/
void BossDeathWall::onTriggerEnter(BoxCollider* other) {

}


/*------------------------------------------------------------------------------
< Functions >
------------------------------------------------------------------------------*/
void BossDeathWall::forward() {
	if (this->right) {
		this->active = true;
		this->transform->position.x -= 3.0f * this->speed * getGame()->timer->deltaTime;
		if (this->startPosition.x - this->transform->position.x > this->maxDistance) {
			this->transform->position.x = this->startPosition.x - this->maxDistance;
		}
	}
	else {
		this->active = true;
		this->transform->position.x += 3.0f * this->speed * getGame()->timer->deltaTime;
		if (this->transform->position.x - this->startPosition.x > this->maxDistance) {
			this->transform->position.x = this->startPosition.x + this->maxDistance;
		}
	}
}

void BossDeathWall::deathArea(bool right) {
	if (right) {
		this->active = true;
		this->transform->position.x -= 3.0f * this->speed * getGame()->timer->deltaTime;
		if (this->startPosition.x - this->transform->position.x > this->maxArea) {
			this->transform->position.x = this->startPosition.x - this->maxArea;
		}
	}
	else {
		this->active = true;
		this->transform->position.x += 3.0f * this->speed * getGame()->timer->deltaTime;
		if (this->transform->position.x - this->startPosition.x > this->maxArea) {
			this->transform->position.x = this->startPosition.x + this->maxArea;
		}
	}
}
