
#ifndef Player_hpp
#define Player_hpp

class Player : public GameObject {
private:
	Input* input;

public:

	// Collider

	// Animation
	Animation* animRun;
	// offset Object

	// Bullet

	// UIObject

	// Orb

	// Parameter
	float hp = 100.0f;
	float gravity = 9.8f;
	float speed = 1.0f;
	float jumpPower = 4.0f;

	// status
	bool move = false;
	bool right = true;
	bool air = true;
	bool shoot = false;
	bool duck = false;
	bool hurt = false;
	bool freeze = false;


	// Constructors
	Player ();
	~Player();

	// virtual Functions
	void start();
	void update();
	// void OnTriggerEnter(BoxCollider* other);
	void fixedUpdate();
};

#endif /* Player_hpp */
