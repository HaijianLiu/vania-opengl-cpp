
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene07::Scene07() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene07::~Scene07() {

}


/*------------------------------------------------------------------------------
< load > in Scene start() before GameObject start()
------------------------------------------------------------------------------*/
void Scene07::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject2", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene07-BackGround2.csv");
	this->tiledMap->loadMapData("TileObject", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene07-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene07-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene07-Camera.csv");
	this->tiledMap->loadMapData("Range", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene07-Range.csv");
	// enemy
	this->tiledMap->loadMapData("Block", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene07-Block.csv");
	// item
	this->tiledMap->loadMapData("Orb", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene07-Orb.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start() after GameObject start()
------------------------------------------------------------------------------*/
void Scene07::set() {
	this->setBackground(0, "background_forest_0");
	this->setBackground(1, "background_forest_2nd");
	this->setBGM("map_normal");
}


/*------------------------------------------------------------------------------
< check > in SceneManager update() before Scene update()
------------------------------------------------------------------------------*/
void Scene07::check() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x > this->tiledMap->gameObjects["Range"][2]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene08");
	}
	if (getGame()->player->transform->position.y > this->tiledMap->gameObjects["Range"][3]->transform->position.y) {
		getGame()->sceneManager->setActiveScene("Scene06");
	}
	if (getGame()->player->transform->position.y < this->tiledMap->gameObjects["Range"][0]->transform->position.y) {
		getGame()->sceneManager->setActiveScene("Scene12");
	}
}
