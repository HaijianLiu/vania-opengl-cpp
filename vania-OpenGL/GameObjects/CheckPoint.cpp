
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
CheckPoint::CheckPoint() {
	// GameObject setting
	this->transform->position.z = 1.0f;
	// scale in real pixel
	this->transform->scale = glm::vec3(32.0f,32.0f,1.0f);
	// Collider (this,offsetX,offsetY,sizeX,sizeY) size is in real pixel && Collider is trigger ?
	this->collider = new BoxCollider(this,0.0f,0.0f,32.0f,32.0f);
	this->collider->tag = "check_point";
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
CheckPoint::~CheckPoint() {
	// delete objects
	delete this->collider;
}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void CheckPoint::start() {
	// set sprite texture and slice | Animation start
	this->sprite->texture = getGame()->resources->getTexture("map_check_point");
	this->sprite->setSlice(32.0f,0.0f,32.0f,32.0f);
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void CheckPoint::update() {

}


/*------------------------------------------------------------------------------
< onTriggerEnter >
------------------------------------------------------------------------------*/
void CheckPoint::onTriggerEnter(BoxCollider* other) {
	if (other->tag == "player" && !this->check) {
		for (std::map<const char*, Scene*>::iterator it = getGame()->sceneManager->scenes.begin(); it != getGame()->sceneManager->scenes.end(); it++) {
			if (it->second->tiledMap->gameObjects.find("Player") != it->second->tiledMap->gameObjects.end()) {
				CheckPoint* otherCheckPoint = dynamic_cast<CheckPoint*>(it->second->tiledMap->gameObjects["Player"][0]);
				otherCheckPoint->check = false;
				otherCheckPoint->sprite->setSlice(32.0f,0.0f,32.0f,32.0f);
			}
		}
		this->check = true;
		getGame()->sceneManager->checkedScene = getGame()->sceneManager->activeScene;
		this->sprite->setSlice(0.0f,0.0f,32.0f,32.0f);
		getGame()->resources->getAudio("map_check_point")->play();
	}
}




/*------------------------------------------------------------------------------
< fixedUpdate >
------------------------------------------------------------------------------*/
void CheckPoint::fixedUpdate() {

}
