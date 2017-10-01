
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene22::Scene22() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene22::~Scene22() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene22::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject", "./Maps/scene_Scene22-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "./Maps/scene_Scene22-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "./Maps/scene_Scene22-Camera.csv");
	this->tiledMap->loadMapData("Range", "./Maps/scene_Scene22-Range.csv");
	// enemy
	this->tiledMap->loadMapData("Flyer", "./Maps/scene_Scene22-Flyer.csv");
	this->tiledMap->loadMapData("Ghost", "./Maps/scene_Scene22-Ghost.csv");
	// item
	this->tiledMap->loadMapData("Orb", "./Maps/scene_Scene22-Orb.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene22::set() {
	this->setBackground(1, "background_tissue_2nd");
	this->setBGM("map_mars");
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene22::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x > this->tiledMap->gameObjects["Range"][0]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene21");
	}
	if (getGame()->player->transform->position.x < this->tiledMap->gameObjects["Range"][1]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene23");
	}
	if (getGame()->player->transform->position.y > this->tiledMap->gameObjects["Range"][2]->transform->position.y) {
		getGame()->sceneManager->setActiveScene("Scene15");
	}
}
