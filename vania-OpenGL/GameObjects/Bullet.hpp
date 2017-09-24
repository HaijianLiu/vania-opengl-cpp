
#ifndef Bullet_hpp
#define Bullet_hpp

class Bullet : public GameObject {
private:

public:
	// Collider
	BoxCollider* collider;

	// Parameter
	float speed = 3.0f;
	float lifeTime = 1.0f;

	// status
	bool right = true;
	glm::vec3 lastPosition = glm::vec3(0.0f, 0.0f, 0.0f);

	// Constructors
	Bullet();
	~Bullet();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);
};


#endif /* Bullet_hpp */
