
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Input::Input() {
	this->window = getWindow();
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Input::~Input() {

}

bool Input::getButtonPress(int button) {
	if (glfwGetKey(this->window->window, button) == GLFW_PRESS) return true;
	else return false;
}
