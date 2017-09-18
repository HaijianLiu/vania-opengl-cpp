
#ifndef Scene_hpp
#define Scene_hpp

class Scene {
private:
	// global GameObjects and Colliders parameter
	std::vector<GameObject*>* gpGameObjects;
	std::vector<BoxCollider*>* gpColliders;
	unsigned int startGameObjectsSize;
	unsigned int startCollidersSize;

	// tiled map Setting
	int tileSize = 16;
	glm::i32vec2 mapSize = glm::i32vec2(225,90);
	glm::i32vec2 tilesetsSize = glm::i32vec2(384/16,320/16);

	// tiled map data
	std::map<const char*, std::vector<glm::i32vec2>> mapDatas;
	std::map<const char*, std::vector<GameObject*>> sceneGameObjects;

public:
	// Scene GameObjects and Colliders
	std::vector<GameObject*> gameObjects;
	std::vector<BoxCollider*> colliders;
	// Camera
	Camera* camera;

	// Frame Delay
	bool frameSkip = true; // skip the first frame


	Scene();
	virtual ~Scene();

	void start();
	void update();

	// Functions
	bool loadMapData(const char* name, const char* path);
	void createGameObject(const char* name);
	void setGameObject(const char* name);

	void setTile(GameObject* gameObject, int mapID, int tileID);
	void setPosition(GameObject* gameObject, int mapID);
	

	void fixCamera(const char* name);

	bool checkCollision(BoxCollider* a, BoxCollider* b);
	void checkCollider();


};


#endif /* Scene_hpp */
