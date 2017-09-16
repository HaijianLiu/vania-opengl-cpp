
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene::Scene() {
	// Camera
	this->camera = getCamera();
	// Timer
	this->timer = getTimer();

	this->resources = getResources();

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
}


/*------------------------------------------------------------------------------
< Start >

0			0.16 			0.32			0.48
0.16
0.32
0.48
------------------------------------------------------------------------------*/
void Scene::start() {
	Scene::loadMapData("TileObject", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_test.csv");

	std::vector<GameObject*> objects;
	for (unsigned int i = 0; i < this->mapDatas["TileObject"].size(); i++) {
		objects.push_back(new TileObject());
		objects.back()->preStart();
		objects.back()->sprite->texture = this->resources->getTexture("tilesets");
		Scene::setTile(objects.back(), this->mapDatas["TileObject"][i].x, this->mapDatas["TileObject"][i].y);
	}
	this->sceneGameObjects.insert(std::make_pair("TileObject", objects));

	// Get GameObject && Get Collider
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

	for (unsigned int i = 0; i < this->gameObjects.size(); i++) {
		if (this->gameObjects[i]->active) {
			this->gameObjects[i]->start();
		}
	}
	// for (unsigned int i = 0; i < this->sceneGameObjects["TileObject"].size(); i++) {
	// 	this->sceneGameObjects["TileObject"][i]->sprite->texture = this->resources->getTexture("tilesets");
	// }

}


/*------------------------------------------------------------------------------
< Update >
------------------------------------------------------------------------------*/
void Scene::update() {
	// Update GameObject && CheckCollider && Update Collider (_DEBUG)
	for (unsigned int i = 0; i < this->gameObjects.size(); i++) {
		if (this->gameObjects[i]->active) {
			this->gameObjects[i]->update();
		}
	}
	checkCollider();
	this->camera->update();
	for (unsigned int i = 0; i < this->gameObjects.size(); i++) {
		if (this->gameObjects[i]->active) {
			this->gameObjects[i]->fixedUpdate();
		}
	}
}


/*------------------------------------------------------------------------------
< Draw >
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
< LoadMapData >
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
