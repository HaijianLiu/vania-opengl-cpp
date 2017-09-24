
#ifndef ColliderObject_hpp
#define ColliderObject_hpp

class ColliderObject : public GameObject {
private:

public:
	// Collider
	BoxCollider* collider;

	// Constructors
	ColliderObject();
	~ColliderObject();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);
};

#endif /* ColliderObject_hpp */
