
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene01::Scene01() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene01::~Scene01() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene01::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject2", "./Maps/scene_Scene01-BackGround2.csv");
	this->tiledMap->loadMapData("TileObject", "./Maps/scene_Scene01-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "./Maps/scene_Scene01-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "./Maps/scene_Scene01-Camera.csv");
	this->tiledMap->loadMapData("Range", "./Maps/scene_Scene01-Range.csv");
	// enemy
	this->tiledMap->loadMapData("Block", "./Maps/scene_Scene01-Block.csv");
	this->tiledMap->loadMapData("Crab", "./Maps/scene_Scene01-Crab.csv");
	this->tiledMap->loadMapData("AI", "./Maps/scene_Scene01-AI.csv");
	// item
	this->tiledMap->loadMapData("Orb", "./Maps/scene_Scene01-Orb.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene01::set() {
	this->setBackground(0, "background_forest_0");
	this->setBackground(1, "background_forest_2nd");
	this->setBGM("map_basic");
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene01::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x < this->tiledMap->gameObjects["Range"][0]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene00");
	}
	if (getGame()->player->transform->position.x > this->tiledMap->gameObjects["Range"][1]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene02");
	}
}
