
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
SceneTitle::SceneTitle() {
	// Input
	this->input = Input::getInstance();
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
SceneTitle::~SceneTitle() {
	delete this->uiTitle;
	delete this->uiTitleBG;
	delete this->uiTitleStart;
	delete this->uiTitleCredits;
	delete this->uiTitleOption;
	delete this->uiTitleCreditsText;
	delete this->uiTitleOptionText;
}


/*------------------------------------------------------------------------------
< load > in Scene start()
------------------------------------------------------------------------------*/
void SceneTitle::load() {
	// UIObject
	this->uiTitleBG = new UIObject(0,0,400,250);
	this->uiTitleStart = new UIObject(0,54,64,8);
	this->uiTitleCredits = new UIObject(0,64,64,8);
	this->uiTitleOption = new UIObject(0,74,64,8);
	this->uiTitleCreditsText = new UIObject(0,0,400,250);
	this->uiTitleCreditsText->visible = false;
	this->uiTitleOptionText = new UIObject(0,0,400,250);
	this->uiTitleOptionText->visible = false;
	this->uiTitlePress = new UIObject(0,88,88,7);
	this->uiTitlePress->visible = false;
	this->uiTitle = new UIObject(0,0,400,250);
}


/*------------------------------------------------------------------------------
< set > in Scene start()
------------------------------------------------------------------------------*/
void SceneTitle::set() {
	this->uiTitle->sprite->texture = getGame()->resources->getTexture("title_title");
	this->uiTitleBG->sprite->texture = getGame()->resources->getTexture("title_star");
	this->uiTitleStart->sprite->texture = getGame()->resources->getTexture("title_text");
	this->uiTitleCredits->sprite->texture = getGame()->resources->getTexture("title_text");
	this->uiTitleOption->sprite->texture = getGame()->resources->getTexture("title_text");
	this->uiTitleCreditsText->sprite->texture = getGame()->resources->getTexture("title_credits");
	this->uiTitleOptionText->sprite->texture = getGame()->resources->getTexture("title_option");
	this->uiTitlePress->sprite->texture = getGame()->resources->getTexture("title_enter");


	this->uiTitleStart->sprite->setSlice(0,0,64,8);
	this->uiTitleCredits->sprite->setSlice(0,8,64,8);
	this->uiTitleCredits->sprite->setColor(100,100,100,255);
	this->uiTitleOption->sprite->setSlice(0,16,64,8);
	this->uiTitleOption->sprite->setColor(100,100,100,255);

	// this->uiTitleStart->sprite->flashTime = this->enterDelay;
	// this->uiTitleCredits->sprite->flashTime = this->enterDelay;
	// this->uiTitleOption->sprite->flashTime = this->enterDelay;


	getGame()->player->uiEnergyBG->active = false;
	getGame()->player->uiEnergy->active = false;
	getGame()->player->score->active = false;
}


/*------------------------------------------------------------------------------
< end > before Scene update()
------------------------------------------------------------------------------*/
void SceneTitle::end() {
	this->uiTitleBG->sprite->setColor(this->counter/2,this->counter/2,this->counter/2,255);
	if (this->counter < 510) {
		this->counter ++ ;
	}
	this->uiTitleBG->offset.x += 0.05f * sin(getGame()->timer->currentTime/2);
	this->uiTitleBG->offset.y += 0.02f * cos(getGame()->timer->currentTime);
	if (!this->enter) {
		if (this->input->getButtonPress(GLFW_KEY_DOWN)) {
//			this->sceneManager->resources->audCurser->Play();
			this->selected ++;
			if (this->selected > 2) {
				this->selected = 2;
			}
		}
		if (this->input->getButtonPress(GLFW_KEY_UP)) {
//			this->sceneManager->resources->audCurser->Play();
			this->selected --;
			if (this->selected < 0) {
				this->selected = 0;
			}
		}
		if (this->input->getButtonPress(GLFW_KEY_ENTER)) {
			this->enter = true;
			switch (this->selected) {
				case 0:
//					this->sceneManager->resources->audStart->Play();
					this->lastEnter = getGame()->timer->currentTime;
//					this->uiTitleStart->sprite->Flash();
					break;
				case 1:
					this->uiTitleCredits->visible = false;
					this->uiTitleStart->visible = false;
					this->uiTitleOption->visible = false;
					this->uiTitle->visible = false;
					this->uiTitleCreditsText->visible = true;
					this->uiTitlePress->visible = true;
//					this->sceneManager->resources->audSelect->Play();
					break;
				case 2:
					this->uiTitleCredits->visible = false;
					this->uiTitleStart->visible = false;
					this->uiTitleOption->visible = false;
					this->uiTitle->visible = false;
					this->uiTitleOptionText->visible = true;
					this->uiTitlePress->visible = true;
//					this->sceneManager->resources->audSelect->Play();
					break;
			}
		}
	}
	else {
//		this->uiTitlePress->sprite->Flash();
		if (this->selected == 0) {
			if (getGame()->timer->currentTime > this->lastEnter + this->enterDelay) {
				switch (this->selected) {
					case 0:
						getGame()->sceneManager->setActiveScene("Scene00");
						break;
					case 1:
						break;
					case 2:
						break;
				}
			}
		}
		else {
			if (this->input->getButtonPress(GLFW_KEY_ENTER)) {
				this->uiTitleCredits->visible = true;
				this->uiTitleStart->visible = true;
				this->uiTitleOption->visible = true;
				this->uiTitle->visible = true;
				this->uiTitleCreditsText->visible = false;
				this->uiTitleOptionText->visible = false;
				this->uiTitlePress->visible = false;
				this->enter = false;
			}
		}
	}

	// Draw
	switch (this->selected) {
		case 0:
			this->uiTitleStart->sprite->setColor(255,255,255,255);
			this->uiTitleCredits->sprite->setColor(100,100,100,255);
			this->uiTitleOption->sprite->setColor(100,100,100,255);
			break;
		case 1:
			this->uiTitleStart->sprite->setColor(100,100,100,255);
			this->uiTitleCredits->sprite->setColor(255,255,255,255);
			this->uiTitleOption->sprite->setColor(100,100,100,255);
			break;
		case 2:
			this->uiTitleStart->sprite->setColor(100,100,100,255);
			this->uiTitleCredits->sprite->setColor(100,100,100,255);
			this->uiTitleOption->sprite->setColor(255,255,255,255);
			break;
	}
}


/*------------------------------------------------------------------------------
< reset > in SceneManager setActiveScene()
------------------------------------------------------------------------------*/
void SceneTitle::reset() {
	// frameDelay
	this->frameSkip = true;
}


/*------------------------------------------------------------------------------
< clear >
------------------------------------------------------------------------------*/
void SceneTitle::clear() {

}
