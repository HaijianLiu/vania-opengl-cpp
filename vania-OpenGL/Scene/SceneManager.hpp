
#ifndef SceneManager_hpp
#define SceneManager_hpp

class SceneManager {
private:
	void creatScene(const char* name, Scene* scene);

public:
	std::map<const char*, Scene*> scenes;

	// Constructors
	SceneManager();
	~SceneManager();

	void start();
	void update();

};

#endif /* SceneManager_hpp */
