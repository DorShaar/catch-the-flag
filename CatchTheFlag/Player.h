#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Pilot.h"
#include "Diver.h"
#include "Soldier.h"
#include "EnumsAndConsts.h"
using namespace std;

class Player
{
	string name;
	vector<Tool*> tools;
	int score;

	// Private Methods.
	void deleteTools();
	int positionDechiper(ToolsNames chosenTool);

public:
	Player(int playerNum, string newName) : name(newName), score(0)
	{
		if (playerNum == PlayerType::FirstPlayer)
		{
			tools.push_back(new Tool(Tool1, YELLOW));
			tools.push_back(new Pilot(Tool2, YELLOW));
			tools.push_back(new Diver(Tool3, YELLOW));
		}
		else // playerNum == PlayerType::SecondPlayer
		{
			tools.push_back(new Pilot(Tool7, RED));
			tools.push_back(new Soldier(Tool8, RED));
			tools.push_back(new Tool(Tool9, RED));
		}
	};

	~Player()
	{
		deleteTools();
	}

	// Getters and Setters.
	string getPlayerName();
	void setPlayerName();
	int getNumOfTools();
	int getScore();
	void resetScore();

	// Methods.
	void printTools();
	bool chooseToolToMove(PlayerType playerTurn, char& userInput);
	bool moveTool(ToolsNames chosenTool, Direction direction, string& errorMessage);
};
