
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene23::Scene23() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene23::~Scene23() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene23::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject2", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene23-BackGround2.csv");
	this->tiledMap->loadMapData("TileObject", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene23-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene23-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene23-Camera.csv");
	this->tiledMap->loadMapData("Range", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene23-Range.csv");
	// item
	this->tiledMap->loadMapData("Orb", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene23-Orb.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene23::set() {
	this->setBackground(0, "background_forest_0");
	this->setBackground(1, "background_forest_2nd");
	this->setBGM("map_mars");
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene23::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x > this->tiledMap->gameObjects["Range"][0]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene22");
	}
	if (getGame()->player->transform->position.y > this->tiledMap->gameObjects["Range"][1]->transform->position.y) {
		getGame()->sceneManager->setActiveScene("Scene14");
	}
}
