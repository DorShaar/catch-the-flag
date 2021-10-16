#include "ScreenHandler.h"

ScreenHandler::ScreenHandler()
{
	setScreenSize(ScreenLength, ScreenHight); // Sets screen size.
	hideCursor(); // Removes courser.
	initializeBoard();
	//printCurrentBoard();
};


// Private Methods.
void ScreenHandler::setScreenSize(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;

	// Stores the console's current dimensions.
	GetWindowRect(console, &r);
	// MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
	// SetConsoleScreenBufferSize(console, width*height);
}


void ScreenHandler::gotoxy(int x, int y)
{
	HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwCursorPosition; // coordinates (x,y).
	cout << flush; // Flush makes sure that the buffer is cleared and the characters are written to their destination.
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	SetConsoleCursorPosition(myconsole, dwCursorPosition);
}


void ScreenHandler::initializeBoard()
{
	for (int i = 0; i < BoardHeight; ++i)
	{
		for (int j = 0; j < BoardLength; ++j)
		{
			board[i][j] = EmptyBoard[i][j];
		}
	}
}

// Setters and Getters.
char ScreenHandler::getCharInBoard(int coordX, int coordY)
{
	return board[coordX][coordY];
}


void ScreenHandler::setCharToBoard(int coordX, int coordY, char ch, Color color)
{
	setTextColor(color);
	board[coordX][coordY] = ch;
	gotoxy(coordX, coordY + BoardStartRow);
	cout << ch;
}

// Methods.
void ScreenHandler::hideCursor()
{
	HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CURSOR;
	CURSOR.dwSize = 0;
	CURSOR.bVisible = FALSE;
	SetConsoleCursorInfo(myconsole, &CURSOR); // Second argument needs pointer.
}


void ScreenHandler::setTextColor(Color colorToSet)
{
	HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(myconsole, (int)colorToSet);
}


void ScreenHandler::resetScreen()
{
	system("cls");
}


void ScreenHandler::eraseCharFromBoard(int coordX, int coordY)
{
	setCharToBoard(coordX, coordY, ' ');
}


void ScreenHandler::printCurrentBoard()
{
	setTextColor(WHITE);
	gotoxy(0, BoardStartRow);
	for (int i = 0; i < BoardHeight; ++i)
	{
		for (int j = 0; j < BoardLength; ++j)
		{
			cout << board[i][j];
		}
	}
}


ScreenHandler* globalScreen()
{
	return staticScreenPtr;
}