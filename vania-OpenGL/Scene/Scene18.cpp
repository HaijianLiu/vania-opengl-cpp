
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene18::Scene18() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene18::~Scene18() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene18::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject", "./Maps/scene_Scene18-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "./Maps/scene_Scene18-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "./Maps/scene_Scene18-Camera.csv");
	this->tiledMap->loadMapData("Range", "./Maps/scene_Scene18-Range.csv");
	// enemy
	this->tiledMap->loadMapData("Flyer", "./Maps/scene_Scene18-Flyer.csv");
	this->tiledMap->loadMapData("Ghost", "./Maps/scene_Scene18-Ghost.csv");
	this->tiledMap->loadMapData("Block", "./Maps/scene_Scene18-Block.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene18::set() {
	this->setBackground(1, "background_tissue_2nd");
	this->setBGM("map_mars");
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene18::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.y > this->tiledMap->gameObjects["Range"][2]->transform->position.y) {
		getGame()->sceneManager->setActiveScene("Scene17");
	}
	if (getGame()->player->transform->position.y < this->tiledMap->gameObjects["Range"][0]->transform->position.y) {
		getGame()->sceneManager->setActiveScene("Scene19");
	}
}
