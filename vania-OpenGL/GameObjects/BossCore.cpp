
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
BossCore::BossCore() {
	// GameObject setting
	this->transform->position.z = 1.0f;
	// scale in real pixel
	this->transform->scale = glm::vec3(32.0f,32.0f,1.0f);
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
BossCore::~BossCore() {

}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void BossCore::start() {
	// set sprite texture and slice | Animation start
	this->sprite->texture = getGame()->resources->getTexture("boss_eye");
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void BossCore::update() {

}


/*------------------------------------------------------------------------------
< onTriggerEnter >
------------------------------------------------------------------------------*/
void BossCore::onTriggerEnter(BoxCollider* other) {

}


/*------------------------------------------------------------------------------
< Functions >
------------------------------------------------------------------------------*/
void BossCore::followTarget() {

	float angle = atan((this->target->transform->position.y - this->parent->transform->position.y) / (this->target->transform->position.x - this->parent->transform->position.x));

	if (this->target->transform->position.x < this->parent->transform->position.x) {
		this->transform->position.x -= cos(angle) * this->speed * getGame()->timer->deltaTime;
		this->transform->position.y -= sin(angle) * this->speed * getGame()->timer->deltaTime;
		if (this->transform->position.x < this->parent->transform->position.x - cos(angle) * this->radius) {
			this->transform->position.x = this->parent->transform->position.x - cos(angle) * this->radius;
		}
		if ( (this->transform->position.y <= this->parent->transform->position.y - sin(angle) * this->radius && sin(angle) >= 0) || (this->transform->position.y > this->parent->transform->position.y - sin(angle) * this->radius && sin(angle) < 0) ){
			this->transform->position.y = this->parent->transform->position.y - sin(angle) * this->radius;
		}
	}
	else {
		this->transform->position.x += cos(angle) * this->speed * getGame()->timer->deltaTime;
		this->transform->position.y += sin(angle) * this->speed * getGame()->timer->deltaTime;
		if (this->transform->position.x > this->parent->transform->position.x + cos(angle) * this->radius) {
			this->transform->position.x = this->parent->transform->position.x + cos(angle) * this->radius;
		}
		if ( (this->transform->position.y >= this->parent->transform->position.y + sin(angle) * this->radius && sin(angle) >= 0) || (this->transform->position.y < this->parent->transform->position.y + sin(angle) * this->radius && sin(angle) < 0) ){
			this->transform->position.y = this->parent->transform->position.y + sin(angle) * this->radius;
		}
	}
	// if (this->target->transform->position.x < this->parent->transform->position.x) {
	// 	this->transform->position.x = this->parent->transform->position.x - cos(angle) * this->radius;
	// 	this->transform->position.y = this->parent->transform->position.y - sin(angle) * this->radius;
	// }
	// else {
	// 	this->transform->position.x = this->parent->transform->position.x + cos(angle) * this->radius;
	// 	this->transform->position.y = this->parent->transform->position.y + sin(angle) * this->radius;
	// }
}


/*------------------------------------------------------------------------------
< reset >
------------------------------------------------------------------------------*/
void BossCore::reset() {
	// this->active = true;
	// this->status->hp = this->hp;
	// this->orb->active = false;
}
