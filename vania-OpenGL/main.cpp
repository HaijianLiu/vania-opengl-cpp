
#include "Engine.hpp"


GLFWwindow* window = createWindow("vania",SCREEN_WIDTH,SCREEN_HEIGHT);
Camera* camera = new Camera();
Quad* quad = new Quad();
Texture* texture = new Texture("/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/enemy_jumper_jump.png");
Shader* shader = new Shader("/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Shader/quad.vs.glsl", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Shader/quad.fs.glsl");
Transform* transform = new Transform();

/*------------------------------------------------------------------------------
< Start >
------------------------------------------------------------------------------*/
void start() {

}


/*------------------------------------------------------------------------------
< Delete >
------------------------------------------------------------------------------*/
void release() {
	delete camera;
	delete quad;
	delete texture;
	delete shader;
	delete transform;
}


/*------------------------------------------------------------------------------
< Update >
------------------------------------------------------------------------------*/
void update() {

}


/*------------------------------------------------------------------------------
< Draw >
------------------------------------------------------------------------------*/
void draw() {

}


/*------------------------------------------------------------------------------
< Get Functions >
------------------------------------------------------------------------------*/
GLFWwindow* getWindow() {
	return window;
}
Camera* getCamera() {
	return camera;
}
Shader* getShader() {
	return shader;
}





/*==============================================================================
< main >
==============================================================================*/
int main() {


	start();

	shader->use();
		shader->setInt("texColor", 0);
		transform->scale = glm::vec3(47.0f,32.0f,0.0f);
		transform->update();
		shader->setMat4("projection",camera->projection);
		shader->setMat4("view",camera->view);
		shader->setMat4("model",transform->model);

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
			quad->draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// glfw: terminate, clearing all previously allocated GLFW resources.
	glfwTerminate();
	release();
	return 0;
}
