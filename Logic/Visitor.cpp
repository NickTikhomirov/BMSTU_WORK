#include "Visitor.h"
#include <string>

using std::string;



Visitor::Visitor(bool B)
{
    if(B) setBlackList();
    else random();
}


Visitor::~Visitor()
{
}


void Visitor::random() {
    face = (short)Randomizer::randInPool(1, 10);
    name = NameGenerator::generateName();
    secondName = NameGenerator::generateName2();
}

void Visitor::setBlackList() {
	name = "Evgeny";
	secondName = "Ponasenkov";
    //birtday = "13.03.1982";
    face = 1;
}
