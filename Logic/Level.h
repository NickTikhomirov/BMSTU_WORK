#pragma once

#include <string>

#include "Generators/DateGenerator.h"
#include "Generators/Randomizer.h"
#include "Generators/NameGenerator.h"
#include "Mistakes.h"

using std::string;

class Level
{
public:
	Level();
    ~Level();
    string name;
    string secondName;
    string birtday;
    char face;
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


    void setBlackList();
    void regenerate();
};

