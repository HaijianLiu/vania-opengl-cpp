
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Game::Game() {
	// create engine objects
	this->timer = new Timer();
	this->camera = new Camera();
	this->resources = new Resources();
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Game::~Game() {
	delete this->timer;
	delete this->camera;
	delete this->resources;
	delete this->sceneManager;
	delete this->player;
}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void Game::start() {
	// create GameObjects
	this->player = new Player();
	this->camera->target = this->player;
	this->sceneManager = new SceneManager();

	this->timer->start();
	this->resources->start();
	this->sceneManager->start();
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void Game::update() {
	this->timer->update();
	this->sceneManager->update();
}


/*------------------------------------------------------------------------------
< get functions >
------------------------------------------------------------------------------*/
std::vector<GameObject*>* Game::getGameObjects() {
	return &this->gameObjects;
}
std::vector<BoxCollider*>* Game::getColliders() {
	return &this->colliders;
}
std::vector<GameObject*> Game::copyGameObjects() {
	return this->gameObjects;
}
std::vector<BoxCollider*> Game::copyColliders() {
	return this->colliders;
}
