
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< List of GetGameObject and Collider >
------------------------------------------------------------------------------*/
std::vector<GameObject*> gameObjects;


/*------------------------------------------------------------------------------
< globals >
------------------------------------------------------------------------------*/
Window* window = new Window("vania", SCREEN_WIDTH, SCREEN_HEIGHT);
RenderPass* renderPass = new RenderPass();

Timer* timer = new Timer();
Camera* camera = new Camera();
Resources* resources = new Resources();

Player* player = new Player();


/*------------------------------------------------------------------------------
< clear >
------------------------------------------------------------------------------*/
void clear() {
	delete window;
	delete timer;
	delete camera;
	delete resources;
	delete renderPass;
	delete player;
	glfwTerminate(); // glfw: terminate, clearing all previously allocated GLFW resources.
}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void start() {
	timer->start();
	resources->start();
	renderPass->start(1);
	// GameObjects
	for (unsigned int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->preStart();
		gameObjects[i]->start();
	}
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void update() {
	timer->update();
	camera->update();
	// GameObjects
	for (unsigned int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->update();
		gameObjects[i]->draw();
	}
}


/*------------------------------------------------------------------------------
< get functions >
------------------------------------------------------------------------------*/
Window* getWindow() {
	return window;
}
Timer* getTimer() {
	return timer;
}
Camera* getCamera() {
	return camera;
}
Resources* getResources() {
	return resources;
}
std::vector<GameObject*>* getGameObjects() {
	return &gameObjects;
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
