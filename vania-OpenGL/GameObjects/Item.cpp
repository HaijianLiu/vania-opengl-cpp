
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Item::Item() {
	// GameObject setting
	this->transform->position.z = 1.0f;
	// scale in real pixel
	this->transform->scale = glm::vec3(16.0f,16.0f,1.0f);
	// Collider (this,offsetX,offsetY,sizeX,sizeY) size is in real pixel && Collider is trigger ?
	this->collider = new BoxCollider(this,0.0f,0.0f,16.0f,16.0f);
	this->collider->tag = "item";
	// UIObject
	this->info = new UIObject(0.0f, 0.0f, 256.0f, 128.0f);
	this->info->active = false;
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Item::~Item() {
	delete this->collider;
	delete this->info;
}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void Item::start() {
	// set sprite texture and slice | Animation start
	this->sprite->texture = getGame()->resources->getTexture("item_icon");
	if (this->status->tag == "dark") {
		this->sprite->setSlice(0,0,16,16);
	}
	if (this->status->tag == "gold") {
		this->sprite->setSlice(32,0,16,16);
	}
	if (this->status->tag == "sliver") {
		this->sprite->setSlice(48,0,16,16);
	}
	if (this->status->tag == "bronze") {
		this->sprite->setSlice(16,0,16,16);
	}
}


/*------------------------------------------------------------------------------
< Update >
------------------------------------------------------------------------------*/
void Item::update() {
	if (this->status->tag == "dark") {
		getGame()->particleSystems["fx_item"]->setColor(245,103,227,255);
	}
	if (this->status->tag == "gold") {
		getGame()->particleSystems["fx_item"]->setColor(252,226,82,255);
	}
	if (this->status->tag == "sliver") {
		getGame()->particleSystems["fx_item"]->setColor(251,112,240,255);
	}
	if (this->status->tag == "bronze") {
		getGame()->particleSystems["fx_item"]->setColor(195,241,136,255);
	}

	this->transform->position.y += 0.002f * sin(getGame()->timer->currentTime * 2.0f);
	getGame()->particleSystems["fx_item"]->instantiate(this->transform);
}


/*------------------------------------------------------------------------------
< onTriggerEnter >
------------------------------------------------------------------------------*/
void Item::onTriggerEnter(BoxCollider* other) {
	if (other->tag == "player") {
		this->active = false;
		getGame()->resources->getAudio("item_orb")->play();
		this->info->status->birthTime = getGame()->timer->currentTime;
		this->info->active = true;
		this->info->destroy = true;
	}
}
