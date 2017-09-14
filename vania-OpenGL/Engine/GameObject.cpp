
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
< preStart >
------------------------------------------------------------------------------*/
void GameObject::preStart() {
	this->birthTime = this->timer->currentTime;
	this->resources->getShader("Quad")->use();
	this->resources->getShader("Quad")->setInt("texColor", 0);
}


/*------------------------------------------------------------------------------
< draw >
------------------------------------------------------------------------------*/
void GameObject::draw() {
	this->transform->update();
	this->resources->getShader("Quad")->use();
	this->resources->getShader("Quad")->setMat4("projection",this->camera->projection);
	this->resources->getShader("Quad")->setMat4("view",this->camera->view);
	this->resources->getShader("Quad")->setMat4("model",this->transform->model);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->resources->getTexture("enemy_jumper_jump")->textureID);
	this->quad->draw();
}
