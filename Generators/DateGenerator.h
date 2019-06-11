#ifndef DATEGENERATOR_H
#define DATEGENERATOR_H


#include <vector>
#include "Logic/Date.h"

using std::vector;

class DateGenerator
{
public:
    vector<Date> dates;
    DateGenerator();
    void generate(char p=0);

    /*
    void generateYear(char);
    void generateMonth();
    void generateDay(char);
    void initBad();
public:

    DateGenerator(short,short,short);
    short d;
    short m;
    short y;

    static DateGenerator d_today();
    static string today();
    static short getDays(short);
    string toString();
    void regenerate();

    static string generateBad();
    static string birthDate();

    DateGenerator operator[](short);
    */
};

#endif // DATEGENERATOR_H
