#pragma once
#include <iostream>
#include "Point.h"
#include "ScreenHandler.h"
using namespace std;

class Tool
{
	Point position;
	char sign;
	Color color;

	// Private Methods.
	void generatePosition();
	bool isStepPossible(int coordX, int coordY);
	virtual bool isStepPossible(int coordX, int coordY, string& errorMessage);

public:
	Tool(char newSign, Color newColor) : sign(newSign), color(newColor)
	{
		generatePosition();
	};

	// Setters and getters.
	char getSign();
	Point getPosition();
	void setPosition(Point& newPosition);

	// Methods.
	void printTool();
	bool checkIfPointOutOfBorders(int coordX, int coordY);
	bool move(Direction direction, string& errorMessage);
	
	// void attack();

};
