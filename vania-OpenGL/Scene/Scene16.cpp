
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene16::Scene16() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene16::~Scene16() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene16::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject", "./Maps/scene_Scene16-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "./Maps/scene_Scene16-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "./Maps/scene_Scene16-Camera.csv");
	this->tiledMap->loadMapData("Range", "./Maps/scene_Scene16-Range.csv");
	// enemy
	this->tiledMap->loadMapData("Block", "./Maps/scene_Scene16-Block.csv");
	this->tiledMap->loadMapData("Crab", "./Maps/scene_Scene16-Crab.csv");
	this->tiledMap->loadMapData("Ghost", "./Maps/scene_Scene16-Ghost.csv");
	this->tiledMap->loadMapData("AI", "./Maps/scene_Scene16-AI.csv");
	this->tiledMap->loadMapData("Item", "./Maps/scene_Scene16-Item.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene16::set() {
	this->setBackground(1, "background_tissue_2nd");
	this->setBGM("map_mars");
	this->tiledMap->gameObjects["Item"][0]->status->tag = "dark";
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene16::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x > this->tiledMap->gameObjects["Range"][0]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene17");
	}
	if (getGame()->player->transform->position.x < this->tiledMap->gameObjects["Range"][1]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene15");
	}
}
