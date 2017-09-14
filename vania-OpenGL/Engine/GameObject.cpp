
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
GameObject::GameObject() {
	// GetGameObjects and push_back
	this->gameObjects = getGameObjects();
	this->gameObjects->push_back(this);
	// get Globals
	this->timer = getTimer();
	this->camera = getCamera();
	this->resources = getResources();
	// new GameObject members
	this->transform = new Transform();
	this->sprite = new Sprite();
	this->sprite->gameObject = this;
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
GameObject::~GameObject() {
	delete this->transform;
	delete this->sprite;
}


/*------------------------------------------------------------------------------
< preStart > before gameObject->start() & after resources->start()
------------------------------------------------------------------------------*/
void GameObject::preStart() {
	// get birthtime
	this->birthTime = this->timer->currentTime;
	// sprite start
	this->sprite->start();
}


/*------------------------------------------------------------------------------
< draw >
------------------------------------------------------------------------------*/
void GameObject::draw() {
	// transform update
	this->transform->update();
	// sprite draw
	this->sprite->draw();
}
