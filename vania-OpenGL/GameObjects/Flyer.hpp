
#ifndef Flyer_hpp
#define Flyer_hpp

class Flyer : public GameObject {
private:

public:
	// Collider
	BoxCollider* collHorizonCheck;
	// Animation
	Animation* animFlyer;

	// GameObject
	Orb* orb;
	float score = 75.0f;

	// Parameter
	float hp = 100.0f;
	float speed = 1.0f;

	// status
	bool right = false;
	bool air = true;

	// Constructors
	Flyer ();
	~Flyer();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);
	void reset();
};

#endif /* Flyer_hpp */
