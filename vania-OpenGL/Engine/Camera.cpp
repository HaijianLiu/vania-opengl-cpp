
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Camera::Camera() {
	this->window = getWindow();
	this->projection = glm::ortho(0.0f, (float)this->window->screenWidth, 0.0f, (float)this->window->screenHeight, 0.0f, 100.0f);
	this->view = glm::lookAt(
		glm::vec3(-SCREEN_WIDTH/2 * this->window->retina, -SCREEN_HEIGHT/2 * this->window->retina, 1), // camera position
		glm::vec3(-SCREEN_WIDTH/2 * this->window->retina, -SCREEN_HEIGHT/2 * this->window->retina, 0), // target position
		glm::vec3(0,1,0)  // up
	);
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

}
