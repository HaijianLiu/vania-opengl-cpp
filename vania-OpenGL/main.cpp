
#include "Engine.hpp"


Window* window = new Window("vania",SCREEN_WIDTH,SCREEN_HEIGHT);
Timer* timer = new Timer();
Camera* camera = new Camera();
Quad* quad = new Quad();
Texture* texture = new Texture("/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/enemy_jumper_jump.png");
Shader* shader = new Shader("/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Shader/quad.vs.glsl", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Shader/quad.fs.glsl");
Transform* transform = new Transform();


/*------------------------------------------------------------------------------
< Delete >
------------------------------------------------------------------------------*/
void release() {
	delete window;
	delete timer;
	delete camera;
	delete quad;
	delete texture;
	delete shader;
	delete transform;
	glfwTerminate(); // glfw: terminate, clearing all previously allocated GLFW resources.
}


/*------------------------------------------------------------------------------
< Start >
------------------------------------------------------------------------------*/
void start() {
	timer->start();
	shader->use();
		shader->setInt("texColor", 0);
		transform->scale = glm::vec3(47.0f,32.0f,0.0f);
		transform->update();
		shader->setMat4("projection",camera->projection);
		shader->setMat4("view",camera->view);
		shader->setMat4("model",transform->model);
}


/*------------------------------------------------------------------------------
< Update >
------------------------------------------------------------------------------*/
void update() {
	timer->update();
}


/*------------------------------------------------------------------------------
< Draw >
------------------------------------------------------------------------------*/
void draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shader->use();
		glBindTexture(GL_TEXTURE_2D, texture->textureID);
		quad->draw();

	glfwSwapBuffers(window->window);
	glfwPollEvents();
}


/*------------------------------------------------------------------------------
< Get Functions >
------------------------------------------------------------------------------*/
Window* getWindow() {
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
	// Start
	start();

	// Game Loop
	while (!glfwWindowShouldClose(window->window)) {
		if (glfwGetKey(window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window->window, true);
		// Update
		// timer->setTime();
		// if (timer->checkFPS(60)) {
			update();
			draw();
		// }
	}

	// release
	release();
	return 0;
}
