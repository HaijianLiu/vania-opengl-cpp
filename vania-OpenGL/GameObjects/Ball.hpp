
#ifndef Ball_hpp
#define Ball_hpp

class Ball : public GameObject {
private:

public:
	// Collider
	BoxCollider* collGroundCheck;
	BoxCollider* collCeilingCheck;
	BoxCollider* collHorizonCheck;

	// GameObject
	Orb* orb;
	float score = 150.0f;

	// Parameter
	float hp = 100.0f;
	float verticalSpeed = 1.0f;
	float horizonSpeed = 1.0f;

	// status
	bool up = false;
	bool right = false;

	// Constructors
	Ball ();
	~Ball();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);
	void reset();
};

#endif /* Ball_hpp */
