
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Ball::Ball() {
	// GameObject setting
	this->status->hp = this->hp;
	this->status->damage = 30;
	// scale in real pixel
	this->transform->scale = glm::vec3(16.0f,16.0f,1.0f);
	// Collider (this,offsetX,offsetY,sizeX,sizeY) size is in real pixel && Collider is trigger ?
	this->collGroundCheck = new BoxCollider(this,0.0f,0.07f,4.0f,4.0f);
	this->collGroundCheck->trigger = true;
	this->collGroundCheck->tag = "ball_ground_check";
	this->collCeilingCheck = new BoxCollider(this,0.0f,-0.07f,4.0f,4.0f);
	this->collCeilingCheck->trigger = true;
	this->collCeilingCheck->tag = "ball_ceiling_check";
	this->collHorizonCheck = new BoxCollider(this,0.0f,0.0f,16.0f,16.0f);
	this->collHorizonCheck->trigger = true;
	this->collHorizonCheck->tag = "ball_enemy";
	// GameObject
	this->orb = new Orb();
	this->orb->active = false;
	this->orb->status->hp = this->score;
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Ball::~Ball() {
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
void Ball::start() {
	// set sprite texture and slice | Animation start
	this->sprite->texture = getGame()->resources->getTexture("enemy_ball");
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void Ball::update() {
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
	if (this->right) {
		this->transform->position.x += this->horizonSpeed * getGame()->timer->deltaTime;
	}
	else {
		this->transform->position.x -= this->horizonSpeed * getGame()->timer->deltaTime;
	}

	if (this->up) {
		this->transform->position.y -= this->verticalSpeed * getGame()->timer->deltaTime;
	}
	else {
		this->transform->position.y += this->verticalSpeed * getGame()->timer->deltaTime;
	}
}


/*------------------------------------------------------------------------------
< onTriggerEnter >
------------------------------------------------------------------------------*/
void Ball::onTriggerEnter(BoxCollider* other) {
	/* Transform if tag = "ground"
	..............................................................................*/
	if (other->tag == "ground" || other->tag == "ai") {
		getGame()->resources->getAudio("enemy_ball_bounce")->play();
		if (this->collGroundCheck->enter == true) {
			this->transform->position.y = other->gameObject->transform->position.y + other->offset.y - other->halfSize.y * PIXEL_TO_UNIT - this->collGroundCheck->offset.y - this->collGroundCheck->halfSize.y * PIXEL_TO_UNIT;
			this->up = true;
		}
		if (this->collHorizonCheck->enter == true) {
			if (this->transform->position.x > other->gameObject->transform->position.x) {
				this->transform->position.x = other->gameObject->transform->position.x + other->offset.x + other->halfSize.x * PIXEL_TO_UNIT - this->collHorizonCheck->offset.x + this->collHorizonCheck->halfSize.x * PIXEL_TO_UNIT;
				this->right = true;
			}
			if (this->transform->position.x < other->gameObject->transform->position.x) {
				this->transform->position.x = other->gameObject->transform->position.x + other->offset.x - other->halfSize.x * PIXEL_TO_UNIT - this->collHorizonCheck->offset.x - this->collHorizonCheck->halfSize.x * PIXEL_TO_UNIT;
				this->right = false;
			}
		}
		if (this->collCeilingCheck->enter == true) {
			this->transform->position.y = other->gameObject->transform->position.y + other->offset.y + other->halfSize.y * PIXEL_TO_UNIT - this->collCeilingCheck->offset.y + this->collCeilingCheck->halfSize.y * PIXEL_TO_UNIT;
			this->up = false;
		}
	}

	/* Damage if tag = "bullet"
	..............................................................................*/
	if (other->tag == "bullet") {
		this->right = !this->right;
		this->up = !this->up;
		this->sprite->flash(0.5f);
		this->status->hp -= other->gameObject->status->damage;
	}
}


/*------------------------------------------------------------------------------
< reset >
------------------------------------------------------------------------------*/
void Ball::reset() {
	this->active = true;
	this->status->hp = this->hp;
	this->up = false;
	this->right = false;
	this->orb->active = false;
}
