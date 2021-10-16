#pragma once
#include "Tool.h"

using namespace std;

class Diver : public Tool
{
	// Private Methods.
	virtual bool isStepPossible(int coordX, int coordY, string& errorMessage) override;

public:
	Diver(char newSign, Color newColor) : Tool(newSign, newColor) {}
};
