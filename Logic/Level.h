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
	bool isDinnerLevel();
    bool agreementMistakes();
    bool xNumberProblems();
    bool xHealthy();
    void regenerate();
};

