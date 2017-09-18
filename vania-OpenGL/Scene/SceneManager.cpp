
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
SceneManager::SceneManager() {
	SceneManager::creatScene("Scene00", new Scene00());
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
void SceneManager::creatScene(const char* name, Scene* scene) {
	this->scenes.insert(std::make_pair(name, scene));
}
