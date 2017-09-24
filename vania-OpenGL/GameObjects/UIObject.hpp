
#ifndef UIObject_hpp
#define UIObject_hpp

class UIObject : public GameObject {
private:

public:
	// offset
	glm::vec2 offset;

	bool destroy = false;

	// Constructors
	UIObject(float offsetX, float offsetY, float sizeX, float sizeY);
	~UIObject();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);
	void UIUpdate();
};

#endif /* UIObject_hpp */
