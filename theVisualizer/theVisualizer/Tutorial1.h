#pragma once

class Tutorial1
{
public:
	Tutorial1();
	virtual ~Tutorial1();

	void visualizeTriangle();

private:
	// A triangle
	float vertices[9] = 
	{
		0.0, 0.5, 0.0,		//x, y, z; Top
		-0.5, -0.5, 0.0,	//x, y, z; Left
		0.5, -0.5, 0.0		//x, y, z; Right
	};
};