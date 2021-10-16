#pragma once
#include "Tool.h"
using namespace std;

class Pilot : public Tool
{
	// Private Methods.
	virtual bool isStepPossible(int coordX, int coordY, string& errorMessage) override;

public:
	Pilot(char newSign, Color newColor) : Tool(newSign, newColor) {}
};