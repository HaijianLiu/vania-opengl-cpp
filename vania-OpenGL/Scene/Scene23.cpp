
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene23::Scene23() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene23::~Scene23() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene23::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject", "./Maps/scene_Scene23-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "./Maps/scene_Scene23-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "./Maps/scene_Scene23-Camera.csv");
	this->tiledMap->loadMapData("Range", "./Maps/scene_Scene23-Range.csv");
	// enemy
	this->tiledMap->loadMapData("Ghost", "./Maps/scene_Scene23-Ghost.csv");
	// item
	this->tiledMap->loadMapData("Orb", "./Maps/scene_Scene23-Orb.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene23::set() {
	this->setBackground(1, "background_tissue_2nd");
	this->setBGM("map_mars");
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene23::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x > this->tiledMap->gameObjects["Range"][0]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene22");
	}
	if (getGame()->player->transform->position.y > this->tiledMap->gameObjects["Range"][1]->transform->position.y) {
		getGame()->sceneManager->setActiveScene("Scene14");
	}
}
