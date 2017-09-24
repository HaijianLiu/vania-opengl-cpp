
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
SceneGameOver::SceneGameOver() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
SceneGameOver::~SceneGameOver() {
	delete this->uiGameOverText;
}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void SceneGameOver::load() {
	// UIObject
	this->uiGameOverText = new UIObject(0.0f,32.0f,64.0f,16.0f);
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void SceneGameOver::set() {
	this->uiGameOverText->sprite->texture = getGame()->resources->getTexture("ui_game_over_text");
}


/*------------------------------------------------------------------------------
< Update >
------------------------------------------------------------------------------*/
// void SceneGameOver::Update() {
// 	// if (this->sceneManager->resources->audBossMainBGM->Playing()) {
// 	// 	this->sceneManager->resources->audBossMainBGM->Stop();
// 	// }
//
// 	this->camera->target = this->sceneManager->player;
// 	// this->uiGameOverText->sprite->Flash();
// 	if (this->sceneManager->player->time->currentTime > this->sceneManager->player->lastGameOver + this->restartDelay * 1000.0f) {
// 		this->sceneManager->SetActiveScene(this->sceneManager->checkPoint);
// 	}
// 	// if (this->sceneManager->resources->audSceneBGM->Playing()) {
// 	// 	this->sceneManager->resources->audSceneBGM->Stop();
// 	// }
// 	// Check Switch Scene
//
// 	// Update
// 	Scene::Update();
// }

/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void SceneGameOver::check() {
	getGame()->camera->target = getGame()->player;
	// Check Switch Scene
	if (getGame()->timer->currentTime > getGame()->player->lastGameOver + this->restartDelay) {
		getGame()->sceneManager->setActiveScene(getGame()->sceneManager->checkedScene);
	}
}
