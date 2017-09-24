
#ifndef Ghost_hpp
#define Ghost_hpp

class Ghost : public GameObject {
private:

public:
	// Collider
	BoxCollider* collider;
	// Animation
	Animation* animation;

	// GameObject
	GameObject* target;
	Orb* orb;
	float score = 125.0f;

	// Constructors
	Ghost();
	~Ghost();

	// Parameter
	float hp = 100.0f;
	float speed = 0.3f;

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);
	void reset();
};

#endif /* Ghost_hpp */
