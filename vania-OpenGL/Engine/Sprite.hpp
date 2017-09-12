
#ifndef Sprite_hpp
#define Sprite_hpp

class Sprite {
private:
	Texture* texture;

public:
	bool flipX = false;

	Sprite();
	~Sprite();
};

#endif /* Sprite_hpp */
