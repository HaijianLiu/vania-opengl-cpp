
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene19::Scene19() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene19::~Scene19() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene19::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject", "./Maps/scene_Scene19-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "./Maps/scene_Scene19-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "./Maps/scene_Scene19-Camera.csv");
	this->tiledMap->loadMapData("Range", "./Maps/scene_Scene19-Range.csv");
	// enemy
	this->tiledMap->loadMapData("Ball", "./Maps/scene_Scene19-Ball.csv");
	this->tiledMap->loadMapData("AI", "./Maps/scene_Scene19-AI.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene19::set() {
	this->setBackground(1, "background_tissue_2nd");
	this->setBGM("map_mars");
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene19::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x < this->tiledMap->gameObjects["Range"][0]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene20");
	}
	if (getGame()->player->transform->position.y > this->tiledMap->gameObjects["Range"][1]->transform->position.y) {
		getGame()->sceneManager->setActiveScene("Scene18");
	}
}
