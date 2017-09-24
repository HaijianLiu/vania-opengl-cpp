
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
AIObject::AIObject() {
	// GameObject setting
	// this->transform->position.z = 1.0f;
	this->visible = false;
	// scale in real pixel
	// ...
	// Collider (this,offsetX,offsetY,sizeX,sizeY) size is in real pixel && Collider is trigger ?
	this->collider = new BoxCollider(this,0.0f,0.0f,16.0f,16.0f);
	this->collider->tag = "ai";
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
AIObject::~AIObject() {

}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void AIObject::start() {
	// set sprite texture and slice | Animation start
	this->sprite->texture = getGame()->resources->getTexture("tilesets");
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void AIObject::update() {
	/* Animation update sprite
	..............................................................................*/
}


/*------------------------------------------------------------------------------
< on Trigger Enter >
------------------------------------------------------------------------------*/
void AIObject::onTriggerEnter(BoxCollider* other) {

}
