
#ifndef Block_hpp
#define Block_hpp

class Block : public GameObject {
private:

public:
	// Collider
	BoxCollider* collider;

	// Parameter
	float hp = 100.0f;
	float destroySpeed = 100.0f;

	// Constructors
	Block();
	~Block();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);
	void reset();
};

#endif /* Block_hpp */
