
#include "Engine.hpp"





/*==============================================================================
< main >
==============================================================================*/
int main() {

	GLFWwindow* window = createWindow("vania",SCREEN_WIDTH,SCREEN_HEIGHT);

	Quad* quad = new Quad();
	Texture* texture = new Texture("/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/enemy_jumper_jump.png");
	Shader* shader = new Shader("/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Shader/quad.vs.glsl", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Shader/quad.fs.glsl");


	glm::mat4 projection = glm::ortho(0.0f, 2*SCREEN_WIDTH, 0.0f, 2*SCREEN_HEIGHT, 0.0f, 100.0f);

	glm::mat4 view = glm::lookAt(
		glm::vec3(-SCREEN_WIDTH/2,-SCREEN_HEIGHT/2,1), // Camera is at (4,3,3), in World Space
		glm::vec3(-SCREEN_WIDTH/2,-SCREEN_HEIGHT/2,0), // and looks at the origin
		glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
	);

	Transform transform = Transform();
	transform.position.x = SCREEN_WIDTH / PIXEL_SCALE / 2.0f;
	transform.position.y = 20.0f;
	transform.scale.x = 47.0f;
	transform.scale.y = 32.0f;

	shader->use();
		shader->setInt("ourTexture", 0);
		glm::mat4 model = glm::mat4();
		model = glm::rotate(0.0f,glm::vec3(0,0,1));
		model = glm::scale(model, glm::vec3(47.0f,32.0f,0.0f));
		model = glm::translate(model, glm::vec3(0.0f,0.0f,0.0f));
		shader->setMat4("model",model);
		shader->setMat4("projection",projection);
		shader->setMat4("view",view);

		// timing
		float deltaTime = 0.0f;
		float lastFrame = 0.0f;

	// render loop
	while (!glfwWindowShouldClose(window)) {

		// per-frame time logic
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;


		// input
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader->use();
			glBindTexture(GL_TEXTURE_2D, texture->textureID);
			model = glm::rotate(0.0f,glm::vec3(0,0,1));
			model = glm::scale(model, glm::vec3(47.0f,32.0f,0.0f));
			model = glm::translate(model, glm::vec3(0.0f,0.0f,0.0f));
			shader->setMat4("model",model);
			quad->draw();
			model = glm::rotate(0.0f,glm::vec3(0,0,1));
			model = glm::scale(model, glm::vec3(47.0f,32.0f,0.0f));
			model = glm::translate(model, glm::vec3(10.0f,10.0f,0.0f));
			shader->setMat4("model",model);
			quad->draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// glfw: terminate, clearing all previously allocated GLFW resources.
	glfwTerminate();
	return 0;
}
