
#include "Engine.hpp"


Window* window = new Window("vania",SCREEN_WIDTH,SCREEN_HEIGHT);
Timer* timer = new Timer();
Camera* camera = new Camera();
Resources* resources = new Resources();

Quad* quad = new Quad();

RenderPass* renderPass = new RenderPass();

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

	resources->loadShader("Quad", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Shader/Quad.vs.glsl",  "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Shader/Quad.fs.glsl");
	resources->loadShader("RenderPass", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Shader/RenderPass.vs.glsl",  "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Shader/RenderPass.fs.glsl");
	resources->loadTexture("enemy_jumper_jump", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/enemy_jumper_jump.png");

	renderPass->start(1);

	transform->scale = glm::vec3(47.0f,32.0f,0.0f);
	transform->update();

	resources->getShader("Quad")->use();
		resources->getShader("Quad")->setInt("texColor", 0);
		resources->getShader("Quad")->setMat4("projection",camera->projection);
		resources->getShader("Quad")->setMat4("view",camera->view);
		resources->getShader("Quad")->setMat4("model",transform->model);
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

	resources->getShader("Quad")->use();
		glBindTexture(GL_TEXTURE_2D, resources->getTexture("enemy_jumper_jump")->textureID);
		quad->draw();

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
Resources* getResources() {
	return resources;
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
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			renderPass->use();
			update();
			draw();
			renderPass->finish();
			renderPass->draw();
			glfwSwapBuffers(window->window);
			glfwPollEvents();
		// }
	}

	// clear
	clear();
	return 0;
}
