#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>

#define SCREEN_WIDTH 300
#define SCREEN_HEIGHT 300

int main(void)
{
	// Make a window
	GLFWwindow *window;

	// Initialize the library and make sure it works
	if (!glfwInit())
	{
		return -1;
	}

	// Create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL);

	// See if the window is actually created
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// Make this windows context the current context
	glfwMakeContextCurrent(window);

	float vertices[] = {
		0.0, 0.5, 0.0,
		-0.5, -0.5, 0.0,
		0.5, -0.5, 0.0
	};

	// Do as long as the window isn't closed
	while (!glfwWindowShouldClose(window)) {
		// Clear the screen at the beginning of every loop
		glClear(GL_COLOR_BUFFER_BIT);

		// Swap the windows front and back buffers
		glfwSwapBuffers(window);
		// Look for events
		glfwPollEvents();
	}

	// Terminate glfw at last
	glfwTerminate();

	return 0;
}
