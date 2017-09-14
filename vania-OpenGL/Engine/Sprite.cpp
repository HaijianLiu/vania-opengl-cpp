
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Sprite::Sprite() {
	// get Globals
	this->quad = getQuad();
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Sprite::~Sprite() {

}


/*------------------------------------------------------------------------------
< start > in GameObject preStart()
------------------------------------------------------------------------------*/
void Sprite::start() {
	// sprite get default resources
	this->shader = this->gameObject->resources->getShader("Quad");
	this->texture = this->gameObject->resources->getTexture("Default");
	// sprite default setting
	this->shader->use();
	this->shader->setMat4("projection",this->gameObject->camera->projection);
	this->shader->setInt("texColor", 0);
}


/*------------------------------------------------------------------------------
< draw > in GameObject update()
------------------------------------------------------------------------------*/
void Sprite::draw() {
	this->shader->use();
	this->shader->setMat4("view",this->gameObject->camera->view);
	this->shader->setMat4("model",this->gameObject->transform->model);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->texture->textureID);
	this->quad->draw();
}
