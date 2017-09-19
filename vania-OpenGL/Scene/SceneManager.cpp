
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
	this->activeScene = "Scene00";
	// start Scenes
	for (std::map<const char*, Scene*>::iterator it = this->scenes.begin(); it != this->scenes.end(); it++) {
		it->second->start();
	}
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void SceneManager::update() {
	if (this->scenes.find(activeScene) != this->scenes.end()) {
		this->scenes[activeScene]->update();
	}
}


/*------------------------------------------------------------------------------
< creat Scene >
------------------------------------------------------------------------------*/
void SceneManager::createScene(const char* name, Scene* scene) {
	this->scenes.insert(std::make_pair(name, scene));
}
