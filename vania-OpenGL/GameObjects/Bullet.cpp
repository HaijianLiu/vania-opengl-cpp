
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Bullet::Bullet() {
	// GameObject setting
	this->active = false;
	this->transform->position.z = 1.0f;
	// scale in real pixel
	this->transform->scale = glm::vec3(4.0f,4.0f,1.0f);
	// Collider (this,offsetX,offsetY,sizeX,sizeY) size is in real pixel && Collider is trigger ?
	this->collider = new BoxCollider(this,0.0f,0.0f,8.0f,8.0f);
	this->collider->trigger = true;
	this->collider->tag = "bullet";
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Bullet::~Bullet() {
	// delete objects
	delete this->collider;
}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void Bullet::start() {
	// set sprite texture and slice | Animation start
	this->sprite->texture = this->resources->getTexture("player_bullet");
	this->sprite->setSlice(0.0f,0.0f,4.0f,4.0f);
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void Bullet::update() {
	/* Destroy
	..............................................................................*/
	destroy(this, this->lifeTime);

	/* Transform
	..............................................................................*/
	if (this->right) {
		this->transform->position.x += this->speed * this->timer->deltaTime;
	}
	else {
		this->transform->position.x -= this->speed * this->timer->deltaTime;
	}

	/* Particle System
	..............................................................................*/
	// if (DistancePow(this->lastPosition, this->transform->position) >= pow(1.0f / (float)this->resources->fxTail->rate, 2.0f)) {
	// 	this->resources->fxTail->Instantiate(this->transform);
	// 	this->lastPosition = this->transform->position;
	// }
}


/*------------------------------------------------------------------------------
< onTriggerEnter >
------------------------------------------------------------------------------*/
void Bullet::onTriggerEnter(BoxCollider* other) {
	if (other->tag != "player" && other->tag != "ai" && other->tag != "orb" && other->tag != "player_orb" && other->tag != "check_point") {
		this->active = false;
		// this->resources->fxDestroy->Instantiate(this->transform);
	}
}


/*------------------------------------------------------------------------------
< fixedUpdate >
------------------------------------------------------------------------------*/
void Bullet::fixedUpdate() {

}
