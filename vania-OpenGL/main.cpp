
#include "Engine.hpp"


Window* window = new Window("vania",SCREEN_WIDTH,SCREEN_HEIGHT);
Timer* timer = new Timer();
Camera* camera = new Camera();
Quad* quad = new Quad();
Resources* resources = new Resources();


Transform* transform = new Transform();



/*------------------------------------------------------------------------------
< Delete >
------------------------------------------------------------------------------*/
void clear() {
	delete window;
	delete timer;
	delete camera;
	delete quad;
	delete transform;
	glfwTerminate(); // glfw: terminate, clearing all previously allocated GLFW resources.
}


/*------------------------------------------------------------------------------
< Start >
------------------------------------------------------------------------------*/
void start() {
	timer->start();

	resources->loadShader("quad", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Shader/quad.vs.glsl",  "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Shader/quad.fs.glsl");
	resources->loadTexture("enemy_jumper_jump", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/enemy_jumper_jump.png");

	resources->getShader("quad")->use();
		resources->getShader("quad")->setInt("texColor", 0);
		transform->scale = glm::vec3(47.0f,32.0f,0.0f);
		transform->update();
		resources->getShader("quad")->setMat4("projection",camera->projection);
		resources->getShader("quad")->setMat4("view",camera->view);
		resources->getShader("quad")->setMat4("model",transform->model);
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

	resources->getShader("quad")->use();
		glBindTexture(GL_TEXTURE_2D, resources->getTexture("enemy_jumper_jump")->textureID);
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

	// clear
	clear();
	return 0;
}
