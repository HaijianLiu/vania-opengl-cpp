
#ifndef Input_hpp
#define Input_hpp

class Input {
private:
	Window* window;

public:
	Input();
	~Input();

	bool getButtonPress(int button);
};

#endif /* Input_hpp */
