
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
	this->keys[key] = action;
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
	if (this->keys[button] == GLFW_PRESS || this->keys[button] == GLFW_REPEAT) return true;
	else return false;
}

bool Input::getButtonTrigger(int button) {
	if (this->keys[button] == GLFW_PRESS) {
		this->keys[button] = GLFW_REPEAT; return true;
	}
	else return false;
}
