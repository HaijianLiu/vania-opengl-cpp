
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene12::Scene12() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene12::~Scene12() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene12::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject2", "./Maps/scene_Scene12-BackGround2.csv");
	this->tiledMap->loadMapData("TileObject", "./Maps/scene_Scene12-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "./Maps/scene_Scene12-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "./Maps/scene_Scene12-Camera.csv");
	this->tiledMap->loadMapData("Range", "./Maps/scene_Scene12-Range.csv");
	// enemy
	this->tiledMap->loadMapData("Block", "./Maps/scene_Scene12-Block.csv");
	this->tiledMap->loadMapData("Ball", "./Maps/scene_Scene12-Ball.csv");
	this->tiledMap->loadMapData("AI", "./Maps/scene_Scene12-AI.csv");
	// item
	this->tiledMap->loadMapData("Orb", "./Maps/scene_Scene12-Orb.csv");
	this->tiledMap->loadMapData("Item", "./Maps/scene_Scene12-Item.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene12::set() {
	this->setBackground(0, "background_forest_0");
	this->setBackground(1, "background_forest_2nd");
	this->setBGM("map_normal");
	this->tiledMap->gameObjects["Item"][0]->status->tag = "bronze";
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene12::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x > this->tiledMap->gameObjects["Range"][0]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene00");
	}
	if (getGame()->player->transform->position.y > this->tiledMap->gameObjects["Range"][1]->transform->position.y) {
		getGame()->sceneManager->setActiveScene("Scene07");
	}
}
