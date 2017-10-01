
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene04::Scene04() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene04::~Scene04() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene04::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject2", "./Maps/scene_Scene04-BackGround2.csv");
	this->tiledMap->loadMapData("TileObject", "./Maps/scene_Scene04-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "./Maps/scene_Scene04-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "./Maps/scene_Scene04-Camera.csv");
	this->tiledMap->loadMapData("Range", "./Maps/scene_Scene04-Range.csv");
	// enemy
	this->tiledMap->loadMapData("Flyer", "./Maps/scene_Scene04-Flyer.csv");
	this->tiledMap->loadMapData("Jumper", "./Maps/scene_Scene04-Jumper.csv");
	this->tiledMap->loadMapData("Block", "./Maps/scene_Scene04-Block.csv");
	// item
	this->tiledMap->loadMapData("Item", "./Maps/scene_Scene04-Item.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene04::set() {
	this->setBackground(0, "background_forest_0");
	this->setBackground(1, "background_forest_2nd");
	this->setBGM("map_basic");
	this->tiledMap->gameObjects["Item"][0]->status->tag = "gold";
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene04::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x > this->tiledMap->gameObjects["Range"][0]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene03");
	}
	if (getGame()->player->transform->position.x < this->tiledMap->gameObjects["Range"][2]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene05");
	}
}
