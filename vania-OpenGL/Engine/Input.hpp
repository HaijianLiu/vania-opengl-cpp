
#ifndef Input_hpp
#define Input_hpp

class Input {
private:
	Window* window;

	int keys[GLFW_KEY_LAST] = {GLFW_RELEASE};

	Input();
	~Input();

public:
	static Input* getInstance();
	void callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	// get button action
	bool getButtonPress(int button);
	bool getButtonTrigger(int button);
};

#endif /* Input_hpp */
