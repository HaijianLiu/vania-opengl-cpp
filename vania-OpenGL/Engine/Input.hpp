
#ifndef Input_hpp
#define Input_hpp

class Input {
private:
	Window* window;

	Input();
	~Input();

public:
	static Input* getInstance();
	void callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	// get button action
	bool getButtonPress(int button);
};

#endif /* Input_hpp */
