
#ifndef SceneManager_hpp
#define SceneManager_hpp

class SceneManager {
private:
	const char* activeScene;
	std::map<const char*, Scene*> scenes;
	void createScene(const char* name, Scene* scene);

public:
	// Constructors
	SceneManager();
	~SceneManager();

	void start();
	void update();

};

#endif /* SceneManager_hpp */
