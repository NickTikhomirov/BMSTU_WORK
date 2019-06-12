#pragma once
#include <string>

using std::string;

class Randomizer
{
public:
	static int randInPool(int, int);
	static string timeGenerator(bool);
    static string toString(short);
	static bool generatePerc(short);
    static string generateMistakes();
    static string generateDocumentNumber();
    static char randomForMistakes(char);
    static char stampDegenerator(char);
};

