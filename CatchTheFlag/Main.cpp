#include "GameManager.h"
using namespace std;


void main()
{
	GameManager catchTheFlag;

	catchTheFlag.run();
}

/*
Bugs:

 - some problem with the error printing, jumps a line.
 - if tool stepped on a surface, print back the right surface when it leaves it.
 - creating flags.
 - count wins and loses.
 - attacks and defendes..
 - flipped games.
 - handle secondary manue + ESC.

 maybe:
 - add numbers and letters.
 - if tool was chosen, print the 
*/