#include "BaseSurface.h"

void BaseSurface::printSurface()
{
	for (int y = 0; y < InnerSpaceHeight; ++y)
	{
		//globalScreen()->gotoxy(placeInBoard.getXcoordinate() + 1, placeInBoard.getYcoordinate() + 1 + y + BoardStartRow);
		for (int x = 0; x < InnerSpaceLength - 1; ++x)
		{
			globalScreen()->setCharToBoard(placeInBoard.getXcoordinate() + 1 + x, placeInBoard.getYcoordinate() + 1 + y, sign, defaultColor);
			cout << sign;
		}
	}
}
