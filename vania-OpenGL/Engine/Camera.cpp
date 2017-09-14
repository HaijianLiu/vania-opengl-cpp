
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Camera::Camera() {
	this->window = getWindow();
	this->projection = glm::ortho(0.0f, (float)this->window->screenWidth, 0.0f, (float)this->window->screenHeight, 0.0f, 100.0f);
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Camera::~Camera() {

}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void Camera::update() {
	this->view = glm::lookAt(
		glm::vec3(this->position.x * PIXEL_SCALE * UNIT_TO_PIXEL * this->window->retina ,this->position.y * PIXEL_SCALE * UNIT_TO_PIXEL * this->window->retina , 1), // camera position
		glm::vec3(this->position.x * PIXEL_SCALE * UNIT_TO_PIXEL * this->window->retina ,this->position.y * PIXEL_SCALE * UNIT_TO_PIXEL * this->window->retina , 0), // target position
		glm::vec3(0,1,0)  // up
	);
}
