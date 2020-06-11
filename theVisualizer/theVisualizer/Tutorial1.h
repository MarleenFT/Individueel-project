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
	void visualizeSquare();

	void drawPoint(int x, int y, int size, bool smooth);

private:
	// A triangle
	float verticesTriangle[9] =
	{
		0.0, 0.5, 0.0,		//x, y, z; Top
		-0.5, -0.5, 0.0,	//x, y, z; Left
		0.5, -0.5, 0.0		//x, y, z; Right
	};
	// A square
	float verticesSquare[12] =
	{
		100, CUBE_HEIGHT, 0,		//x, y, z; Top left
		CUBE_WIDTH, CUBE_HEIGHT, 0,	//x, y, z; Top right
		CUBE_WIDTH, 100, 0,			//x, y, z; Bottom left
		100, 100, 0					//x, y, z; Bottom right
	};
	// A point
	float pointVertex[2] = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };			//x, y; Point
};