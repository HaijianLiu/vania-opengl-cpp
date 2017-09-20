
#ifndef Orb_hpp
#define Orb_hpp

class Orb : public GameObject {
private:

public:
	// Collider
	BoxCollider* collider;

	// Constructors
	Orb();
	~Orb();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);
	void fixedUpdate();
};

#endif /* Orb_hpp */
