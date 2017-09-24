
#ifndef CheckPoint_hpp
#define CheckPoint_hpp

class CheckPoint : public GameObject {
private:

public:
	// Collider
	BoxCollider* collider;

	// status
	bool check = false;

	// Constructors
	CheckPoint();
	~CheckPoint();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);
};

#endif /* CheckPoint_hpp */
