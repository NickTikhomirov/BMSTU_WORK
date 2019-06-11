#pragma once

#include <string>

#include "Generators/DateGenerator.h"
#include "Generators\Randomizer.h"
#include "Visitor.h"
#include "Mistakes.h"

using std::string;

class Level
{
public:
	Level();
	~Level();
    Visitor *visitor;
    Mistakes *mistakes;
    string time;
    string insuranceNumber;

    string getNameFor(char);
    string getName2For(char);
    string dateA;
    string dateH;
    string dateT;
    string dateP;
    string dateR;
    string dateX;
    string dateM;


	bool isDinnerLevel();
    bool agreementMistakes();
    void regenerate();
};

