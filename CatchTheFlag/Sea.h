#pragma once
#include "BaseSurface.h"
using namespace std;

class Sea final : public BaseSurface
{
public:
	Sea(int coordXInSurfaceData, int coordYInSurfaceData)
	{
		sign = BoardChars::SeaChar;
		defaultColor = BLUE;
		placeInBoard = Point((coordXInSurfaceData*(InnerSpaceLength + 1)), coordYInSurfaceData*(InnerSpaceHeight + 1));
	}
};