
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Block::Block() {
	// GameObject setting
	this->status->hp = this->hp;
	this->transform->position.z = 1.0f;
	// scale in real pixel
	this->transform->scale = glm::vec3(16.0f,16.0f,1.0f);
	// Collider (this,offsetX,offsetY,sizeX,sizeY) size is in real pixel && Collider is trigger ?
	this->collider = new BoxCollider(this,0.0f,0.0f,16.0f,16.0f);
	this->collider->tag = "ground";
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Block::~Block() {
	delete this->collider;
}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void Block::start() {
	// set sprite texture and slice | Animation start
	this->sprite->texture = this->resources->getTexture("map_block");
	this->sprite->setSlice(0.0f,0.0f,16.0f,16.0f);
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void Block::update() {
	if (this->status->hp >= 70) {
		this->sprite->setSlice(0.0f,0.0f,16.0f,16.0f);
	}
	else if (this->status->hp < 70 && this->status->hp >= 40) {
		this->sprite->setSlice(16.0f,0.0f,16.0f,16.0f);
	}
	else if (this->status->hp < 40 && this->status->hp > 0) {
		this->sprite->setSlice(32.0f,0.0f,16.0f,16.0f);
	}
	else if (this->status->hp <= 0) {
		this->active = false;
	}
}


/*------------------------------------------------------------------------------
< onTriggerEnter >
------------------------------------------------------------------------------*/
void Block::onTriggerEnter(BoxCollider* other) {
	if (other->tag == "bullet") {
		this->status->hp -= other->gameObject->status->damage;
	}
	if (other->tag == "ball_ceiling_check" || other->tag == "ball_ground_check" || other->tag == "ball_enemy") {
		this->status->hp -= 50.0f;
	}
	if (other->tag == "ground_check") {
		this->status->hp -= this->destroySpeed * this->timer->deltaTime;
	}
}


/*------------------------------------------------------------------------------
< fixedUpdate >
------------------------------------------------------------------------------*/
void Block::fixedUpdate() {

}
