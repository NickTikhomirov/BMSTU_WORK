#pragma once
#include <string>
using std::string;


#include "Generators/Randomizer.h"
#include "Generators/DateGenerator.h"
#include "Generators/NameGenerator.h"

class Visitor{
public:
    Visitor(bool B=false);
	~Visitor();

    string name;
    string secondName;
    string birtday;
    short face;

    void random();
    void setBlackList();
};

