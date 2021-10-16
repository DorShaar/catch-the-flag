#pragma once
#include "BaseSurface.h"
using namespace std;

class Forrest final: public BaseSurface
{
public:
	Forrest(int coordXInSurfaceData, int coordYInSurfaceData)
	{
		sign = ForrestChar;
		defaultColor = GREEN;
		placeInBoard = Point(coordXInSurfaceData*(InnerSpaceLength + 1), coordYInSurfaceData*(InnerSpaceHeight + 1));
	}
};