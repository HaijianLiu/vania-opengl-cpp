
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Orb::Orb() {
	// GameObject setting
	this->active = false;
	this->status->hp = 150;
	// scale in real pixel
	this->transform->scale = glm::vec3(16.0f,16.0f,1.0f);
	// Collider (this,offsetX,offsetY,sizeX,sizeY) size is in real pixel && Collider is trigger ?
	this->collider = new BoxCollider(this,0.0f,0.0f,16.0f,16.0f);
	this->collider->tag = "orb";
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Orb::~Orb() {
	delete this->collider;
}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void Orb::start() {
	// set sprite texture and slice | Animation start
	this->sprite->texture = this->resources->getTexture("item_orb");
	this->sprite->setSlice(16.0f,0.0f,16.0f,16.0f);
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void Orb::update() {
	this->transform->position.y += 0.002f * sin(this->timer->currentTime/300.0f);
	getGame()->particleSystems["fx_orb"]->instantiate(this->transform);
}


/*------------------------------------------------------------------------------
< onTriggerEnter >
------------------------------------------------------------------------------*/
void Orb::onTriggerEnter(BoxCollider* other) {
	if (other->tag == "player") {
		this->active = false;
		// this->resources->audOrbGet->Play();
	}
}


/*------------------------------------------------------------------------------
< Fixed Update >
------------------------------------------------------------------------------*/
void Orb::fixedUpdate() {

}
