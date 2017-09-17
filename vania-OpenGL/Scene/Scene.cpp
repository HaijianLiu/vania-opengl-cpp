
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene::Scene() {
	// get start size
	this->gpGameObjects = getGameObjects();
	this->gpColliders = getColliders();
	this->startGameObjectsSize = this->gpGameObjects->size();
	this->startCollidersSize = this->gpColliders->size();
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene::~Scene() {
	// delete Map GameObjects
	deleteVectorMap(this->sceneGameObjects);
}


/*------------------------------------------------------------------------------
< Start > after Resources start()
------------------------------------------------------------------------------*/
void Scene::start() {
	/* loadMapData
	..............................................................................*/
	Scene::loadMapData("ColliderObject", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_test2.csv");
	Scene::loadMapData("TileObject", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_test.csv");


	/* create gameObjects
	..............................................................................*/
	createGameObject("ColliderObject");
	createGameObject("TileObject");


	/* Get GameObject && Get Collider
	..............................................................................*/
	this->gameObjects = copyGameObjects();
	this->colliders = copyColliders();
	// reset global gameObjects
	int size;
	size = this->gpGameObjects->size() - this->startGameObjectsSize;
	for (int i = 0; i < size; i++) {
		this->gpGameObjects->pop_back();
	}
	size = this->gpColliders->size() - this->startCollidersSize;
	for (int i = 0; i < size; i++) {
		this->gpColliders->pop_back();
	}

	/* gameObjects preStart() & start()
	..............................................................................*/
	for (unsigned int i = 0; i < this->gameObjects.size(); i++) {
		this->gameObjects[i]->defaultStart();
		this->gameObjects[i]->start();
	}

	/* set objects position & slice (after given a texture)
	..............................................................................*/
	setGameObject("ColliderObject");
	setGameObject("TileObject");
}


/*------------------------------------------------------------------------------
< Update > GameObject update() onTriggerEnter() fixedUpdate()
------------------------------------------------------------------------------*/
void Scene::update() {
	// Update GameObject && CheckCollider && Update Collider (_DEBUG)
	for (unsigned int i = 0; i < this->gameObjects.size(); i++) {
		if (this->gameObjects[i]->active) {
			this->gameObjects[i]->update();
		}
	}
	checkCollider();
	for (unsigned int i = 0; i < this->gameObjects.size(); i++) {
		if (this->gameObjects[i]->active) {
			this->gameObjects[i]->fixedUpdate();
		}
	}
}


/*------------------------------------------------------------------------------
< Draw > GameObject draw()
------------------------------------------------------------------------------*/
void Scene::draw() {
	// Draw GameObject && Draw Collider (_DEBUG)
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
< loadMapData >
------------------------------------------------------------------------------*/
bool Scene::loadMapData(const char* name, const char* path) {
	std::vector<glm::i32vec2> data;

	FILE* file = fopen(path,"rb");
	if (file == nullptr) return false;
	unsigned int counter = 0;
	int num;
	while (!feof(file)) {
		if(fscanf(file, "%d,", &num) == 1){
			if (num != -1) {
				data.push_back(glm::i32vec2(counter,num));
			}
			counter++;
		}
	}
	fclose(file);

	this->mapDatas.insert(std::make_pair(name, data));

	return true;
}


/*------------------------------------------------------------------------------
< create GameObject > createGameObject by name & size by data size
------------------------------------------------------------------------------*/
void Scene::createGameObject(const char* name) {
	std::vector<GameObject*> objects;
	for (unsigned int i = 0; i < this->mapDatas[name].size(); i++) {
		if (name == "TileObject") objects.push_back(new TileObject());
		else if (name == "ColliderObject") objects.push_back(new ColliderObject());
	}
	this->sceneGameObjects.insert(std::make_pair(name, objects));
}


/*------------------------------------------------------------------------------
< set GameObject > use it after GameObject has a texture
------------------------------------------------------------------------------*/
void Scene::setGameObject(const char* name) {
	for (unsigned int i = 0; i < this->sceneGameObjects[name].size(); i++) {
		Scene::setTile(this->sceneGameObjects[name][i], this->mapDatas[name][i].x, this->mapDatas[name][i].y);
	}
}


/*------------------------------------------------------------------------------
< set Tile > use it after GameObject has a texture
------------------------------------------------------------------------------*/
void Scene::setTile(GameObject* gameObject, int mapID, int tileID) {
	gameObject->transform->position.x = mapID % this->mapSize.x * PIXEL_TO_UNIT * this->tileSize;
	gameObject->transform->position.y = mapID / this->mapSize.x * PIXEL_TO_UNIT * this->tileSize;
	gameObject->transform->scale = glm::vec3(this->tileSize, this->tileSize, 1.0f);
	gameObject->sprite->setSlice(tileID % this->tilesetsSize.x * this->tileSize , tileID / this->tilesetsSize.x * this->tileSize, this->tileSize, this->tileSize);
}

void Scene::setPosition(GameObject* gameObject, int mapID) {
	// gameObject->transform->position.x = mapID % this->mapSize.x * PIXEL_TO_UNIT * this->tileSize;
	// gameObject->transform->position.y = mapID / this->mapSize.x * PIXEL_TO_UNIT * this->tileSize;
}
