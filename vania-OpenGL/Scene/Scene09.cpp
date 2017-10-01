
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene09::Scene09() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene09::~Scene09() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene09::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject", "./Maps/scene_Scene09-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "./Maps/scene_Scene09-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "./Maps/scene_Scene09-Camera.csv");
	this->tiledMap->loadMapData("Range", "./Maps/scene_Scene09-Range.csv");
	// item
	this->tiledMap->loadMapData("Item", "./Maps/scene_Scene09-Item.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene09::set() {
	this->setBackground(1, "background_ship_2nd");
	this->tiledMap->gameObjects["Item"][0]->status->tag = "sliver";
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene09::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x < this->tiledMap->gameObjects["Range"][0]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene08");
	}
	if (getGame()->player->transform->position.y > this->tiledMap->gameObjects["Range"][1]->transform->position.y) {
		getGame()->sceneManager->setActiveScene("Scene05");
	}
}
