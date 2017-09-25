
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Flyer::Flyer() {
	// GameObject setting
	this->status->hp = this->hp;
	this->status->damage = 30;
	// scale in real pixel
	this->transform->scale = glm::vec3(32.0f,32.0f,1.0f);
	// Collider (this,offsetX,offsetY,sizeX,sizeY) size is in real pixel && Collider is trigger ?
	this->collHorizonCheck = new BoxCollider(this,0.0f,0.0f,16.0f,16.0f);
	this->collHorizonCheck->trigger = true;
	this->collHorizonCheck->tag = "enemy";
	// Animation (textureName, divideX, divideY, sampleTime)
	this->animFlyer = new Animation("enemy_flyer", 2,1,15);
	// GameObject
	this->orb = new Orb();
	this->orb->active = false;
	this->orb->status->hp = this->score;
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Flyer::~Flyer() {
	// Animation
	delete this->animFlyer;
	// Collider
	delete this->collHorizonCheck;
	// GameObject
	delete this->orb;
}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void Flyer::start() {
	// set sprite texture and slice | Animation start
	this->animFlyer->start();
	this->orb->sprite->setSlice(16.0f,0.0f,16.0f,16.0f);
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void Flyer::update() {
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
	// move
	if (!this->right) {
		this->transform->position.x -= this->speed * getGame()->timer->deltaTime;
	}
	else {
		this->transform->position.x += this->speed * getGame()->timer->deltaTime;
	}

	/* Animation update sprite
	..............................................................................*/
	this->animFlyer->update(this->sprite);
}


/*------------------------------------------------------------------------------
< On Trigger Enter >
------------------------------------------------------------------------------*/
void Flyer::onTriggerEnter(BoxCollider* other) {
	/* Transform if tag = "ground"
	..............................................................................*/
	if (other->tag == "ground" || other->tag == "ai") {
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
< reset >
------------------------------------------------------------------------------*/
void Flyer::reset() {
	this->active = true;
	this->status->hp = this->hp;
	this->right = false;
	this->sprite->flipX = this->right;
	this->air = true;
	this->orb->active = false;
}
