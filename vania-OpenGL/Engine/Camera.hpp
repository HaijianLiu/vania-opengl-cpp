
#ifndef Camera_hpp
#define Camera_hpp

class Camera {
private:

public:
	// Camera Position
	glm::vec3 position;
	glm::vec3 target;

	Camera();
	~Camera();
};

#endif /* Camera_hpp */
