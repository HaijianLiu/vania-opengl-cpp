
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
< start > in GameObject defaultStart()
------------------------------------------------------------------------------*/
void Sprite::start() {
	// sprite get default resources
	this->quad = this->gameObject->resources->quad;
	this->shader = this->gameObject->resources->getShader("Sprite");
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
	// shader
	this->shader->use();
	// transform
	this->shader->setMat4("view", this->gameObject->camera->view);
	this->shader->setMat4("model", this->gameObject->transform->model);
	// slice
	this->shader->setMat3("slice", this->slice);
	// flip
	if (this->flipX) this->shader->setMat3("flip", this->matFlipX);
	else this->shader->setMat3("flip", glm::mat3(1.0f));
	// color
	this->shader->setVec4("spriteColor", this->color);
	// texture
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->texture->textureID);
	// draw
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


/*------------------------------------------------------------------------------
< setColor >
------------------------------------------------------------------------------*/
void Sprite::setColor(float r, float g, float b, float a) {
	this->color = glm::vec4(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
}
