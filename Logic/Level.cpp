#include "Level.h"
#include <string>
#include "Generators\Randomizer.h"

using std::string;
using std::to_string;


Level::Level()
{
    mistakes = new Mistakes;
    visitor = new Visitor(mistakes->isB());
    insuranceNumber = Randomizer::generateDocumentNumber();
    time=Randomizer::timeGenerator(mistakes->isDinner());
}


Level::~Level()
{
    delete mistakes;
    delete visitor;
}



void Level::regenerate(){
    delete mistakes;
    mistakes = new Mistakes;
    delete visitor;
    visitor = new Visitor(mistakes->isB());
    insuranceNumber = Randomizer::generateDocumentNumber();
    time=Randomizer::timeGenerator(mistakes->isDinner());
}

bool Level::isDinnerLevel() {
    return mistakes->isDinner();
}

bool Level::agreementMistakes(){
    return mistakes->isA();
}

bool Level::xNumberProblems(){
    return false;
}

bool Level::xHealthy(){
    return true;
}
