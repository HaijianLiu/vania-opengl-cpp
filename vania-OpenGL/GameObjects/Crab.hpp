
#ifndef Crab_hpp
#define Crab_hpp

class Crab : public GameObject {
private:

public:
	// Collider
	BoxCollider* collGroundCheck;
	BoxCollider* collHorizonCheck;
	// Animation
	Animation* animWalk;

	// GameObject
	Orb* orb;
	float score = 50.0f;

	// Parameter
	float hp = 100.0f;
	float gravity = 9.8f;
	float speed = 0.3f;
	float jumpPower = 4.0f;

	// status
	bool right = false;
	bool air = true;
	float verticalSpeed = 0.0f;

	// Constructors
	Crab ();
	~Crab();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);
	void fixedUpdate();
};

#endif /* Crab_hpp */
