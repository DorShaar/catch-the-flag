#include "Tool.h"

// Setters and getters.

char Tool::getSign() { return sign; }

Point Tool::getPosition() {	return position; }


// Private Methods.

void Tool::generatePosition()
{
	int generatedX, generatedY;
	int boardCoordX, boardCoordY;

	/*
	For calculation the middle point of the square.
	x = [SurfaceDateX*(InnerSpaceLength + 1)] + 3.
	y = [SurfaceDateY*(InnerSpaceHeight + 1)] + 2.
	*/

	if (sign == Tool1 || sign == Tool2 || sign == Tool3) // The owner is players A.
	{
		do
		{
			generatedX = rand() % 13; // Range: 0-12.
			generatedY = rand() % 5; // Range: 0-4.
			boardCoordX = (generatedX*(InnerSpaceLength + 1)) + 3;
			boardCoordY = (generatedY*(InnerSpaceHeight + 1)) + 2;
		} while (!isStepPossible(boardCoordX, boardCoordY));
	}
	else // sign == Tool7 / Tool8 / Tool9. The owner is players B. 
	{
		do
		{
			generatedX = rand() % 13; // Range: 0-12.
			generatedY = rand() % 5; // Range: 0-4.
			generatedY = 12 - generatedY; // Range: 8-12.
			boardCoordX = (generatedX*(InnerSpaceLength + 1)) + 3;
			boardCoordY = (generatedY*(InnerSpaceHeight + 1)) + 2;
		} while (!isStepPossible(boardCoordX, boardCoordY));
	}
	position = Point(boardCoordX, boardCoordY);
}


bool Tool::checkIfPointOutOfBorders(int coordX, int coordY)
{
	if ((coordX < 0) || (coordX >= BoardLength) || (coordY < 0) || (coordY >= BoardHeight))
	{
		return true;
	}
	else { return false; }
}

bool Tool::isStepPossible(int coordX, int coordY)
{
	char ch = globalScreen()->getCharInBoard(coordX, coordY);

	if (checkIfPointOutOfBorders(coordX, coordY))
	{
		return false;
	}

	if (ch == Tool1 || ch == Tool2 || ch == Tool3 || ch == Tool7 || ch == Tool8 || ch == Tool9)
	{
		return false;
	}
	else if (ch == BoardChars::SeaChar || ch == BoardChars::ForrestChar)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Tool::isStepPossible(int coordX, int coordY, string& errorMessage)
{
	char ch = globalScreen()->getCharInBoard(coordX, coordY);
	if (checkIfPointOutOfBorders(coordX, coordY))
	{
		errorMessage = "Invalid move. The new position is out of the borders of the board.";
	}

	if (ch == Tool1 || ch == Tool2 || ch == Tool3 || ch == Tool7 || ch == Tool8 || ch == Tool9)
	{
		errorMessage = "Invalid move. There is already another tool there.";
		return false;
	}
	else if (ch == BoardChars::SeaChar)
	{
		errorMessage = "Invalid move. This tool cannot swim.";
		return false;
	}
	else if(ch == BoardChars::ForrestChar)
	{
		errorMessage = "Invalid move. This tool cannot go trough the forrest.";
		return false;
	}
	else
	{
		return true;
	}
}


void Tool::setPosition(Point& newPosition)
{
	position = newPosition;
}


// Methods.

void Tool::printTool()
{
	globalScreen()->setCharToBoard(position.getXcoordinate(), position.getYcoordinate(), sign, color);
}


bool Tool::move(Direction direction, string& errorMessage)
{
	Point newPosition;

	switch (direction)
	{
	case Direction::Up:
		newPosition.setXCoordinate(position.getXcoordinate());
		newPosition.setYCoordinate(position.getYcoordinate() - (InnerSpaceHeight + 1));
		break;
	case Direction::Down:
		newPosition.setXCoordinate(position.getXcoordinate());
		newPosition.setYCoordinate(position.getYcoordinate() + (InnerSpaceHeight + 1));
		break;
	case Direction::Left:
		newPosition.setXCoordinate(position.getXcoordinate() - (InnerSpaceLength + 1));
		newPosition.setYCoordinate(position.getYcoordinate());
		break;
	case Direction::Right:
		newPosition.setXCoordinate(position.getXcoordinate() + (InnerSpaceLength + 1));
		newPosition.setYCoordinate(position.getYcoordinate());
		break;
	default:
		errorMessage = "Invalid input. Try again.";
		return false;
	}

	if (isStepPossible(newPosition.getXcoordinate(), newPosition.getYcoordinate(), errorMessage))
	{
		globalScreen()->eraseCharFromBoard(position.getXcoordinate(), position.getYcoordinate());
		setPosition(newPosition);
		printTool();
		return true;
	}

	else { return false; }
}


// void attack();