
#ifndef Camera_hpp
#define Camera_hpp

class Camera {
private:

public:
	Camera();
	~Camera();

	// Camera Position
	glm::vec3 position;
	glm::vec3 cameraFront, cameraUp, cameraRight;
	glm::vec3 worldFront, worldUp, worldRight;
	// Eular Angles
	float yaw;
	float pitch;
	// Moment options
	float moveSpeed;
	float rotateSensitivity;

	// Camera Attributes
	float field; // Degree° Field of View
	float ratio;
	float rangeStart;
	float rangeEnd;

	void update();

	void translate(float x, float y, float z);
	void setUpside(glm::vec3 up);
	void setField(float degree);
	void setRatio(float ratio);
	void setRange(float start, float end);

	glm::mat4 getMatrixProjection();
	glm::mat4 getMatrixView();
	glm::vec3 getPosition();
};

#endif /* Camera_hpp */
