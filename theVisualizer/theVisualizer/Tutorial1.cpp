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

void Tutorial1::visualizeSquare(float size, float xPlace, float yPlace, float zPlace, float colors[])
{
	float hl = size / 2;

	float verticesSquare[12] =
	{
		xPlace - hl, yPlace + hl, zPlace + hl,	//top left
		xPlace + hl, yPlace + hl, zPlace + hl,	//top right
		xPlace + hl, yPlace - hl, zPlace + hl,	//bottom right
		xPlace - hl, yPlace - hl, zPlace + hl,	//bottom left
	};

	glColor3f(colors[0], colors[1], colors[2]);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, verticesSquare);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Tutorial1::drawPoint(int x, int y, int size, bool smooth)
{
	this->pointVertex[0] = x;
	this->pointVertex[1] = y;

	if (smooth) {
		glEnable(GL_POINT_SMOOTH);
	}

	glEnableClientState(GL_VERTEX_ARRAY);
	glPointSize(size);
	glVertexPointer(2, GL_FLOAT, 0, this->pointVertex);
	glDrawArrays(GL_POINTS, 0, 1);
	glDisableClientState(GL_VERTEX_ARRAY);

	if (smooth) {
		glDisable(GL_POINT_SMOOTH);
	}
}

void Tutorial1::drawCube(float xPos, float yPos, float zPos, float length, float colors[])
{
	float halfLength = length / 2;
	float Cube[72] =
	{
		//front
		xPos - halfLength, yPos + halfLength, zPos + halfLength,	//top left
		xPos + halfLength, yPos + halfLength, zPos + halfLength,	//top right
		xPos + halfLength, yPos - halfLength, zPos + halfLength,	//bottom right
		xPos - halfLength, yPos - halfLength, zPos + halfLength,	//bottom left
		//back
		xPos - halfLength, yPos + halfLength, zPos - halfLength,
		xPos + halfLength, yPos + halfLength, zPos - halfLength,
		xPos + halfLength, yPos - halfLength, zPos - halfLength,
		xPos - halfLength, yPos - halfLength, zPos - halfLength,
		//left
		xPos - halfLength, yPos + halfLength, zPos + halfLength,
		xPos - halfLength, yPos + halfLength, zPos - halfLength,
		xPos - halfLength, yPos - halfLength, zPos - halfLength,
		xPos - halfLength, yPos - halfLength, zPos + halfLength,
		//right
		xPos + halfLength, yPos + halfLength, zPos + halfLength,
		xPos + halfLength, yPos + halfLength, zPos - halfLength,
		xPos + halfLength, yPos - halfLength, zPos - halfLength,
		xPos + halfLength, yPos - halfLength, zPos + halfLength,
		//top
		xPos - halfLength, yPos + halfLength, zPos + halfLength,
		xPos - halfLength, yPos + halfLength, zPos - halfLength,
		xPos + halfLength, yPos + halfLength, zPos - halfLength,
		xPos + halfLength, yPos + halfLength, zPos + halfLength,
		//bottom
		xPos - halfLength, yPos - halfLength, zPos + halfLength,
		xPos - halfLength, yPos - halfLength, zPos - halfLength,
		xPos + halfLength, yPos - halfLength, zPos - halfLength,
		xPos + halfLength, yPos - halfLength, zPos + halfLength,
	};

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	glColor3f(colors[0], colors[1], colors[2]);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, Cube);
	glDrawArrays(GL_QUADS, 0, 24);
	glDisableClientState(GL_VERTEX_ARRAY);
}


