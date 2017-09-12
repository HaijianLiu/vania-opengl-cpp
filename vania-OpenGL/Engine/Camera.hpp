
#ifndef Camera_hpp
#define Camera_hpp

class Camera {
private:
	GLFWwindow* window;
	int screenWidth, screenHeight;

public:
	// Camera Position
	glm::vec3 position;
	glm::vec3 target;

	// matrix uniform
	glm::mat4 projection, view;

	Camera();
	~Camera();

	void update();
};

#endif /* Camera_hpp */
