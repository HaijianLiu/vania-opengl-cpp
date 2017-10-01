
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene17::Scene17() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene17::~Scene17() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene17::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject", "./Maps/scene_Scene17-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "./Maps/scene_Scene17-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "./Maps/scene_Scene17-Camera.csv");
	this->tiledMap->loadMapData("Range", "./Maps/scene_Scene17-Range.csv");
	// enemy
	this->tiledMap->loadMapData("Block", "./Maps/scene_Scene17-Block.csv");
	this->tiledMap->loadMapData("Ball", "./Maps/scene_Scene17-Ball.csv");
	this->tiledMap->loadMapData("AI", "./Maps/scene_Scene17-AI.csv");
	// item
	this->tiledMap->loadMapData("Orb", "./Maps/scene_Scene17-Orb.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene17::set() {
	this->setBackground(1, "background_tissue_2nd");
	this->setBGM("map_mars");
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene17::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x > this->tiledMap->gameObjects["Range"][4]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene10");
	}
	if (getGame()->player->transform->position.x < this->tiledMap->gameObjects["Range"][2]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene16");
	}
	if (getGame()->player->transform->position.y < this->tiledMap->gameObjects["Range"][0]->transform->position.y) {
		getGame()->sceneManager->setActiveScene("Scene18");
	}
}
