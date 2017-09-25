
#ifndef Item_hpp
#define Item_hpp

class Item : public GameObject {
private:

public:
	// Collider
	BoxCollider* collider;

	// GameObject
	UIObject* info;

	// Constructors
	Item();
	~Item();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);
};

#endif /* Item_hpp */
