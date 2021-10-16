#pragma once
using namespace std;

enum KeyboardButtons
{
	// First's player keyboard buttons.
	Player1Up = 'w',
	Player1Down = 's',
	Player1Left = 'a',
	Player1Right = 'd',

	// Second's player keyboard buttons.
	Player2Up = 'i',
	Player2Down = 'k',
	Player2Left = 'j',
	Player2Right = 'l',

	// Menu buttons.
	ESC = 27
};


enum menuCommands
{
	Undefiend = '0',
	SetPlayersNames = '1',
	PlayGame = '2',
	PlayFlippedGame = '3',
	ResetScore = '4',
	ExitGame = '9'
};


enum secondaryMenuCommands
{
	ContinueGame = '1',
	RestartGame = '2',
	GoToMainMenu = '8',
};


enum Color
{
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHTGREY = 7,
	DARKGREY = 8,
	LIGHTBLUE = 9,
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	LIGHTRED = 12,
	LIGHTMAGENTA = 13,
	YELLOW = 14,
	WHITE = 15
};


enum Direction
{
	Up = 0,
	Down = 1,
	Left = 2,
	Right = 3,
};


enum PlayerType
{
	FirstPlayer = 0,
	SecondPlayer = 1
};


enum BoardChars
{
	ForrestChar = '^',
	SeaChar = '~'
};


enum ToolsNames
{
	Tool1 = '1',
	Tool2 = '2',
	Tool3 = '3',
	Tool7 = '7',
	Tool8 = '8',
	Tool9 = '9'
};


// Sleep consts.
const int oneSecond = 1000;

// Screen consts.
const int ScreenLength = 1500;
const int ScreenHight = 900;
const int MiddleOfScreen = 30;
const int MenuStartRow = 0;
const int MessageToUserRow = 3;
const int BoardStartRow = 7;


// SurfaceData consts.
const int SurfaceDataSize = 13;
static char* SurfaceDate[SurfaceDataSize] = {
	   //0123456789012
		"          A  ", // 0
		"             ",
		"             ",
		"  f      s   ",
		"  f     ss   ",
		"  ff   sss   ", // 5
		"ffff     ss  ",
		"f  f     sss ",
		"   f     ss  ",
		"         s   ",
		"             ", // 10
		"             ",
		" B           "  // 12
};


// Board consts.
const int BoardLength = 80;
const int BoardHeight = 53;
const int InnerSpaceLength = 5;
const int InnerSpaceHeight = 3;
static char* EmptyBoard[BoardHeight] = {

	/*
	To calculate top-left point:
	x= SurfaceDateX*(InnerSpaceLength+1).
	y= SurfaceDateY*(InnerSpaceHeight+1).

	To calculate middle point of the square:
	x= [SurfaceDateX*(InnerSpaceLength+1)] +3.
	y= [SurfaceDateY*(InnerSpaceHeight+1)] +2.
	*/

   //	      10        20        30        40        50        60        70       79
   //01234567890123456789012345678901234567890123456789012345678901234567890123456789
	"-------------------------------------------------------------------------------", // 0
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|------------------------------------------------------------------------------",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |", // 5
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|------------------------------------------------------------------------------",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |", // 10
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|------------------------------------------------------------------------------",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |", // 15
	"|------------------------------------------------------------------------------",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|------------------------------------------------------------------------------", // 20
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|------------------------------------------------------------------------------",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |", // 25
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|------------------------------------------------------------------------------",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |", // 30
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|------------------------------------------------------------------------------",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |", // 35
	"|------------------------------------------------------------------------------",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|------------------------------------------------------------------------------", // 40
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|------------------------------------------------------------------------------",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |", // 45
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|------------------------------------------------------------------------------",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |",
	"|     |     |     |     |     |     |     |     |     |     |     |     |     |", // 50
	"-------------------------------------------------------------------------------" // 51
	//012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234
	//	       10        20        30        40        50        60        70        80        90       100 104
};