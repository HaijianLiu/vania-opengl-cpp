
#ifndef BossDeathBite_hpp
#define BossDeathBite_hpp

class BossDeathBite : public GameObject {
private:

public:
	// Collider
	BoxCollider* collider;
	// Animation
	Animation* animAppear;
	Animation* animDisappear;
	Animation* animBite;

	// Target
	GameObject* target;

	// Parameter
	float lastTime = 10.0f;
	float biteTime = 1.0f;

	// Status
	bool appearing = false;
	bool bite = false;
	float lastAppear = 0;
	float lastBite = 0;
	float appearTime = 1.0f;

	// Constructors
	BossDeathBite();
	~BossDeathBite();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);
	void reset();

	// Functions
	void appear();
};

#endif /* BossDeathBite_hpp */
