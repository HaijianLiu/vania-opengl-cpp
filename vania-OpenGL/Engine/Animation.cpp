
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Animation::Animation(const char* textureName, float divideX, float divideY, float sampleTime) {
	// get
	this->timer = getTimer();
	this->resources = getResources();
	// set parameters
	this->textureName = textureName;
	this->divide.x = divideX;
	this->divide.y = divideY;
	this->sampleTime = sampleTime;
	this->counter = 0;
	this->currentSlice = 0;
	this->lastCounterTime = 0.0f;
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Animation::~Animation() {

}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void Animation::start() {
	// load texture
	this->texture = this->resources->getTexture(this->textureName);
	// set slices
	this->sliceSize = glm::vec2(this->texture->width / this->divide.x, this->texture->height / this->divide.y);
	this->sliceMax = this->divide.x * this->divide.y;
	for (int i = 0; i < this->sliceMax; i++) {
		glm::mat3 slice = {
			this->sliceSize.x / this->texture->width, 0.0f, 0.0f,
			0.0f, this->sliceSize.y / this->texture->height, 0.0f,
			(i % (int)this->divide.x) * this->sliceSize.x / this->texture->width, (i / (int)this->divide.x) * this->sliceSize.y / this->texture->height, 1.0f,
		};
		this->slices.push_back(slice);
	}
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void Animation::update(Sprite* sprite) {
	// counter ++ per 1/60 seconds
	if (this->timer->currentTime > 1.0f/60.f + this->lastCounterTime) {
		this->counter++;
		// reset counter when currentSlice ++
		if (this->counter > this->sampleTime - 1) {
			this->counter = 0;
		}
		this->lastCounterTime = this->timer->currentTime;
	}

	// update currentSlice
	if(this->counter % (int)this->sampleTime == 0) {
		this->currentSlice = (this->currentSlice + 1) % this->sliceMax;
	}

	// update sprite
	sprite->texture = this->texture;
	sprite->slice = this->slices[this->currentSlice];
}
