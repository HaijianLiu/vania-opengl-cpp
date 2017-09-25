
#ifndef BossCore_hpp
#define BossCore_hpp

class BossCore : public GameObject {
private:

public:
	// GameObject
	GameObject* parent;
	GameObject* target;

	// Parameter
	float radius = 0.1f;
	float speed = 0.5f;

	// Constructors
	BossCore ();
	~BossCore();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);

	// Functions
	void followTarget();
	void lookRight();
	void lookLeft();
};

#endif /* BossCore_hpp */
