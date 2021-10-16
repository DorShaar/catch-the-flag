#pragma once

#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "EnumsAndConsts.h"
using namespace std;

class ScreenHandler
{
	// Members.
	char board[BoardHeight][BoardLength];

	// Private Methods.
	void setScreenSize(int x, int y);
	void hideCursor();
	void initializeBoard();

public:
	// Constructors.
	ScreenHandler();

	// Setters and Getters.
	char getCharInBoard(int coordX, int coordY);
	void setCharToBoard(int coordX, int coordY, char ch, Color color = WHITE);

	// Methods.
	void resetScreen();
	void gotoxy(int x, int y);
	void setTextColor(Color = WHITE);
	void eraseCharFromBoard(int coordX, int coordY);
	void printCurrentBoard();
	
};

static ScreenHandler* staticScreenPtr = new ScreenHandler();

ScreenHandler* globalScreen();