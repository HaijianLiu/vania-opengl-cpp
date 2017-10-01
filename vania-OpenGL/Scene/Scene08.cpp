
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene08::Scene08() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene08::~Scene08() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene08::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject2", "./Maps/scene_Scene08-BackGround2.csv");
	this->tiledMap->loadMapData("TileObject", "./Maps/scene_Scene08-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "./Maps/scene_Scene08-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "./Maps/scene_Scene08-Camera.csv");
	this->tiledMap->loadMapData("Range", "./Maps/scene_Scene08-Range.csv");
	// enemy
	this->tiledMap->loadMapData("Flyer", "./Maps/scene_Scene08-Flyer.csv");
	this->tiledMap->loadMapData("Jumper", "./Maps/scene_Scene08-Jumper.csv");
	this->tiledMap->loadMapData("DamageZone", "./Maps/scene_Scene08-DamageZone.csv");
	this->tiledMap->loadMapData("Block", "./Maps/scene_Scene08-Block.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene08::set() {
	this->setBackground(1, "background_tissue_2nd");
	this->setBGM("map_normal");
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene08::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x < this->tiledMap->gameObjects["Range"][0]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene07");
	}
	if (getGame()->player->transform->position.x > this->tiledMap->gameObjects["Range"][1]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene09");
	}
}
