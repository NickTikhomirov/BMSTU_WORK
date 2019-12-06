#include "Level.h"

using std::string;
using std::to_string;


Level::Level()
{
    mistakes = nullptr;
    regenerate();
}


Level::~Level()
{
    delete mistakes;
}

string Level::getNameFor(char a){
    if(mistakes->isNameCorrect(a)) return name;
    else if(rand()%2) return (NameGenerator::degenerateName(name));
    else {
        string p;
        do p = NameGenerator::generateName();
        while(p==(name));
        return p;
    }
}

string Level::getName2For(char a){
    if(mistakes->isName2Correct(a)) return secondName;
    else if(rand()%2) return (NameGenerator::degenerateName(secondName));
    else {
        string p;
        do p = NameGenerator::generateName2();
        while(p==(secondName));
        return p;
    }
}



void Level::regenerate(){
    delete mistakes;
    mistakes = new Mistakes;
    if(mistakes->isB()) setBlackList();
    else {
        face = (short)Randomizer::randInPool(1, 17);
        name = NameGenerator::generateName();
        secondName = NameGenerator::generateName2();
    }
    insuranceNumber = Randomizer::generateDocumentNumber();

    dates = DateGenerator();
    dates.generate(mistakes->anyDateMistakes());
}

void Level::setBlackList(){
    face=1;
    name = "Evgeny";
    secondName = "Ponasenkov";
}
