#ifndef NAMEGENERATOR_H
#define NAMEGENERATOR_H
#include <string>

using std::string;

class NameGenerator{
public:
    static string generateName();
    static string generateName2();
    static string generateCountry();
    static string generateBadCountry();
    static string degenerateName(string);
};

#endif // NAMEGENERATOR_H
