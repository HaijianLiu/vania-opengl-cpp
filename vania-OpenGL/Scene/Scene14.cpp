
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene14::Scene14() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene14::~Scene14() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene14::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject2", "./Maps/scene_Scene14-BackGround2.csv");
	this->tiledMap->loadMapData("TileObject", "./Maps/scene_Scene14-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "./Maps/scene_Scene14-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "./Maps/scene_Scene14-Camera.csv");
	this->tiledMap->loadMapData("Range", "./Maps/scene_Scene14-Range.csv");
	// enemy
	this->tiledMap->loadMapData("Ghost", "./Maps/scene_Scene14-Ghost.csv");
	// check point
	this->tiledMap->loadMapData("Player", "./Maps/scene_Scene14-Player.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene14::set() {
	this->setBackground(1, "background_tissue_2nd");
	this->setBGM("map_mars");
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene14::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x > this->tiledMap->gameObjects["Range"][1]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene15");
	}
	if (getGame()->player->transform->position.x < this->tiledMap->gameObjects["Range"][2]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene13");
	}
}
