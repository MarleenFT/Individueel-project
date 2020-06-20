#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>

#include "Tutorial1.h"

#define cubesize 50

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);

GLfloat rotationX = 0.0f;
GLfloat rotationY = 0.0f;

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

	glfwSetKeyCallback(window, keyCallback);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

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
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	GLfloat halfScreenWidth = SCREEN_WIDTH / 2;
	GLfloat halfScreenHeight = SCREEN_HEIGHT / 2;

	// Do as long as the window isn't closed
	while (!glfwWindowShouldClose(window)) {
		// Clear the screen at the beginning of every loop
		glClear(GL_COLOR_BUFFER_BIT);

		//--------------------------------Add draw code here--------------------------------------------
		glPushMatrix();
		glTranslatef(halfScreenWidth, halfScreenHeight, -500);
		glRotatef(rotationX, 1, 0, 0);
		glRotatef(rotationY, 0, 1, 0);
		glTranslatef(-halfScreenWidth, -halfScreenHeight, 500);

		float color1[3] = { 1, 0, 0 };
		float color2[3] = { 0, 0, 1 };

		tut1.drawCube(halfScreenWidth - 50, halfScreenHeight - 50, -450, cubesize, color1);
		tut1.drawCube(halfScreenWidth, halfScreenHeight - 50, -450, cubesize, color2);
		tut1.drawCube(halfScreenWidth + 50, halfScreenHeight - 50, -450, cubesize, color1);
		tut1.drawCube(halfScreenWidth - 50, halfScreenHeight, -450, cubesize, color2);
		tut1.drawCube(halfScreenWidth, halfScreenHeight, -450, cubesize, color1);
		tut1.drawCube(halfScreenWidth + 50, halfScreenHeight, -450, cubesize, color2);
		tut1.drawCube(halfScreenWidth - 50, halfScreenHeight + 50, -450, cubesize, color1);
		tut1.drawCube(halfScreenWidth, halfScreenHeight + 50, -450, cubesize, color2);
		tut1.drawCube(halfScreenWidth + 50, halfScreenHeight + 50, -450, cubesize, color1);

		tut1.drawCube(halfScreenWidth - 50, halfScreenHeight - 50, -500, cubesize, color2);
		tut1.drawCube(halfScreenWidth, halfScreenHeight - 50, -500, cubesize, color1);
		tut1.drawCube(halfScreenWidth + 50, halfScreenHeight - 50, -500, cubesize, color2);
		tut1.drawCube(halfScreenWidth - 50, halfScreenHeight, -500, cubesize, color1);
		tut1.drawCube(halfScreenWidth, halfScreenHeight, -500, cubesize, color2);
		tut1.drawCube(halfScreenWidth + 50, halfScreenHeight, -500, cubesize, color1);
		tut1.drawCube(halfScreenWidth - 50, halfScreenHeight + 50, -500, cubesize, color2);
		tut1.drawCube(halfScreenWidth, halfScreenHeight + 50, -500, cubesize, color1);
		tut1.drawCube(halfScreenWidth + 50, halfScreenHeight + 50, -500, cubesize, color2);

		tut1.drawCube(halfScreenWidth - 50, halfScreenHeight - 50, -550, cubesize, color1);
		tut1.drawCube(halfScreenWidth, halfScreenHeight - 50, -550, cubesize, color2);
		tut1.drawCube(halfScreenWidth + 50, halfScreenHeight - 50, -550, cubesize, color1);
		tut1.drawCube(halfScreenWidth - 50, halfScreenHeight, -550, cubesize, color2);
		tut1.drawCube(halfScreenWidth, halfScreenHeight, -550, cubesize, color1);
		tut1.drawCube(halfScreenWidth + 50, halfScreenHeight, -550, cubesize, color2);
		tut1.drawCube(halfScreenWidth - 50, halfScreenHeight + 50, -550, cubesize, color1);
		tut1.drawCube(halfScreenWidth, halfScreenHeight + 50, -550, cubesize, color2);
		tut1.drawCube(halfScreenWidth + 50, halfScreenHeight + 50, -550, cubesize, color1);

		glPopMatrix();
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

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	GLfloat rotationSpeed = 3;

	// actions are GLFW_PRESS, GLFW_RELEASE or GLFW_REPEAT
	if (action == GLFW_PRESS || action == GLFW_REPEAT)
	{
		switch (key)
		{
		case GLFW_KEY_UP:
			rotationX -= rotationSpeed;
			break;
		case GLFW_KEY_DOWN:
			rotationX += rotationSpeed;
			break;
		case GLFW_KEY_RIGHT:
			rotationY += rotationSpeed;
			break;
		case GLFW_KEY_LEFT:
			rotationY -= rotationSpeed;
			break;
		}
	}
}