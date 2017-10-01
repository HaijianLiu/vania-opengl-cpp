
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene20::Scene20() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene20::~Scene20() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene20::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject", "./Maps/scene_Scene20-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "./Maps/scene_Scene20-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "./Maps/scene_Scene20-Camera.csv");
	this->tiledMap->loadMapData("Range", "./Maps/scene_Scene20-Range.csv");
	// enemy
	this->tiledMap->loadMapData("Block", "./Maps/scene_Scene20-Block.csv");
	this->tiledMap->loadMapData("Ball", "./Maps/scene_Scene20-Ball.csv");
	this->tiledMap->loadMapData("AI", "./Maps/scene_Scene20-AI.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene20::set() {
	this->setBackground(1, "background_tissue_2nd");
	this->setBGM("map_mars");
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene20::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x > this->tiledMap->gameObjects["Range"][0]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene19");
	}
	if (getGame()->player->transform->position.y > this->tiledMap->gameObjects["Range"][1]->transform->position.y) {
		getGame()->sceneManager->setActiveScene("Scene21");
	}
}
