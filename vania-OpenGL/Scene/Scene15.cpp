
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene15::Scene15() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene15::~Scene15() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene15::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject", "./Maps/scene_Scene15-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "./Maps/scene_Scene15-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "./Maps/scene_Scene15-Camera.csv");
	this->tiledMap->loadMapData("Range", "./Maps/scene_Scene15-Range.csv");
	// enemy
	this->tiledMap->loadMapData("Block", "./Maps/scene_Scene15-Block.csv");
	this->tiledMap->loadMapData("Crab", "./Maps/scene_Scene15-Crab.csv");
	this->tiledMap->loadMapData("Jumper", "./Maps/scene_Scene15-Jumper.csv");
	this->tiledMap->loadMapData("AI", "./Maps/scene_Scene15-AI.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene15::set() {
	this->setBackground(1, "background_tissue_2nd");
	this->setBGM("map_mars");
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene15::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x > this->tiledMap->gameObjects["Range"][2]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene16");
	}
	if (getGame()->player->transform->position.x < this->tiledMap->gameObjects["Range"][1]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene14");
	}
	if (getGame()->player->transform->position.y < this->tiledMap->gameObjects["Range"][0]->transform->position.y) {
		getGame()->sceneManager->setActiveScene("Scene22");
	}
}
