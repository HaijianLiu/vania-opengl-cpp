
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene10::Scene10() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene10::~Scene10() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene10::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject", "./Maps/scene_Scene10-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "./Maps/scene_Scene10-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "./Maps/scene_Scene10-Camera.csv");
	this->tiledMap->loadMapData("Range", "./Maps/scene_Scene10-Range.csv");
	// enemy
	this->tiledMap->loadMapData("Ball", "./Maps/scene_Scene10-Ball.csv");
	this->tiledMap->loadMapData("AI", "./Maps/scene_Scene10-AI.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene10::set() {
	this->setBackground(1, "background_ship_2nd");
	this->setBGM("map_mars");
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene10::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x > this->tiledMap->gameObjects["Range"][0]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene11");
	}
	if (getGame()->player->transform->position.x < this->tiledMap->gameObjects["Range"][1]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene17");
	}
}
