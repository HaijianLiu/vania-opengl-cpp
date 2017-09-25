
#ifndef DamageZone_hpp
#define DamageZone_hpp

class DamageZone : public GameObject {
private:

public:
	// Collider
	BoxCollider* collider;

	// Constructors
	DamageZone();
	~DamageZone();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);
};

#endif /* DamageZone_hpp */
