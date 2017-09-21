
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
UIObject::UIObject(float offsetX, float offsetY, float sizeX, float sizeY) {
	// GameObject setting
	this->transform->position.z = 6.0f;
	// offset in real pixel
	this->offset = glm::vec2(offsetX,offsetY);
	// scale in real pixel
	this->transform->scale = glm::vec3(sizeX,sizeY,1.0f);
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
UIObject::~UIObject() {

}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void UIObject::start() {
	// set sprite texture and slice | Animation start
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void UIObject::update() {
	if (this->destroy) {
		destroyByTime(this,3.0f);
	}
}


/*------------------------------------------------------------------------------
< onTriggerEnter >
------------------------------------------------------------------------------*/
void UIObject::onTriggerEnter(BoxCollider* other) {

}


/*------------------------------------------------------------------------------
< fixedUpdate >
------------------------------------------------------------------------------*/
void UIObject::fixedUpdate() {

}


/*------------------------------------------------------------------------------
< UIUpdate >
------------------------------------------------------------------------------*/
void UIObject::UIUpdate() {
	this->transform->position.x = this->camera->position.x + this->offset.x * PIXEL_TO_UNIT;
	this->transform->position.y = this->camera->position.y + this->offset.y * PIXEL_TO_UNIT;
}
