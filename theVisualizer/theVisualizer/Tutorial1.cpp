#include "Tutorial1.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

Tutorial1::Tutorial1()
{
}

Tutorial1::~Tutorial1()
{
}

void Tutorial1::visualizeTriangle()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, this->verticesTriangle);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Tutorial1::visualizeSquare()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, this->verticesSquare);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}

