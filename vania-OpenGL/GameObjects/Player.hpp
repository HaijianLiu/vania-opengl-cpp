
#ifndef Player_hpp
#define Player_hpp

class Player : public GameObject {
private:
	// Input
	Input* input;

public:
	// Collider
	BoxCollider* collGroundCheck;
	BoxCollider* collCeilingCheck;
	BoxCollider* collHorizonCheck;
	// Animation
	Animation* animIdle;
	Animation* animShoot;
	Animation* animRun;
	Animation* animJump;
	Animation* animDuck;
	Animation* animDuckShoot;
	Animation* animHurt;
	// offset Object
	OffsetObject* leftShoot;
	OffsetObject* rightShoot;
	OffsetObject* leftDuckShoot;
	OffsetObject* rightDuckShoot;
	// Bullet
	std::vector<Bullet*> bullets;
	// UIObject
	// UIObject* uiEnergyBG;
	// UIObject* uiEnergy;
	// Score* score;
	// Orb
	Orb* orb;

	// Parameter
	float hp = 100.0f;
	float gravity = 9.8f;
	float speed = 1.0f;
	float jumpPower = 4.0f;
	float shootColdDown = 0.1f;
	float hurtColdDown = 1.0f;
	float hurtFreeze = 0.3f;
	float freezeColdDown = 5.0f;
	float backSpeed = 0.5f;
	float shootEnergy = 20.0f;
	float energyRegain = 20.0f;
	float bulletDamage = 40.0f;

	// status
	bool move = false;
	bool right = true;
	bool air = false;
	bool shoot = false;
	bool duck = false;
	bool hurt = false;
	bool dead = false;
	bool freeze = false;
	float verticalSpeed = 0.0f;
	float shootDuration = 0.2f;
	float deathDelay = 1.0f;
	float gameOverDelay = 3.0f;
	float lastGameOver = 0;
	float lastShoot = 0;
	float lastHurt = 0;
	float lastFreeze = 0;


	// Constructors
	Player ();
	~Player();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);
	void fixedUpdate();
};

#endif /* Player_hpp */
