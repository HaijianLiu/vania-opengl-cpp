
#ifndef SceneTitle_hpp
#define SceneTitle_hpp

class SceneTitle : public Scene {
private:
	// Input
	Input* input;

public:
	// UIObject
	UIObject* uiTitleBG;
	UIObject* uiTitle;
	UIObject* uiTitleStart;
	UIObject* uiTitleOption;
	UIObject* uiTitleCredits;
	UIObject* uiTitleCreditsText;
	UIObject* uiTitleOptionText;
	UIObject* uiTitlePress;

	bool enter = false;
	int selected = 0;
	float lastEnter = 0.0f;
	float enterDelay = 2.0f;

	int counter = 0;

	SceneTitle();
	~SceneTitle();

	// virtual Functions
	void load();
	void set();
	void check();
};

#endif /* SceneTitle_hpp */
