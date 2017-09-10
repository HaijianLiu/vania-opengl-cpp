
#include "Engine.hpp"

/*==============================================================================
< main >
==============================================================================*/
int main() {

	GLFWwindow* window = createWindow("vania",SCREEN_WIDTH,SCREEN_HEIGHT);

	// render loop
	while (!glfwWindowShouldClose(window)) {

		// input
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// glfw: terminate, clearing all previously allocated GLFW resources.
	glfwTerminate();
	return 0;
}
