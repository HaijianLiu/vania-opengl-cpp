
#include "Engine.hpp"

Time::Time() {

}

Time::~Time() {

}

void Time::start() {
	this->lastTime = glfwGetTime();
}

// in a game loop but not in FPS check loop
void Time::setTime() {
	this->currentTime = glfwGetTime();
}


// in FPS check loop
void Time::update() {

	// from setTime **** for test
	this->currentTime = glfwGetTime();

	this->deltaTime = this->currentTime - this->lastTime;
	if (this->deltaTime > 0.04f) {
		this->deltaTime = 0.032f;
	}
	this->lastTime = this->currentTime;
}


bool Time::checkFPS(int frameRate) {
	if (this->currentTime - this->lastTime >= 1.0f / frameRate) {
		return true;
	}
	else {
		return false;
	}
}
