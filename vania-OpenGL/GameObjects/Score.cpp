
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Score::Score() {
	// Set GameObject
	this->visible = false;
	// GameObject
	for (unsigned int i = 0; i < this->max; i++) {
		this->numbers.push_back(new UIObject(this->offset.x + (this->max - i - 1) * this->size.x, this->offset.y, this->size.x, this->size.y));
	}
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Score::~Score() {

}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void Score::start() {
	// set sprite texture and slice | Animation start
	for (unsigned int i = 0; i < this->numbers.size(); i++) {
		this->numbers[i]->active = false;
		this->numbers[i]->sprite->texture = getGame()->resources->getTexture("ui_numbers");
		this->numbers[i]->sprite->setSlice(0.0f,0.0f,this->size.x,this->size.y);
	}

	// show zero
	this->numbers[0]->active = true;
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void Score::update() {
	if (this->willAddScore != 0) {
		this->score++;
		Score::addOne(0);
		this->willAddScore--;
	}
}

void Score::addOne(unsigned int i) {
	if (i < this->max) {
		if (this->numbers[i]->sprite->slice[2].x < 0.9f) {
			if (!this->numbers[i]->active) {
				this->numbers[i]->active = true;
			}
			this->numbers[i]->sprite->slice[2].x += 0.1f;
		}
		else {
			this->numbers[i]->sprite->slice[2].x = 0.0f;
			Score::addOne(i+1);
		}
	}
}

void Score::willAdd(unsigned int i) {
	this->willAddScore += i;
}


/*------------------------------------------------------------------------------
< onTriggerEnter >
------------------------------------------------------------------------------*/
void Score::onTriggerEnter(BoxCollider* other) {

}


/*------------------------------------------------------------------------------
< fixedUpdate >
------------------------------------------------------------------------------*/
void Score::fixedUpdate() {

}
