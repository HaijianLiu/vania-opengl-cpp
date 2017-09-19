
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
< start >
------------------------------------------------------------------------------*/
void Scene00::loadScene() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	Scene::loadMapData("ColliderObject", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene00-Ground.csv");
	Scene::loadMapData("TileObject", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene00-BackGround.csv");
	Scene::loadMapData("CameraRange", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene00-Camera.csv");

	Scene::loadMapData("Player", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene00-Player.csv");
	Scene::setPosition(getGame()->player, this->mapDatas["Player"][0].x);
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void Scene00::endScene() {

}
