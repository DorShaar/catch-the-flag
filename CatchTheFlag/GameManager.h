#pragma once
#include <vector>
#include "EnumsAndConsts.h"
#include "Player.h"
#include "ScreenHandler.h"
#include "Sea.h"
#include "Forrest.h"
using namespace std;

class GameManager
{
	Player **players;
	vector<BaseSurface*> surfacesObjects;
	int iterationsCount;
	PlayerType playerTurn;
	char userInput;
	bool endOfGame;

	// Private Methods.
	
	// Texts.
	void headLine();
	void entryMessage();
	void menu();
	void secondaryMenu();
	void switchMenuCommands();
	void switchSecondaryMenuCommands();
	void MessageToUser(string lineToPrint ="");
	void ByeByeMessage();

	// Vector surfacesObjects.
	void updateSurfacesObjects();
	void deleteSurfacesObject();
	void printSurfaces();

	// Players.
	void printGamePlayersName();
	void printPlayersScores();
	void printPlayersTools();
	bool isValidNumOfToolsFromPlayers();

	// Game run.
	bool getMoveToolCommandAndConvert();
	void isGameOver();
	void playGame();


public:
	GameManager::GameManager() : iterationsCount(0), playerTurn(PlayerType::FirstPlayer), endOfGame(false)
	{
		updateSurfacesObjects();
		players = new Player*[2];
		players[0] = new Player(Player(PlayerType::FirstPlayer, "A"));
		players[1] = new Player(Player(PlayerType::SecondPlayer, "B"));
	}

	GameManager::~GameManager()
	{
		deleteSurfacesObject();
		delete players[0];
		delete players[1];
	}

	// Methods.
	void run();
};