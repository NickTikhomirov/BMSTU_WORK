#include "Level.h"

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

string Level::getNameFor(char a){
    if(mistakes->isNameCorrect(a)) return visitor->name;
    else if(rand()%2) return NameGenerator::degenerateName(visitor->name);
    else {
        string p;
        do p = NameGenerator::generateName();
        while(p==(visitor->name));
        return p;
    }
}

string Level::getName2For(char a){
    if(mistakes->isNameCorrect(a)) return visitor->secondName;
    else if(rand()%2) return NameGenerator::degenerateName(visitor->secondName);
    else {
        string p;
        do p = NameGenerator::generateName2();
        while(p==(visitor->secondName));
        return p;
    }
}



void Level::regenerate(){
    if(mistakes!=0)delete mistakes;
    mistakes = new Mistakes;
    if(visitor!=0)delete visitor;
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
