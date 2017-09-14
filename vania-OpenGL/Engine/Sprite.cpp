
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Sprite::Sprite() {

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
	this->quad = this->gameObject->resources->quad;
	this->shader = this->gameObject->resources->getShader("Quad");
	this->texture = this->gameObject->resources->getTexture("default");
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
	this->shader->setMat3("slice",this->slice);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->texture->textureID);
	this->quad->draw();
}


/*------------------------------------------------------------------------------
< setSlice >
------------------------------------------------------------------------------*/
void Sprite::setSlice(float offsetX, float offsetY, float sizeX, float sizeY) {
	this->slice = {
		sizeX / this->texture->width, 0.0f, 0.0f,
		0.0f, sizeY / this->texture->height, 0.0f,
		offsetX / this->texture->width, offsetY / this->texture->height, 1.0f,
	};
}
