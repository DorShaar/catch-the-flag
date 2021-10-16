#include "GameManager.h"

// Private Methods.

void GameManager::headLine()
{
	globalScreen()->setTextColor(Color::CYAN);
	globalScreen()->gotoxy(MiddleOfScreen, 0);
	cout << "Catch The Flag !";
	globalScreen()->setTextColor();
}


void GameManager::entryMessage()
{
	headLine();
	char dummy;

	globalScreen()->gotoxy(0, 2);
	cout << "Welcome to Dor Shaar's game - Catch the flag !\n\n\n";
	cout << "Try to get the opponent's flag, before he reaches yours first!\n";
	cout << "In this game you have three tools, every tool has different ability.\nPlay Wisely!!\n\n\n";
	cout << "Good luck !\nPress any key to continue.\n";
	cin >> dummy;
	getchar(); // For dummy \n.
}


void GameManager::menu()
{
	globalScreen()->resetScreen();
	headLine();

	globalScreen()->gotoxy(0, 2);
	cout << "Choose one of the options below:\n";
	cout << "1. Pick players names.\n2. Start the game.\n3. Start flipped game.\n";
	cout << "4. Reset scores.\n9. Exit the game.\n\n";
	cout << "Your option is: ";
}


void GameManager::secondaryMenu()
{
	globalScreen()->resetScreen();
	headLine();

	globalScreen()->gotoxy(0, 2);
	cout << "Choose one of the options below:\n";
	cout << "1. Go back from where we stopped.\n2. Restart this game.\n8. Go to main manu.\n";
	cout << "9. Exit the game.\n\n";
	cout << "Your option is: ";
}


void GameManager::switchMenuCommands()
{
	userInput = getchar();
	getchar(); // For dummy \n.
	
	switch (userInput)
	{
	case menuCommands::SetPlayersNames:
		players[0]->setPlayerName();
		players[1]->setPlayerName();
		cout << "Your player's names are: " << players[0]->getPlayerName() << " and " << players[1]->getPlayerName() << ".\nMay the best of you win!\n";
		break;
	case menuCommands::PlayGame:
		break;
	case menuCommands::PlayFlippedGame:
		break;
	case menuCommands::ResetScore:
		players[0]->resetScore();
		players[1]->resetScore();
		cout << "Your scores were reset.\n";
		break;
	case menuCommands::ExitGame:
		endOfGame = true;
		break;
	default:
		userInput = Undefiend;
		cout << "You chose invalid input. Try again.\n";
		break;
	}
}


void GameManager::switchSecondaryMenuCommands()
{
	userInput = getchar();
	getchar(); // For dummy \n.

	switch (userInput)
	{
	case secondaryMenuCommands::ContinueGame:
		break;
	case secondaryMenuCommands::RestartGame:
		// restart Game TODO.;
		break;
	case secondaryMenuCommands::GoToMainMenu:
		break;
	case menuCommands::ExitGame:
		break;
	default:
		userInput = Undefiend;
		cout << "You chose invalid input. Try again.\n";
		break;
	}
}


void GameManager::MessageToUser(string lineToPrint)
{
	globalScreen()->setTextColor();
	globalScreen()->gotoxy(0, MessageToUserRow);
	cout << "                                                                                ";
	cout << "                                                                                ";
	globalScreen()->gotoxy(0, MessageToUserRow);
	if (playerTurn == PlayerType::FirstPlayer) // Player's A turn.
	{
		cout << players[0]->getPlayerName() << "'s turn.\n";
	}
	else // Player's B turn.
	{
		cout << players[1]->getPlayerName() << "'s turn.\n";
	}
	cout << lineToPrint;
}


void GameManager::ByeByeMessage()
{
	globalScreen()->resetScreen();
	headLine();

	globalScreen()->gotoxy(10, 10);
	cout << "Thank you for playing! Hope you Enjoyed our game! :)\n";
	Sleep(3*oneSecond);
}


void GameManager::deleteSurfacesObject()
{
	vector<BaseSurface*>::iterator itr = surfacesObjects.begin();

	while (itr != surfacesObjects.end())
	{
		delete *itr;
		surfacesObjects.erase(itr);
		itr = surfacesObjects.begin();
	}
}

void GameManager::updateSurfacesObjects()
{
	for (int i = 0; i < SurfaceDataSize; ++i)
	{
		for (int j = 0; j < SurfaceDataSize; ++j)
		{
			if (SurfaceDate[i][j] == 'f')
			{
				surfacesObjects.push_back(new Forrest(j, i));
			}
			else if (SurfaceDate[i][j] == 's')
			{
				surfacesObjects.push_back(new Sea(j, i));
			}
		}
	}
}


void GameManager::printSurfaces()
{
	vector<BaseSurface*>::iterator itr = surfacesObjects.begin();

	while (itr != surfacesObjects.end())
	{
		(*itr)->printSurface();
		++itr;
	}
}


void GameManager::printGamePlayersName()
{
	globalScreen()->setTextColor(Color::YELLOW);
	globalScreen()->gotoxy(MiddleOfScreen - (players[0]->getPlayerName().length()) + 9, 1); // 9 is the half length of the headline.
	cout << players[0]->getPlayerName();
	globalScreen()->setTextColor();
	cout << " : ";
	globalScreen()->setTextColor(Color::RED);
	cout << players[1]->getPlayerName();
	globalScreen()->setTextColor();
}


void GameManager::printPlayersScores()
{
	globalScreen()->gotoxy(0, BoardStartRow - 1);
	cout << players[0]->getPlayerName() << " score: " << players[0]->getScore();
	globalScreen()->gotoxy(0, BoardStartRow + BoardHeight);
	cout << players[1]->getPlayerName() << " score: " << players[1]->getScore();
}


void GameManager::printPlayersTools()
{
	players[0]->printTools();
	players[1]->printTools();
}


bool GameManager::isValidNumOfToolsFromPlayers()
{
	// Returns true if the 
	if ((players[0]->getNumOfTools() == 0) || (players[1]->getNumOfTools() == 0))
	{
		return false;
	}
	else { return true;	}
}


bool GameManager::getMoveToolCommandAndConvert()
{
	bool returnedValue = false;

	userInput = getchar();
	getchar(); // For dummy \n.

	if (playerTurn == PlayerType::FirstPlayer) // Player's A turn.
	{
		switch (userInput)
		{
		case KeyboardButtons::Player1Up:
			userInput = Direction::Up;
			returnedValue = true;
			break;
		case KeyboardButtons::Player1Down:
			userInput = Direction::Down;
			returnedValue = true;
			break;
		case KeyboardButtons::Player1Right:
			userInput = Direction::Right;
			returnedValue = true;
			break;
		case KeyboardButtons::Player1Left:
			userInput = Direction::Left;
			returnedValue = true;
			break;
		default:
			MessageToUser("\nInvalid input. Try Again.");
			break;
		}
	}

	else // Player's B turn.
	{
		switch (userInput)
		{
		case KeyboardButtons::Player2Up:
			userInput = Direction::Up;
			returnedValue = true;
			break;
		case KeyboardButtons::Player2Down:
			userInput = Direction::Down;
			returnedValue = true;
			break;
		case KeyboardButtons::Player2Right:
			userInput = Direction::Right;
			returnedValue = true;
			break;
		case KeyboardButtons::Player2Left:
			userInput = Direction::Left;
			returnedValue = true;
			break;
		default:
			MessageToUser("Invalid input. Try Again.");
			break;
		}
	}
	return returnedValue;
}


void GameManager::isGameOver()
{
	if (!isValidNumOfToolsFromPlayers())
	{
		endOfGame = true;
	}
	// TODO: Chceks if flag was captured
}


void GameManager::playGame()
{
	globalScreen()->resetScreen();
	headLine();
	printGamePlayersName();
	globalScreen()->printCurrentBoard();
	printPlayersScores();
	printSurfaces();
	printPlayersTools();

	while ((userInput != KeyboardButtons::ESC) && (userInput != menuCommands::ExitGame))
	{
		ToolsNames chosenTool;
		bool isInValidInput = true;

		MessageToUser();
		userInput = getchar();
		getchar(); // For dummy '\n'.
		chosenTool = (ToolsNames)userInput;
		
		while (!(players[playerTurn]->chooseToolToMove(playerTurn, userInput)))
		{
			MessageToUser("Invalid input. Try again.");
			userInput = getchar();
			getchar(); // For dummy '\n'.
			chosenTool = (ToolsNames)userInput;
		}

		if (userInput != KeyboardButtons::ESC)
		{
			Direction direction;
			string lineToPrint = (string)"Tool " + (char)chosenTool + (string)" was chosen. Where do you want to move it?";
			MessageToUser(lineToPrint);

			while (!getMoveToolCommandAndConvert()) {}
			direction = Direction(userInput);
			while (!(players[playerTurn]->moveTool(chosenTool, direction, lineToPrint)))
			{
				MessageToUser(lineToPrint);
				while (!getMoveToolCommandAndConvert()) {}
				direction = Direction(userInput);
			}
		}

		// TODO : handel ESC.

		iterationsCount++;
		(iterationsCount % 2 == 0) ? playerTurn = PlayerType::FirstPlayer : playerTurn = PlayerType::SecondPlayer;
		isGameOver();
	}
}


// Methods.

void GameManager::run()
{
	entryMessage();
	menu();
	do
	{
		switchMenuCommands();
	} while (userInput != menuCommands::ExitGame && userInput != menuCommands::PlayGame && userInput != menuCommands::PlayFlippedGame);
	
	if (userInput == menuCommands::PlayGame) // Maybe while instead of if TOFIX
	{
		playGame();
	}
	else if (userInput == menuCommands::PlayFlippedGame)
	{
		//PlayFlippedGame();
	}
	
	ByeByeMessage();
}