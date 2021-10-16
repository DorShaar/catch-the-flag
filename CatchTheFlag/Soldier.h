#pragma once
#include "Tool.h"
using namespace std;

class Soldier : public Tool
{
	// Private Methods.
	virtual bool isStepPossible(int coordX, int coordY, string& errorMessage) override;

public:
	Soldier(char newSign, Color newColor) : Tool(newSign, newColor) {}
};