
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Camera::Camera() {
	this->window = getWindow();
	glfwGetFramebufferSize(this->window, &this->screenWidth, &this->screenHeight);
	this->projection = glm::ortho(0.0f, (float)this->screenWidth, 0.0f, (float)this->screenHeight, 0.0f, 100.0f);
	this->view = glm::lookAt(
		glm::vec3(-SCREEN_WIDTH,-SCREEN_HEIGHT,1), // camera position
		glm::vec3(-SCREEN_WIDTH,-SCREEN_HEIGHT,0), // target position
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
