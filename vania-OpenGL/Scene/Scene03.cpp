
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene03::Scene03() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene03::~Scene03() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene03::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject2", "./Maps/scene_Scene03-BackGround2.csv");
	this->tiledMap->loadMapData("TileObject", "./Maps/scene_Scene03-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "./Maps/scene_Scene03-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "./Maps/scene_Scene03-Camera.csv");
	this->tiledMap->loadMapData("Range", "./Maps/scene_Scene03-Range.csv");
	// enemy
	this->tiledMap->loadMapData("Block", "./Maps/scene_Scene03-Block.csv");
	this->tiledMap->loadMapData("Crab", "./Maps/scene_Scene03-Crab.csv");
	this->tiledMap->loadMapData("Flyer", "./Maps/scene_Scene03-Flyer.csv");
	this->tiledMap->loadMapData("AI", "./Maps/scene_Scene03-AI.csv");
	// item
	this->tiledMap->loadMapData("Orb", "./Maps/scene_Scene03-Orb.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene03::set() {
	this->setBackground(0, "background_forest_0");
	this->setBackground(1, "background_forest_2nd");
	this->setBGM("map_basic");
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene03::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x > this->tiledMap->gameObjects["Range"][1]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene02");
	}
	if (getGame()->player->transform->position.x < this->tiledMap->gameObjects["Range"][0]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene04");
	}
}
