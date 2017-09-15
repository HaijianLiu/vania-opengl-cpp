
#ifndef Animation_hpp
#define Animation_hpp

class Animation {
private:
	Timer* timer;
	Resources* resources;

public:
	Texture* texture;
	std::vector<glm::mat3> slices;

	const char* textureName;
	glm::vec2 divide;
	float sampleTime, lastCounterTime;

	glm::vec2 sliceSize;
	unsigned int sliceMax, counter, currentSlice;

	Animation(const char* textureName, float divideX, float divideY, float sampleTime);
	~Animation ();

	void start();
	void update(Sprite* sprite);
};

#endif /* Animation_hpp */
