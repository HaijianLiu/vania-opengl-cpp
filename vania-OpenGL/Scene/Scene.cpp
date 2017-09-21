
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene::Scene() {
	// TiledMap
	this->tiledMap = new TiledMap();
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene::~Scene() {
	// delete Map GameObjects
	delete this->tiledMap;
	delete this->backGround2nd;
	delete this->backGround4th;
}


/*------------------------------------------------------------------------------
< Start > after Resources start()
------------------------------------------------------------------------------*/
void Scene::start() {
	/* get GameObjects and Colliders in initial Game
	..............................................................................*/
	std::vector<GameObject*>* gpGameObjects = getGame()->getGameObjects();
	std::vector<BoxCollider*>* gpColliders = getGame()->getColliders();
	unsigned int startGameObjectsSize = gpGameObjects->size();
	unsigned int startCollidersSize = gpColliders->size();


	/* load Scene
	..............................................................................*/
	this->load();

	// BackGround Object
	this->backGround4th = new UIObject(0.0f,0.0f,SCREEN_WIDTH,SCREEN_HEIGHT);
	this->backGround2nd = new UIObject(0.0f,0.0f,SCREEN_WIDTH,SCREEN_HEIGHT);
	this->backGround4th->transform->position.z = 0.0f;
	this->backGround2nd->transform->position.z = 0.0f;

	/* create gameObjects
	..............................................................................*/
	for (std::map<const char*, std::vector<glm::i32vec2>>::iterator it = this->tiledMap->mapDatas.begin(); it != this->tiledMap->mapDatas.end(); it++) {
		this->tiledMap->createGameObject(it->first);
	}


	/* Get GameObject && Get Collider
	..............................................................................*/
	this->gameObjects = getGame()->copyGameObjects();
	this->colliders = getGame()->copyColliders();
	// reset global gameObjects
	unsigned int size;
	size = gpGameObjects->size() - startGameObjectsSize;
	for (int i = 0; i < size; i++) {
		gpGameObjects->pop_back();
	}
	size = gpColliders->size() - startCollidersSize;
	for (int i = 0; i < size; i++) {
		gpColliders->pop_back();
	}


	/* gameObjects defaultStart() & start()
	..............................................................................*/
	for (unsigned int i = this->gameObjects.size(); i > 0; i--) {
		this->gameObjects[i-1]->defaultStart();
		this->gameObjects[i-1]->start();
	}


	/* set objects position & slice (after given a texture)
	..............................................................................*/
	for (std::map<const char*, std::vector<glm::i32vec2>>::iterator it = this->tiledMap->mapDatas.begin(); it != this->tiledMap->mapDatas.end(); it++) {
		this->tiledMap->setGameObject(it->first);
	}

	// BackGround Object
	this->backGround2nd->sprite->texture = getGame()->resources->getTexture("background_2nd");
	this->backGround4th->sprite->texture = getGame()->resources->getTexture("background_4th");
	this->backGround2nd->sprite->setSlice(0.0f,0.0f,SCREEN_WIDTH,SCREEN_HEIGHT);
	this->backGround4th->sprite->setSlice(0.0f,0.0f,SCREEN_WIDTH,SCREEN_HEIGHT);
}


/*------------------------------------------------------------------------------
< Update > GameObject update() onTriggerEnter() fixedUpdate() draw()
------------------------------------------------------------------------------*/
void Scene::update() {
	for (unsigned int i = 0; i < this->gameObjects.size(); i++) {
		if (this->gameObjects[i]->active) {
			this->gameObjects[i]->update();
		}
	}

	Scene::checkCollider();

	for (unsigned int i = 0; i < this->gameObjects.size(); i++) {
		if (this->gameObjects[i]->active) {
			this->gameObjects[i]->fixedUpdate();
		}
	}

	Scene::fixCamera("CameraRange");

	for (unsigned int i = 0; i < this->gameObjects.size(); i++) {
		if (this->gameObjects[i]->active) {
			this->gameObjects[i]->UIUpdate();
		}
	}

	// backGround2nd && backGround4th
	this->backGround2nd->sprite->setSlice(0.5f * getGame()->camera->position.x * UNIT_TO_PIXEL, 0.5f * getGame()->camera->position.y * UNIT_TO_PIXEL, SCREEN_WIDTH, SCREEN_HEIGHT);

	for (unsigned int i = this->gameObjects.size(); i > 0; i--) {
		if (this->gameObjects[i-1]->active && this->gameObjects[i-1]->visible) {
			this->gameObjects[i-1]->draw();
		}
	}

}


/*------------------------------------------------------------------------------
< CheckCollision >
------------------------------------------------------------------------------*/
bool Scene::checkCollision(BoxCollider* a, BoxCollider* b) {
	// Collision x-axis?
	bool collisionX =
		a->gameObject->transform->position.x + a->offset.x + a->halfSize.x * PIXEL_TO_UNIT >
		b->gameObject->transform->position.x + b->offset.x - b->halfSize.x * PIXEL_TO_UNIT
		&&
		a->gameObject->transform->position.x + a->offset.x - a->halfSize.x * PIXEL_TO_UNIT <
		b->gameObject->transform->position.x + b->offset.x + b->halfSize.x * PIXEL_TO_UNIT;
	// Collision y-axis?
	bool collisionY =
		a->gameObject->transform->position.y + a->offset.y + a->halfSize.y * PIXEL_TO_UNIT >
		b->gameObject->transform->position.y + b->offset.y - b->halfSize.y * PIXEL_TO_UNIT
		&&
		a->gameObject->transform->position.y + a->offset.y - a->halfSize.y * PIXEL_TO_UNIT <
		b->gameObject->transform->position.y + b->offset.y + b->halfSize.y * PIXEL_TO_UNIT;
	// Collision only if on both axes
	return collisionX && collisionY;
}
void Scene::checkCollider() {
	for (unsigned int i = 0; i < this->colliders.size(); i++) {
		if (this->colliders[i]->trigger && this->colliders[i]->gameObject->active && this->colliders[i]->active) {
			for (unsigned int j = 0; j < this->colliders.size(); j++) {
				bool collision = checkCollision(this->colliders[i],this->colliders[j]);
				if (i != j && collision && this->colliders[j]->gameObject->active && this->colliders[j]->active) {
					this->colliders[i]->enter = true;
					this->colliders[i]->gameObject->onTriggerEnter(this->colliders[j]);
					this->colliders[i]->enter = false;
					this->colliders[j]->enter = true;
					this->colliders[j]->gameObject->onTriggerEnter(this->colliders[i]);
					this->colliders[j]->enter = false;
				}
			}
		}
	}
}



/*------------------------------------------------------------------------------
< fix Camera > after Camera updatePosition() before Camera updateUniform()
------------------------------------------------------------------------------*/
void Scene::fixCamera(const char* name) {
	Camera* camera = getGame()->camera;

	camera->updatePosition();

	if (this->tiledMap->gameObjects.find(name) != this->tiledMap->gameObjects.end()) {
		if (this->tiledMap->gameObjects[name].size() == 1) {
			camera->position.x = this->tiledMap->gameObjects[name][0]->transform->position.x;
			camera->position.y = this->tiledMap->gameObjects[name][0]->transform->position.y;
		}
		if (this->tiledMap->gameObjects[name].size() == 2) {
			if (camera->position.x <= this->tiledMap->gameObjects[name][0]->transform->position.x) {
				camera->position.x = this->tiledMap->gameObjects[name][0]->transform->position.x;
			}
			if (camera->position.x > this->tiledMap->gameObjects[name][1]->transform->position.x) {
				camera->position.x = this->tiledMap->gameObjects[name][1]->transform->position.x;
			}
			if (camera->position.y <= this->tiledMap->gameObjects[name][0]->transform->position.y) {
				camera->position.y = this->tiledMap->gameObjects[name][0]->transform->position.y;
			}
			if (camera->position.y > this->tiledMap->gameObjects[name][1]->transform->position.y) {
				camera->position.y = this->tiledMap->gameObjects[name][1]->transform->position.y;
			}
		}
	}

	camera->updateUniform();
}
