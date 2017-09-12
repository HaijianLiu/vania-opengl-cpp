
#ifndef Transform_hpp
#define Transform_hpp

class Transform {
private:
	/* data */

public:
	glm::vec3 position = glm::vec3(0.0f,0.0f,0.0f);
	glm::vec3 scale = glm::vec3(1.0f,1.0f,0.0f);

	Transform();
	~Transform();
};

#endif /* Transform_hpp */
