
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
ColliderObject::ColliderObject() {
	// GameObject setting
	// this->transform->position.z = 1.0f;
	this->visible = false;
	// scale in real pixel
	// ...
	// Collider (this,offsetX,offsetY,sizeX,sizeY) size is in real pixel && Collider is trigger ?
	this->collider = new BoxCollider(this,0.0f,0.0f,16.0f,16.0f);
	this->collider->tag = "ground";
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
ColliderObject::~ColliderObject() {

}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void ColliderObject::start() {
	// set sprite texture and slice | Animation start
	this->sprite->texture = getGame()->resources->getTexture("tilesets");
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void ColliderObject::update() {
	/* Animation update sprite
	..............................................................................*/
}


/*------------------------------------------------------------------------------
< on Trigger Enter >
------------------------------------------------------------------------------*/
void ColliderObject::onTriggerEnter(BoxCollider* other) {

}
