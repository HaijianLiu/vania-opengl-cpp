
#ifndef Camera_hpp
#define Camera_hpp

class Camera {
private:
	Window* window;

public:
	// Camera Position
	glm::vec3 position = glm::vec3(0.0f,0.0f,0.0f);

	// matrix uniform
	glm::mat4 projection, view;

	Camera();
	~Camera();

	void update();
};

#endif /* Camera_hpp */
