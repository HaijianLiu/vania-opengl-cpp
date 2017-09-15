
#ifndef Sprite_hpp
#define Sprite_hpp

class Sprite {
private:
	Quad* quad;
	glm::mat3 matFlipX = {
		-1.0f,0.0f,0.0f,
		 0.0f,1.0f,0.0f,
		 1.0f,0.0f,1.0f,
	};

public:
	// this gameObject
	GameObject* gameObject;
	// sprite member
	Shader* shader;
	Texture* texture;
	// slice uniform
	glm::mat3 slice = glm::mat3(1.0f);
	// flip flag
	bool flipX = false;

	Sprite();
	~Sprite();

	void start();
	void draw();

	void setSlice(float offsetX, float offsetY, float sizeX, float sizeY);
};

#endif /* Sprite_hpp */
