
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Ghost::Ghost() {
	// GameObject setting
	this->active = false;
	this->transform->position.z = 2.0f;
	this->status->hp = this->hp;
	this->status->damage = 30.0f;
	// scale in real pixel
	this->transform->scale = glm::vec3(28.0f,37.0f,1.0f);
	// Collider (this,offsetX,offsetY,sizeX,sizeY) size is in real pixel && Collider is trigger ?
	this->collider = new BoxCollider(this,0.0f,0.0f,24.0f,24.0f);
	this->collider->tag = "enemy";
	// Animation (textureName, divideX, divideY, sampleTime)
	this->animation = new Animation("enemy_ghost", 4,1,15);
	// GameObject
	this->orb = new Orb();
	this->orb->active = false;
	this->orb->status->hp = this->score;
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Ghost::~Ghost() {
	// delete objects
	delete this->collider;
	delete this->animation;
	// GameObject
	delete this->orb;
}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void Ghost::start() {
	this->target = getGame()->player;
	// set sprite texture and slice | Animation start
	this->animation->start();
	this->orb->sprite->setSlice(16.0f,0.0f,16.0f,16.0f);
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void Ghost::update() {
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
	float angle = atan((this->target->transform->position.y - this->transform->position.y) / (this->target->transform->position.x - this->transform->position.x));

	if (this->target->transform->position.x < this->transform->position.x) {
		this->transform->position.x -= cos(angle) * this->speed * getGame()->timer->deltaTime;
		this->transform->position.y -= sin(angle) * this->speed * getGame()->timer->deltaTime;
	}
	else {
		this->transform->position.x += cos(angle) * this->speed * getGame()->timer->deltaTime;
		this->transform->position.y += sin(angle) * this->speed * getGame()->timer->deltaTime;
	}


	/* Animation update sprite
	..............................................................................*/
	this->animation->update(this->sprite);
}


/*------------------------------------------------------------------------------
< onTriggerEnter >
------------------------------------------------------------------------------*/
void Ghost::onTriggerEnter(BoxCollider* other) {
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
void Ghost::reset() {
	this->active = true;
	this->status->hp = this->hp;
	this->orb->active = false;
}
