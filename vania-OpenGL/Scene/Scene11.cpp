
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene11::Scene11() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene11::~Scene11() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene11::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject", "./Maps/scene_Scene11-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "./Maps/scene_Scene11-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "./Maps/scene_Scene11-Camera.csv");
	this->tiledMap->loadMapData("Range", "./Maps/scene_Scene11-Range.csv");
	// boss
	this->tiledMap->loadMapData("Boss", "./Maps/scene_Scene11-Boss.csv");
	// item
	this->tiledMap->loadMapData("Orb", "./Maps/scene_Scene11-Orb.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene11::set() {
	this->setBackground(1, "background_tissue_2nd");
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene11::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x < this->tiledMap->gameObjects["Range"][0]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene10");
	}
	if (!this->tiledMap->gameObjects["Boss"][0]->active && !getGame()->resources->getAudio("boss_destroy")->playing() && !getGame()->resources->getAudio("boss_win")->playing()) {
		getGame()->sceneManager->setActiveScene("SceneTitle");
		this->tiledMap->gameObjects["Boss"][0]->reset();
	}
}

void Scene11::reset() {
	this->tiledMap->gameObjects["Boss"][0]->reset();
}
