
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
BossBullet::BossBullet() {
	// GameObject setting
	this->active = false;
	this->transform->position.z = 2.0f;
	this->status->hp = this->hp;
	this->status->damage = 30.0f;
	// scale in real pixel
	this->transform->scale = glm::vec3(21.0f,21.0f,1.0f);
	// Collider (this,offsetX,offsetY,sizeX,sizeY) size is in real pixel && Collider is trigger ?
	this->collider = new BoxCollider(this,0.0f,0.0f,16.0f,16.0f);
	this->collider->tag = "enemy";
	// Animation (textureName, divideX, divideY, sampleTime)
	this->animation = new Animation("boss_bullet", 7,1,4);
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
BossBullet::~BossBullet() {
	// delete objects
	delete this->collider;
	delete this->animation;
}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void BossBullet::start() {
	this->target = getGame()->player;
	// set sprite texture and slice | Animation start
	this->animation->start();
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void BossBullet::update() {
	/* Death
	..............................................................................*/
	if (this->status->hp <= 0) {
		this->active = false;
		getGame()->resources->getAudio("enemy_destroy")->play();
		instantiate(getGame()->publicObjects["enemy_destroy"], this->transform);
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


	// Animation SetTexture() || Sprite SetTexture()
	this->animation->update(this->sprite);
}


/*------------------------------------------------------------------------------
< onTriggerEnter >
------------------------------------------------------------------------------*/
void BossBullet::onTriggerEnter(BoxCollider* other) {
	/* Damage if tag = "bullet"
	..............................................................................*/
	if (other->tag == "bullet") {
		this->sprite->flash(0.5f);
		this->status->hp -= other->gameObject->status->damage;
	}
	/* dead if tag = "player"
	..............................................................................*/
	if (other->tag == "player") {
		this->active = false;
		getGame()->resources->getAudio("enemy_destroy")->play();
		instantiate(getGame()->publicObjects["enemy_destroy"], this->transform);
	}
}


/*------------------------------------------------------------------------------
< reset >
------------------------------------------------------------------------------*/
void BossBullet::reset() {
	// this->active = true;
	// this->status->hp = this->hp;
	// this->orb->active = false;
}
