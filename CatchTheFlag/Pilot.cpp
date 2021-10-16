#include "Pilot.h"

bool Pilot::isStepPossible(int coordX, int coordY, string& errorMessage)
{
	if (checkIfPointOutOfBorders(coordX, coordY))
	{
		errorMessage = "Invalid move. The new position is out of the borders of the board.";
		return false;
	}

	char ch = globalScreen()->getCharInBoard(coordX, coordY);

	if (ch == Tool1 || ch == Tool2 || ch == Tool3 || ch == Tool7 || ch == Tool8 || ch == Tool9)
	{
		errorMessage = "Invalid move. There is already another tool there.";
		return false;
	}
	else
	{
		return true;
	}
}