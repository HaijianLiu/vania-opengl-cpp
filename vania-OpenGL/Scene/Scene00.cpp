
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene00::Scene00() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene00::~Scene00() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene00::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject2", "./Maps/scene_Scene00-BackGround2.csv");
	this->tiledMap->loadMapData("TileObject", "./Maps/scene_Scene00-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "./Maps/scene_Scene00-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "./Maps/scene_Scene00-Camera.csv");
	this->tiledMap->loadMapData("Range", "./Maps/scene_Scene00-Range.csv");
	// check point
	this->tiledMap->loadMapData("Player", "./Maps/scene_Scene00-Player.csv");
	// enemy
	this->tiledMap->loadMapData("Block", "./Maps/scene_Scene00-Block.csv");
	this->tiledMap->loadMapData("Crab", "./Maps/scene_Scene00-Crab.csv");
	this->tiledMap->loadMapData("AI", "./Maps/scene_Scene00-AI.csv");
	// item
	this->tiledMap->loadMapData("Orb", "./Maps/scene_Scene00-Orb.csv");
	// this->tiledMap->loadMapData("Item", "./Maps/scene_Scene00-Item.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene00::set() {
	this->setBackground(0, "background_forest_0");
	this->setBackground(1, "background_forest_2nd");
	this->setBGM("map_basic");
	// this->tiledMap->gameObjects["Item"][0]->status->tag = "gold";
	// this->tiledMap->gameObjects["Item"][1]->status->tag = "sliver";
	// this->tiledMap->gameObjects["Item"][2]->status->tag = "bronze";
	// this->tiledMap->gameObjects["Item"][3]->status->tag = "dark";
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene00::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x > this->tiledMap->gameObjects["Range"][1]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene01");
	}
	if (getGame()->player->transform->position.x < this->tiledMap->gameObjects["Range"][0]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene12");
	}
}
