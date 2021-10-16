#pragma once
#include <iostream>
#include "Point.h"
#include "EnumsAndConsts.h"
#include "ScreenHandler.h"
using namespace std;

class BaseSurface
{

protected:
	char sign;
	Color defaultColor;
	Point placeInBoard; // The most top-left character in one square on the board (Like (0,0)).

public:
	BaseSurface(){};

	// Methods.
	virtual void printSurface();
};