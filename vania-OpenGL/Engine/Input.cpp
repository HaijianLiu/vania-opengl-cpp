
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< callback >
------------------------------------------------------------------------------*/
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	Input::getInstance()->callback(window,key,scancode,action,mods);
}

Input* Input::getInstance() {
	static Input instance;
	return &instance;
}

void Input::callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if(action == GLFW_REPEAT ) {
		std::cout << "GLFW_REPEAT" << key << std::endl;
	} else if (action == GLFW_PRESS) {
		std::cout << "GLFW_PRESS" << key << std::endl;
	} else if (action == GLFW_RELEASE) {
		std::cout << "GLFW_RELEASE" << key << std::endl;
	}
}


/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Input::Input() {
	this->window = getWindow();
	glfwSetKeyCallback(this->window->window, keyCallback);
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Input::~Input() {

}


/*------------------------------------------------------------------------------
< get button action >
------------------------------------------------------------------------------*/
bool Input::getButtonPress(int button) {
	if (glfwGetKey(this->window->window, button) == GLFW_PRESS) return true;
	else return false;
}
