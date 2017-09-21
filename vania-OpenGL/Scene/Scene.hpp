
#ifndef Scene_hpp
#define Scene_hpp

class Scene {
private:
	// Scene GameObjects and Colliders
	std::vector<GameObject*> gameObjects;
	std::vector<BoxCollider*> colliders;

public:
	// tiled map
	TiledMap* tiledMap;

	// BackGround Object
	UIObject* backGround2nd;
	UIObject* backGround4th;

	// Frame Delay
	bool frameSkip = true; // skip the first frame

	// Constructors
	Scene();
	virtual ~Scene();

	void start();
	void update();

	virtual void load() = 0;
	virtual void end() = 0;
	virtual void reset() = 0;
	virtual void clear() = 0;

	void fixCamera(const char* name);

	bool checkCollision(BoxCollider* a, BoxCollider* b);
	void checkCollider();
};


#endif /* Scene_hpp */
