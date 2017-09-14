
#ifndef Sprite_hpp
#define Sprite_hpp

class Sprite {
private:
	Resources* resources;
public:
	Shader* shader;
	Texture* texture;

	bool flipX = false;

	Sprite();
	~Sprite();

	void start();
};

#endif /* Sprite_hpp */
