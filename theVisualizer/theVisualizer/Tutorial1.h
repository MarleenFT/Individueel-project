#pragma once

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#define CUBE_WIDTH 300
#define CUBE_HEIGHT 300

class Tutorial1
{
public:
	Tutorial1();
	virtual ~Tutorial1();

	void visualizeTriangle();
	void visualizeSquare(float size, float xPlace, float yPlace, float zPlace, float colors[]);

	void drawPoint(int x, int y, int size, bool smooth);

	void drawCube(float xPos, float yPos, float zPos, float length, float colors[]);

private:
	// A triangle
	float verticesTriangle[9] =
	{
		0.0, 0.5, 0.0,		//x, y, z; Top
		-0.5, -0.5, 0.0,	//x, y, z; Left
		0.5, -0.5, 0.0		//x, y, z; Right
	};

	// A point
	float pointVertex[2] = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };			//x, y; Point
};