
#ifndef AIObject_hpp
#define AIObject_hpp

class AIObject : public GameObject {
private:

public:
	// Collider
	BoxCollider* collider;

	// Constructors
	AIObject();
	~AIObject();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);
};

#endif /* AIObject_hpp */
