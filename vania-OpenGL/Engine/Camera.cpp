
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Camera::Camera() {
	this->window = getWindow();
	this->projection = glm::ortho(-this->window->screenWidth/2.0f, this->window->screenWidth/2.0f, -this->window->screenHeight/2.0f, this->window->screenHeight/2.0f, 0.0f, 100.0f);
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Camera::~Camera() {

}


/*------------------------------------------------------------------------------
< update > after GameObject fixedUpdate() before GameObject draw()
------------------------------------------------------------------------------*/
void Camera::update() {
	this->view = glm::lookAt(
		glm::vec3(this->position.x * PIXEL_SCALE * UNIT_TO_PIXEL * this->window->retina ,this->position.y * PIXEL_SCALE * UNIT_TO_PIXEL * this->window->retina , this->position.z), // camera position
		glm::vec3(this->position.x * PIXEL_SCALE * UNIT_TO_PIXEL * this->window->retina ,this->position.y * PIXEL_SCALE * UNIT_TO_PIXEL * this->window->retina , 0), // target position
		glm::vec3(0,1,0)  // up
	);
}
