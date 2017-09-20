
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene00::Scene00() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene00::~Scene00() {

}


/*------------------------------------------------------------------------------
< load > in Scene start()
------------------------------------------------------------------------------*/
void Scene00::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	this->tiledMap->loadMapData("Player", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene00-Player.csv");
	this->tiledMap->loadMapData("ColliderObject", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene00-Ground.csv");
	this->tiledMap->loadMapData("TileObject", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene00-BackGround.csv");
	this->tiledMap->loadMapData("CameraRange", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene00-Camera.csv");
	this->tiledMap->loadMapData("Crab", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene00-Crab.csv");
	this->tiledMap->loadMapData("Orb", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene00-Orb.csv");
}


/*------------------------------------------------------------------------------
< end >
------------------------------------------------------------------------------*/
void Scene00::end() {

}


/*------------------------------------------------------------------------------
< reset > in SceneManager setActiveScene()
------------------------------------------------------------------------------*/
void Scene00::reset() {
	// frameDelay
	this->frameSkip = true;
	// Player
	if (this->tiledMap->mapDatas["Player"].size() != 0 && !getGame()->player->active) {
		this->tiledMap->setPosition(getGame()->player, this->tiledMap->mapDatas["Player"][0].x);
		getGame()->player->active = true;
		getGame()->camera->target = getGame()->player;
	}
}


/*------------------------------------------------------------------------------
< clear >
------------------------------------------------------------------------------*/
void Scene00::clear() {

}
