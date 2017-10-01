
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene02::Scene02() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene02::~Scene02() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene02::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject2", "./Maps/scene_Scene02-BackGround2.csv");
	this->tiledMap->loadMapData("TileObject", "./Maps/scene_Scene02-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "./Maps/scene_Scene02-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "./Maps/scene_Scene02-Camera.csv");
	this->tiledMap->loadMapData("Range", "./Maps/scene_Scene02-Range.csv");
	// check point
	this->tiledMap->loadMapData("Player", "./Maps/scene_Scene02-Player.csv");
	// enemy
	this->tiledMap->loadMapData("Flyer", "./Maps/scene_Scene02-Flyer.csv");
	// item
	this->tiledMap->loadMapData("Orb", "./Maps/scene_Scene02-Orb.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene02::set() {
	this->setBackground(0, "background_forest_0");
	this->setBackground(1, "background_forest_2nd");
	this->setBGM("map_basic");
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene02::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x < this->tiledMap->gameObjects["Range"][0]->transform->position.x) {
		if (distancePow(getGame()->player->transform->position, this->tiledMap->gameObjects["Range"][0]->transform->position) < 1.0f) {
			getGame()->sceneManager->setActiveScene("Scene01");
		}
		else {
			getGame()->sceneManager->setActiveScene("Scene03");
		}
	}
}
