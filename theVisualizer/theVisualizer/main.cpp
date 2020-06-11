#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>

#include "Tutorial1.h"

int main(void)
{
	Tutorial1 tut1;

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

	// Vertex will range from 0 to SCREEN_WIDTH and HEIGHT
	glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
	// Add 'camera'
	glMatrixMode(GL_PROJECTION);
	//Put user at 0 0 0
	glLoadIdentity();
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
	glMatrixMode(GL_MODELVIEW);

	// Do as long as the window isn't closed
	while (!glfwWindowShouldClose(window)) {
		// Clear the screen at the beginning of every loop
		glClear(GL_COLOR_BUFFER_BIT);

		//--------------------------------Add draw code here--------------------------------------------
		tut1.drawPoint(80, SCREEN_HEIGHT / 2, 10, true);
		tut1.drawPoint(90, SCREEN_HEIGHT / 2, 10, false);
		tut1.drawPoint(100, SCREEN_HEIGHT / 2, 10, true);
		tut1.drawPoint(110, SCREEN_HEIGHT / 2, 10, false);
		tut1.drawPoint(120, SCREEN_HEIGHT / 2, 10, true);
		tut1.drawPoint(130, SCREEN_HEIGHT / 2, 10, false);
		tut1.drawPoint(140, SCREEN_HEIGHT / 2, 10, true);
		//----------------------------------------------------------------------------------------------

		// Swap the windows front and back buffers
		glfwSwapBuffers(window);
		// Look for events
		glfwPollEvents();
	}

	// Terminate glfw at last
	glfwTerminate();

	return 0;
}
