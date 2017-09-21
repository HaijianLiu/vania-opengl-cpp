
#ifndef Scene01_hpp
#define Scene01_hpp

class Scene01 : public Scene {
private:
	/* data */

public:
	// Constructors
	Scene01();
	~Scene01();

	// virtual Functions
	void load();
	void end();
	void reset();
	void clear();
};

#endif /* Scene01_hpp */
