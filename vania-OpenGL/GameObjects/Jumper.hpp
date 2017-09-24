
#ifndef Jumper_hpp
#define Jumper_hpp

class Jumper : public GameObject {
private:

public:
	// Collider
	BoxCollider* collGroundCheck;
	BoxCollider* collCeilingCheck;
	BoxCollider* collHorizonCheck;
	// Animation
	Animation* animIdle;
	Animation* animJump;

	// GameObject
	GameObject* target;
	Orb* orb;
	float score = 100.0f;

	// Parameter
	float hp = 100.0f;
	float gravity = 9.8f;
	float speed = 0.5f;
	float jumpPower = 4.0f;
	float jumpColdDown = 1.0f;

	// status
	bool right = false;
	bool air = true;
	float verticalSpeed = 0.0f;
	float lastJump = 0;

	// Constructors
	Jumper ();
	~Jumper();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);
	void reset();
};

#endif /* Jumper_hpp */
