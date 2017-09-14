
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Transform::Transform() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Transform::~Transform() {

}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void Transform::update() {
	this->model = glm::mat4();
	this->model = glm::rotate(this->rotation.z,glm::vec3(0,0,1));
	this->model = glm::scale(this->model, glm::vec3(this->scale.x * PIXEL_SCALE, this->scale.y * PIXEL_SCALE, this->scale.z * PIXEL_SCALE));
	this->model = glm::translate(this->model, glm::vec3(this->position.x,this->position.y,this->position.z));
}
