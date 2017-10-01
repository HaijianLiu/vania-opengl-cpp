
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene07::Scene07() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene07::~Scene07() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene07::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject2", "./Maps/scene_Scene07-BackGround2.csv");
	this->tiledMap->loadMapData("TileObject", "./Maps/scene_Scene07-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "./Maps/scene_Scene07-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "./Maps/scene_Scene07-Camera.csv");
	this->tiledMap->loadMapData("Range", "./Maps/scene_Scene07-Range.csv");
	// enemy
	this->tiledMap->loadMapData("Flyer", "./Maps/scene_Scene07-Flyer.csv");
	this->tiledMap->loadMapData("Jumper", "./Maps/scene_Scene07-Jumper.csv");
	this->tiledMap->loadMapData("DamageZone", "./Maps/scene_Scene07-DamageZone.csv");
	this->tiledMap->loadMapData("Block", "./Maps/scene_Scene07-Block.csv");
	// item
	this->tiledMap->loadMapData("Orb", "./Maps/scene_Scene07-Orb.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene07::set() {
	this->setBackground(0, "background_forest_0");
	this->setBackground(1, "background_forest_2nd");
	this->setBGM("map_normal");
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene07::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x > this->tiledMap->gameObjects["Range"][2]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene08");
	}
	if (getGame()->player->transform->position.y > this->tiledMap->gameObjects["Range"][3]->transform->position.y) {
		getGame()->sceneManager->setActiveScene("Scene06");
	}
	if (getGame()->player->transform->position.y < this->tiledMap->gameObjects["Range"][0]->transform->position.y) {
		getGame()->sceneManager->setActiveScene("Scene12");
	}
}
