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
    DateGenerator dates;
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

    void setBlackList();
    void regenerate();
};

