
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
TiledMap::TiledMap() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
TiledMap::~TiledMap() {

}


/*------------------------------------------------------------------------------
< loadMapData >
------------------------------------------------------------------------------*/
bool TiledMap::loadMapData(const char* name, const char* path) {
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
void TiledMap::createGameObject(const char* name) {
	std::vector<GameObject*> objects;
	for (unsigned int i = 0; i < this->mapDatas[name].size(); i++) {
		if (name == "TileObject") objects.push_back(new TileObject());
		if (name == "TileObject2") objects.push_back(new TileObject());
		else if (name == "ColliderObject") objects.push_back(new ColliderObject());
		else if (name == "CameraRange") objects.push_back(new NoneObject());
		else if (name == "Range") objects.push_back(new NoneObject());
		else if (name == "Player") objects.push_back(new CheckPoint());
		else if (name == "Orb") objects.push_back(new Orb());
		else if (name == "Block") objects.push_back(new Block());
		else if (name == "Crab") objects.push_back(new Crab());
		else if (name == "AI") objects.push_back(new AIObject());
	}
	this->gameObjects.insert(std::make_pair(name, objects));
}


/*------------------------------------------------------------------------------
< set GameObject > use it after GameObject has a texture
------------------------------------------------------------------------------*/
void TiledMap::setGameObject(const char* name) {
	for (unsigned int i = 0; i < this->gameObjects[name].size(); i++) {
		if (name == "TileObject" || name == "TileObject2" || name == "ColliderObject" || name == "CameraRange" || name == "AI") {
			TiledMap::setTile(this->gameObjects[name][i], this->mapDatas[name][i].x, this->mapDatas[name][i].y);
		}
		else {
			TiledMap::setPosition(this->gameObjects[name][i], this->mapDatas[name][i].x);
		}
	}
}


/*------------------------------------------------------------------------------
< set Tile > use it after GameObject has a texture
------------------------------------------------------------------------------*/
void TiledMap::setTile(GameObject* gameObject, int mapID, int tileID) {
	gameObject->transform->position.x = mapID % this->mapSize.x * PIXEL_TO_UNIT * this->tileSize;
	gameObject->transform->position.y = mapID / this->mapSize.x * PIXEL_TO_UNIT * this->tileSize;
	gameObject->transform->scale = glm::vec3(this->tileSize + 1.0f, this->tileSize + 1.0f, 1.0f);
	gameObject->sprite->setSlice(tileID % this->tilesetsSize.x * this->tileSize , tileID / this->tilesetsSize.x * this->tileSize, this->tileSize, this->tileSize);
}


/*------------------------------------------------------------------------------
< set position >
------------------------------------------------------------------------------*/
void TiledMap::setPosition(GameObject* gameObject, int mapID) {
	gameObject->transform->position.x = mapID % this->mapSize.x * PIXEL_TO_UNIT * this->tileSize;
	gameObject->transform->position.y = mapID / this->mapSize.x * PIXEL_TO_UNIT * this->tileSize;
}


void TiledMap::reset() {
	// player
	if (this->mapDatas.find("Player") != this->mapDatas.end() && !getGame()->player->active) {
		TiledMap::setPosition(getGame()->player, this->mapDatas["Player"][0].x);
		getGame()->player->reset();
		getGame()->camera->target = getGame()->player;
	}
	for (std::map<const char*, std::vector<GameObject*>>::iterator it = this->gameObjects.begin(); it != this->gameObjects.end(); it++) {
		if (it->first != "TileObject" && it->first != "TileObject2" && it->first != "ColliderObject" && it->first != "CameraRange" && it->first != "Range" && it->first != "Player" && it->first != "Orb" && it->first != "Item") {
			for (unsigned int i = 0; i < it->second.size(); i++) {
				TiledMap::setPosition(it->second[i], this->mapDatas[it->first][i].x);
				it->second[i]->reset();
			}
		}
	}
}
