
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Player::Player() {
	// Input
  this->input = Input::getInstance();
	// scale in real pixel
	this->transform->scale = glm::vec3(80.0f,80.0f,1.0f);

	// Collider (this,offsetX,offsetY,sizeX,sizeY) size is in real pixel && Collider is trigger ?
	this->collGroundCheck = new BoxCollider(this,0.0f,0.21f,8.0f,4.0f);
	this->collGroundCheck->trigger = true;
	this->collGroundCheck->tag = "ground_check";
	this->collCeilingCheck = new BoxCollider(this,0.0f,-0.05f,4.0f,4.0f);
	this->collCeilingCheck->trigger = true;
	this->collCeilingCheck->tag = "ceiling_check";
	this->collHorizonCheck = new BoxCollider(this,0.0f,0.08f,24.0f,28.0f);
	this->collHorizonCheck->trigger = true;
	this->collHorizonCheck->tag = "player";
	// Animation (textureName, divideX, divideY, sampleTime)
	this->animIdle = new Animation("player_idle", 3,1,15);
	this->animShoot = new Animation("player_shoot", 3,1,4);
	this->animRun = new Animation("player_run_shoot", 10,1,4);
	this->animJump = new Animation("player_jump", 6,1,4);
	this->animDuck = new Animation("player_duck", 1,1,60);
	this->animDuckShoot = new Animation("player_duck_shoot", 3,1,4);
	this->animHurt = new Animation("player_hurt", 1,1,60);
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Player::~Player() {
	// BoxCollider
	delete this->collGroundCheck;
	delete this->collCeilingCheck;
	delete this->collHorizonCheck;
	// Animation
	delete this->animIdle;
	delete this->animShoot;
	delete this->animRun;
	delete this->animJump;
	delete this->animDuck;
	delete this->animDuckShoot;
	delete this->animHurt;
}


/*------------------------------------------------------------------------------
< Start >
------------------------------------------------------------------------------*/
void Player::start() {
	this->transform->position = glm::vec3(0.0f,0.0f,0.0f);

	// set sprite texture and slice | Animation start
	// this->sprite->texture = this->resources->getTexture("player_run_shoot");
	// this->sprite->setSlice(0.0f,0.0f,80.0f,80.0f);
	this->animIdle->start();
	this->animShoot->start();
	this->animRun->start();
	this->animJump->start();
	this->animDuck->start();
	this->animDuckShoot->start();
	this->animHurt->start();
}


/*------------------------------------------------------------------------------
< Update > before gameObject draw()
------------------------------------------------------------------------------*/
void Player::update() {

	/* transform
	..............................................................................*/
	if (!this->hurt) {
		// move
		if (this->input->getButtonPress(GLFW_KEY_LEFT) || this->input->getButtonPress(GLFW_KEY_A)) {
			this->move = true;
			this->right = false;
			this->sprite->flipX = !this->right;
			this->transform->position.x -= this->speed * this->timer->deltaTime;
		}
		else if (this->input->getButtonPress(GLFW_KEY_RIGHT) || this->input->getButtonPress(GLFW_KEY_D)) {
			this->move = true;
			this->right = true;
			this->sprite->flipX = !this->right;
			this->transform->position.x += this->speed * this->timer->deltaTime;
		}
		else {
			this->move = false;
		}
		// jump
		if (this->input->getButtonPress(GLFW_KEY_SPACE) || this->input->getButtonPress(GLFW_KEY_J)) {
			if (!this->air) {
				// this->verticalSpeed = this->jumpPower;
				this->air = true;
			}
		}
		// duck
		if (this->input->getButtonPress(GLFW_KEY_DOWN) || this->input->getButtonPress(GLFW_KEY_S)) {
			if (!this->air) {
				this->duck = true;
			}
		}
		else {
			this->duck = false;
		}
	}
	else {
		if (this->right) {
			// this->transform->position.x -= this->backSpeed * this->timer->deltaTime;
		}
		else {
			// this->transform->position.x += this->backSpeed * this->timer->deltaTime;
		}
	}


	/* shoot
	..............................................................................*/
	if (!this->hurt) {
		if (this->input->getButtonPress(GLFW_KEY_F) || this->input->getButtonPress(GLFW_KEY_K)) {
			if (this->timer->currentTime > this->lastShoot + this->shootColdDown) {
				// if (this->status->hp > this->shootEnergy) {
					this->shoot = true;
					// this->status->hp -= this->shootEnergy;
					// for (unsigned int i = 0; i < this->resources->audShoot.size(); i++) {
					// 	if (!this->resources->audShoot[i]->Playing()) {
					// 		this->resources->audShoot[i]->Play();
					// 		break;
					// 	}
					// }
					// for (unsigned int i = 0; i < this->bullets.size(); i++) {
					// 	if (!this->bullets[i]->active) {
							this->lastShoot = this->timer->currentTime;
					// 		this->bullets[i]->birthTime = this->time->currentTime;
					// 		this->bullets[i]->right = this->right;
					// 		this->bullets[i]->active = true;
					// 		if (this->right) {
					// 			if (this->duck && !this->move && !this->air) {
					// 				this->bullets[i]->transform->position = this->rightDuckFire->transform->position;
					// 			}
					// 			else {
					// 				this->bullets[i]->transform->position = this->rightFire->transform->position;
					// 			}
					// 		}
					// 		else {
					// 			if (this->duck && !this->move && !this->air) {
					// 				this->bullets[i]->transform->position = this->leftDuckFire->transform->position;
					// 			}
					// 			else {
					// 				this->bullets[i]->transform->position = this->leftFire->transform->position;
					// 			}
					// 		}
					// 		break;
					// 	}
					// }
				// }
				// else {
				// 	this->resources->audPlayerNoAmmo->Play();
				// }
			}
		}
	}
	// Shoot Flag
	if (this->timer->currentTime > this->lastShoot + this->shootDuration) {
		this->shoot = false;
	}


	/* Animation update sprite
	..............................................................................*/
	if (!this->hurt) {
		if (this->air) {
			this->animJump->update(this->sprite);
		}
		else {
			if (this->move) {
				this->animRun->update(this->sprite);
			}
			if (!this->move) {
				if (this->duck) {
					if (this->shoot) {
						this->animDuckShoot->update(this->sprite);
					}
					else {
						this->animDuck->update(this->sprite);
					}
				}
				else {
					if (this->shoot) {
						this->animShoot->update(this->sprite);
					}
					else{
						this->animIdle->update(this->sprite);
					}
				}
			}
		}
	}
	else {
		this->animHurt->update(this->sprite);
	}
}


/*------------------------------------------------------------------------------
< On Trigger Enter >
------------------------------------------------------------------------------*/
void Player::onTriggerEnter(BoxCollider* other) {

}


/*------------------------------------------------------------------------------
< Fixed Update >
------------------------------------------------------------------------------*/
void Player::fixedUpdate() {

}
