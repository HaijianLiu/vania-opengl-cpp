
#ifndef Player_hpp
#define Player_hpp

class Player : public GameObject {
private:

public:

	// Constructors
	Player ();
	~Player();

	// virtual Functions
	void start();
	void update();
	// void OnTriggerEnter(BoxCollider* other);
	void fixedUpdate();
};

#endif /* Player_hpp */
