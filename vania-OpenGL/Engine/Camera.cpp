
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
< update > after GameObject fixedUpdate() before Camera updateUniform()
------------------------------------------------------------------------------*/
void Camera::updatePosition() {
	// Camera position
	if (this->target != nullptr) {
		if (!this->switching) {
			this->position.x = this->target->transform->position.x;
			this->position.y = this->target->transform->position.y;
		}
		else {
			if (this->position.x != this->target->transform->position.x) {
				if (this->position.x > this->target->transform->position.x) {
					this->position.x -= this->switchSpeed * getGame()->timer->deltaTime;
					if (this->position.x < this->target->transform->position.x) {
						this->position.x = this->target->transform->position.x;
					}
				}
				else {
					this->position.x += this->switchSpeed * getGame()->timer->deltaTime;
					if (this->position.x > this->target->transform->position.x) {
						this->position.x = this->target->transform->position.x;
					}
				}
			}
			if (this->position.x == this->target->transform->position.x) {
				this->switching = false;
			}
		}
	}
}


/*------------------------------------------------------------------------------
< update > after Camera updatePosition() maybe after Scene fixCamera() before GameObject draw()
------------------------------------------------------------------------------*/
void Camera::updateUniform() {
	float positionX = this->position.x * PIXEL_SCALE * UNIT_TO_PIXEL * this->window->retina;
	float positionY = this->position.y * PIXEL_SCALE * UNIT_TO_PIXEL * this->window->retina;
	
	this->view = glm::lookAt(
		glm::vec3(positionX, positionY, this->position.z), // camera position
		glm::vec3(positionX, positionY, 0), // target position
		glm::vec3(0,1,0)  // up
	);
}


/*------------------------------------------------------------------------------
< switchTarget >
------------------------------------------------------------------------------*/
void Camera::switchTarget(GameObject* target) {
	if (!this->switching) {
		this->switching = true;
		this->target = target;
	}
}

