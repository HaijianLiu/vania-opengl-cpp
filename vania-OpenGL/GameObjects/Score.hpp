
#ifndef Score_hpp
#define Score_hpp

class Score : public GameObject {
private:

public:
	// GameObject
	std::vector<UIObject*> numbers;

	// Score
	unsigned int score = 0;
	unsigned int willAddScore = 0;

	// Spec
	glm::vec2 offset = glm::vec2(140.0f,105.0f);
	glm::vec2 size = glm::vec2(9.0f,7.0f);
	unsigned int max = 6;

	// Constructors
	Score();
	~Score();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);

	void addOne(unsigned int i);
	void willAdd(unsigned int i);
};

#endif /* Score_hpp */
