
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene02::Scene02() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene02::~Scene02() {

}


/*------------------------------------------------------------------------------
< load > in Scene start()
------------------------------------------------------------------------------*/
void Scene02::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject2", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene02-BackGround2.csv");
	this->tiledMap->loadMapData("TileObject", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene02-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene02-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene02-Camera.csv");
	this->tiledMap->loadMapData("Range", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene02-Range.csv");
	// check point
	this->tiledMap->loadMapData("Player", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene02-Player.csv");
	// enemy
	// this->tiledMap->loadMapData("Flyer", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene02-Flyer.csv");
	// item
	this->tiledMap->loadMapData("Orb", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene02-Orb.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start()
------------------------------------------------------------------------------*/
void Scene02::set() {
	// BackGround Object
	this->backGround2nd->sprite->texture = getGame()->resources->getTexture("background_2nd");
	this->backGround4th->sprite->texture = getGame()->resources->getTexture("background_4th");
	this->backGround2nd->sprite->setSlice(0.0f,0.0f,SCREEN_WIDTH,SCREEN_HEIGHT);
	this->backGround4th->sprite->setSlice(0.0f,0.0f,SCREEN_WIDTH,SCREEN_HEIGHT);
	this->backGround2nd->active = true;
	this->backGround4th->active = true;
}


/*------------------------------------------------------------------------------
< end > before Scene update()
------------------------------------------------------------------------------*/
void Scene02::end() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x < this->tiledMap->gameObjects["Range"][0]->transform->position.x) {
		if (distancePow(getGame()->player->transform->position, this->tiledMap->gameObjects["Range"][0]->transform->position) < 1.0f) {
			getGame()->sceneManager->setActiveScene("Scene01");
		}
		else {
			getGame()->sceneManager->setActiveScene("Scene03");
		}
	}
}


/*------------------------------------------------------------------------------
< reset > in SceneManager setActiveScene()
------------------------------------------------------------------------------*/
void Scene02::reset() {
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
void Scene02::clear() {

}
