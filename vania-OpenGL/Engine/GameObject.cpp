
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
GameObject::GameObject() {
	// GetGameObjects and push_back
	this->gameObjects = getGameObjects();
	this->gameObjects->push_back(this);
	// get objects
	this->quad = getQuad();
	this->timer = getTimer();
	this->camera = getCamera();
	this->resources = getResources();
	// new objects
	this->transform = new Transform();
	this->sprite = new Sprite();
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
	// sprite get resources
	this->sprite->shader = this->resources->getShader("Quad");
	this->sprite->texture = this->resources->getTexture("Default");
	// sprite default setting
	this->sprite->shader->use();
	this->sprite->shader->setMat4("projection",this->camera->projection);
	this->sprite->shader->setInt("texColor", 0);
}


/*------------------------------------------------------------------------------
< draw >
------------------------------------------------------------------------------*/
void GameObject::draw() {
	this->transform->update();
	this->sprite->shader->use();
	this->sprite->shader->setMat4("view",this->camera->view);
	this->sprite->shader->setMat4("model",this->transform->model);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->resources->getTexture("enemy_jumper_jump")->textureID);
	this->quad->draw();
}
