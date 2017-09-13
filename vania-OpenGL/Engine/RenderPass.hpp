
#ifndef RenderPass_hpp
#define RenderPass_hpp

class RenderPass {
private:
	Window* window;
	Resources* resources;

public:
	unsigned int fbo, vao;
	std::vector<unsigned int> pass;

	RenderPass(int number);
	~RenderPass();

	void use();
	void finish();
	void draw();
};

#endif /* RenderPass_hpp */
