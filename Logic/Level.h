#pragma once

#include <string>

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

	bool isDinnerLevel();
    bool agreementMistakes();
    void regenerate();
};

