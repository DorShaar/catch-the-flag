#pragma once
using namespace std;

class Point
{
	int coordinateX;
	int coordinateY;

public:
	Point() : coordinateX(0), coordinateY(0) { };
	Point(int newXCoord, int newYCoord) : coordinateX(newXCoord), coordinateY(newYCoord) { };

	// Setters and Getters.
	int getXcoordinate();
	void setXCoordinate(int newXCoordinate);
	int getYcoordinate();
	void setYCoordinate(int newYCoordinate);
};