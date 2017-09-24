
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
AnimationObject::AnimationObject(const char* textureName, float sizeX, float sizeY, float divideX, float divideY, float sampleTime) {
	// GameObject setting
	this->active = false;
	this->transform->position.z = 1.0f;
	// scale in real pixel
	this->transform->scale = glm::vec3(sizeX, sizeY, 1.0f);
	// Animation (divideX, divideY, sampleTime) || Slice (ID,positionX,positionY,sizeX,sizeY) all in real pixel
	this->animation = new Animation(textureName, divideX, divideY, sampleTime);
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
AnimationObject::~AnimationObject() {
	delete this->animation;
}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void AnimationObject::start() {
	// set sprite texture and slice | Animation start
	this->animation->start();
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void AnimationObject::update() {
	if (!this->loop) {
		if (getGame()->timer->currentTime > this->status->birthTime + this->animation->sliceMax * this->animation->sampleTime / 60.0f) {
			this->active = false;
		}
		else {
			if (this->animation->currentSlice != this->animation->sliceMax - 1) {
				this->animation->update(this->sprite);
			}
		}
	}
}


/*------------------------------------------------------------------------------
< onTriggerEnter >
------------------------------------------------------------------------------*/
void AnimationObject::onTriggerEnter(BoxCollider* other) {

}


/*------------------------------------------------------------------------------
< reset > for instantiate()
------------------------------------------------------------------------------*/
void AnimationObject::reset() {
	this->animation->currentSlice = 0;
	this->animation->lastTime = 0;
	this->animation->update(this->sprite);
}
