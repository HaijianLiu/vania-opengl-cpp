
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Player::Player() {
	// new objects
	this->input = new Input();
	// scale in real pixel
	this->transform->scale = glm::vec3(80.0f,80.0f,0.0f);
	// Animation (textureName, divideX, divideY, sampleTime)
	this->animRun = new Animation("player_run_shoot",10,1,4);
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Player::~Player() {
	delete this->input;
}


/*------------------------------------------------------------------------------
< Start >
------------------------------------------------------------------------------*/
void Player::start() {
	// set sprite texture and slice | Animation start
	// this->sprite->texture = this->resources->getTexture("player_run_shoot");
	// this->sprite->setSlice(0.0f,0.0f,80.0f,80.0f);
	this->animRun->start();
}


/*------------------------------------------------------------------------------
< Update >
------------------------------------------------------------------------------*/
void Player::update() {
	// if (this->input->getButtonPress(GLFW_KEY_DOWN)) {
	// 	this->transform->position.y += 1.0f * this->timer->deltaTime;
	// }
	this->transform->position = glm::vec3(2.0f,1.2f,0.0f);

	// Animation update sprite
	this->animRun->update(this->sprite);
}


/*------------------------------------------------------------------------------
< On Trigger Enter >
------------------------------------------------------------------------------*/
// void Player::onTriggerEnter(BoxCollider* other) {
//
// }


/*------------------------------------------------------------------------------
< Fixed Update >
------------------------------------------------------------------------------*/
void Player::fixedUpdate() {

}
