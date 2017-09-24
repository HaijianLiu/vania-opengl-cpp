
#ifndef SceneGameOver_hpp
#define SceneGameOver_hpp

class SceneGameOver : public Scene {
private:

public:
	// UIObject
	UIObject* uiGameOverText;

	float restartDelay = 3.0f;

	SceneGameOver();
	~SceneGameOver();

	// virtual Functions
	void load();
	void set();
	void check();
	void reset();
};

#endif /* SceneGameOver_hpp */
