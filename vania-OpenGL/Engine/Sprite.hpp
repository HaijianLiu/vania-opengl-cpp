
#ifndef Sprite_hpp
#define Sprite_hpp

class Sprite {
private:
	Quad* quad;

public:
	// this gameObject
	GameObject* gameObject;
	// sprite member
	Shader* shader;
	Texture* texture;
	// slice uniform
	glm::mat3 slice = glm::mat3(1.0f);

	bool flipX = false;

	Sprite();
	~Sprite();

	void start();
	void draw();

	void setSlice(float offsetX, float offsetY, float sizeX, float sizeY);
};

#endif /* Sprite_hpp */
