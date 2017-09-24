
#ifndef AnimationObject_hpp
#define AnimationObject_hpp

class AnimationObject : public GameObject {
private:

public:
	// Animation
	Animation* animation;
	bool loop = false;

	// Constructors
	AnimationObject(const char* textureName, float sizeX, float sizeY, float divideX, float divideY, float sampleTime);
	~AnimationObject();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);
	void reset();
};

#endif /* AnimationObject_hpp */
