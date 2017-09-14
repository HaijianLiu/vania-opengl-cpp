
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

	bool flipX = false;

	Sprite();
	~Sprite();

	void start();
	void draw();
};

#endif /* Sprite_hpp */
