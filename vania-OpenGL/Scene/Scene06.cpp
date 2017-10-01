
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene06::Scene06() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene06::~Scene06() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene06::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject2", "./Maps/scene_Scene06-BackGround2.csv");
	this->tiledMap->loadMapData("TileObject", "./Maps/scene_Scene06-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "./Maps/scene_Scene06-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "./Maps/scene_Scene06-Camera.csv");
	this->tiledMap->loadMapData("Range", "./Maps/scene_Scene06-Range.csv");
	// enemy
	this->tiledMap->loadMapData("Block", "./Maps/scene_Scene06-Block.csv");
	this->tiledMap->loadMapData("Crab", "./Maps/scene_Scene06-Crab.csv");
	this->tiledMap->loadMapData("Flyer", "./Maps/scene_Scene06-Flyer.csv");
	this->tiledMap->loadMapData("Jumper", "./Maps/scene_Scene06-Jumper.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene06::set() {
	this->setBackground(0, "background_forest_0");
	this->setBackground(1, "background_forest_2nd");
	this->setBGM("map_normal");
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene06::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x > this->tiledMap->gameObjects["Range"][2]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene05");
	}
	if (getGame()->player->transform->position.x < this->tiledMap->gameObjects["Range"][1]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene13");
	}
	if (getGame()->player->transform->position.y < this->tiledMap->gameObjects["Range"][0]->transform->position.y) {
		getGame()->sceneManager->setActiveScene("Scene07");
	}
}
