
#ifndef BossBullet_hpp
#define BossBullet_hpp

class BossBullet : public GameObject {
private:

public:
	// Collider
	BoxCollider* collider;
	// Animation
	Animation* animation;

	// GameObject
	GameObject* target;

	// Constructors
	BossBullet();
	~BossBullet();

	// Parameter
	float hp = 40.0f;
	float speed = 0.3f;

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);
};

#endif /* BossBullet_hpp */
