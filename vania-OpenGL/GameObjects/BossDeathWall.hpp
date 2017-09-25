
#ifndef BossDeathWall_hpp
#define BossDeathWall_hpp

class BossDeathWall : public GameObject {
private:

public:
	// Collider
	BoxCollider* collider;

	// Constructors
	BossDeathWall();
	~BossDeathWall();

	// Parameter
	float speed = 1.0f;
	float maxArea = 2.0f;

	// status
	glm::vec3 startPosition = glm::vec3(0.0f, 0.0f, 0.0f);
	bool right = true;
	float maxDistance = 0.32f;

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);

	// Functions
	void forward();
	void deathArea(bool right);
};

#endif /* BossDeathWall_hpp */
