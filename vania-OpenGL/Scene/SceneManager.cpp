
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
SceneManager::SceneManager() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
SceneManager::~SceneManager() {
	deleteMap(this->scenes);
}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void SceneManager::start() {
	// create Scenes
	SceneManager::createScene("Scene00", new Scene00());
	SceneManager::createScene("Scene01", new Scene01());
	SceneManager::createScene("Scene02", new Scene02());
	SceneManager::createScene("Scene03", new Scene03());
	SceneManager::createScene("Scene04", new Scene04());
	SceneManager::createScene("Scene05", new Scene05());
	SceneManager::createScene("Scene06", new Scene06());
	SceneManager::createScene("Scene07", new Scene07());
	SceneManager::createScene("Scene08", new Scene08());
	SceneManager::createScene("Scene09", new Scene09());
	SceneManager::createScene("Scene10", new Scene10());
	SceneManager::createScene("Scene11", new Scene11());
	SceneManager::createScene("Scene12", new Scene12());
	SceneManager::createScene("Scene13", new Scene13());
	SceneManager::createScene("Scene14", new Scene14());
	SceneManager::createScene("Scene15", new Scene15());
	SceneManager::createScene("Scene16", new Scene16());
	SceneManager::createScene("Scene17", new Scene17());
	SceneManager::createScene("Scene18", new Scene18());
	SceneManager::createScene("Scene19", new Scene19());
	SceneManager::createScene("Scene20", new Scene20());
	SceneManager::createScene("Scene21", new Scene21());
	SceneManager::createScene("Scene22", new Scene22());
	SceneManager::createScene("Scene23", new Scene23());
	SceneManager::createScene("SceneGameOver", new SceneGameOver());
	SceneManager::createScene("SceneTitle", new SceneTitle());

	// start Scenes
	for (std::map<const char*, Scene*>::iterator it = this->scenes.begin(); it != this->scenes.end(); it++) {
		it->second->start();
	}
	// set active Scene
	SceneManager::setActiveScene("SceneTitle");
	// SceneManager::setActiveScene("Scene05");
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void SceneManager::update() {
	if (this->scenes.find(this->activeScene) != this->scenes.end()) {
		this->scenes[this->activeScene]->check();
		this->scenes[this->activeScene]->update();
	}
}


/*------------------------------------------------------------------------------
< creat Scene >
------------------------------------------------------------------------------*/
void SceneManager::createScene(const char* name, Scene* scene) {
	this->scenes.insert(std::make_pair(name, scene));
}


/*------------------------------------------------------------------------------
< set active Scene >
------------------------------------------------------------------------------*/
void SceneManager::setActiveScene(const char* name) {
	// if (this->scenes[this->activeScene]->bgm != nullptr && this->scenes[this->activeScene]->bgm->Playing()) {
	// 	this->scenes[this->activeScene]->bgm->Stop();
	// }
	this->activeScene = name;
	this->scenes[this->activeScene]->tiledMap->reset();
	this->scenes[this->activeScene]->frameSkip = true;
	this->scenes[this->activeScene]->reset();
	if (this->scenes[this->activeScene]->bgm == nullptr) {
		getGame()->resources->iSoundEngine->stopAllSounds();
	}
	// if (this->scenes[this->activeScene]->bgm != nullptr) {
	// 	this->scenes[this->activeScene]->bgm->Play();
	// }
}
