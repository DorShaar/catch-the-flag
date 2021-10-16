#include "Player.h"

// Private Methods.
void Player::deleteTools()
{
	vector<Tool*>::iterator itr = tools.begin();

	while (itr != tools.end())
	{
		delete *itr;
		tools.erase(itr);
		itr = tools.begin();
	}
}


int Player::positionDechiper(ToolsNames chosenTool)
{
	int toolPositionInVector;

	switch (chosenTool)
	{
	case ToolsNames::Tool1:
		toolPositionInVector = 0;
		break;
	case ToolsNames::Tool7:
		toolPositionInVector = 0;
		break;
	case ToolsNames::Tool2 :
		toolPositionInVector = 1;
		break;
	case ToolsNames::Tool8:
		toolPositionInVector = 1;
		break;
	case ToolsNames::Tool3 :
		toolPositionInVector = 2;
		break;
	case ToolsNames::Tool9:
		toolPositionInVector = 2;
		break;
	default:
		cout << "Error accured! <chosenTool> was not leagal value.\n";
		break;
	}
	return toolPositionInVector;
}


// Setters and Getters.
string Player::getPlayerName() { return name; }


void Player::setPlayerName()
{
	string newName;

	cout << "Type your name.\n";
	getline(cin,newName);
	name = newName;
}


int Player::getNumOfTools()
{
	return tools.size();
}


int Player::getScore() { return score; }


void Player::resetScore() {	score = 0; }


// Methods.

void Player::printTools()
{
	vector<Tool*>::iterator itr = tools.begin();

	while (itr != tools.end())
	{
		(*itr)->printTool();
		++itr;
	}
}


bool Player::chooseToolToMove(PlayerType playerTurn, char& userInput)
{
	if (playerTurn == PlayerType::FirstPlayer) // Player's A turn.
	{
		if (userInput != Tool1 && userInput != Tool2 && userInput != Tool3 && userInput != KeyboardButtons::ESC)
		{
			return false;
		}
	}

	else // Player's B turn.
	{
		if (userInput != Tool7 && userInput != Tool8 && userInput != Tool9 && userInput != KeyboardButtons::ESC)
		{
			return false;
		}
	}

	return true;
}


bool Player::moveTool(ToolsNames chosenTool, Direction direction, string& errorMessage)
{
	int toolPositionInVector = positionDechiper(chosenTool);

	if (!tools.at(toolPositionInVector)->move(direction, errorMessage)) { return false; }
	else { return true;	}
}
