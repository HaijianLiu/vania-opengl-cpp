
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene13::Scene13() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene13::~Scene13() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene13::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject2", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene13-BackGround2.csv");
	this->tiledMap->loadMapData("TileObject", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene13-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene13-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene13-Camera.csv");
	this->tiledMap->loadMapData("Range", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene13-Range.csv");
	// enemy
	this->tiledMap->loadMapData("Ghost", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene13-Ghost.csv");
	// item
	this->tiledMap->loadMapData("Orb", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene13-Orb.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene13::set() {
	this->setBackground(0, "background_forest_0");
	this->setBackground(1, "background_forest_2nd");
	this->setBGM("map_normal");
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene13::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x > this->tiledMap->gameObjects["Range"][0]->transform->position.x) {
		if (distancePow(getGame()->player->transform->position, this->tiledMap->gameObjects["Range"][0]->transform->position) < 1.0f) {
			getGame()->sceneManager->setActiveScene("Scene06");
		}
		else {
			getGame()->sceneManager->setActiveScene("Scene14");
		}
	}
}
