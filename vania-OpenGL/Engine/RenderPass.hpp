
#ifndef RenderPass_hpp
#define RenderPass_hpp

class RenderPass {
private:
	Window* window;
	Quad* quad;

public:
	unsigned int fbo;
	std::vector<unsigned int> pass;
	Shader* shader;

	RenderPass(int number);
	~RenderPass();

	void use();
	void finish();
	void draw();
};

#endif /* RenderPass_hpp */
