#ifndef DATEGENERATOR_H
#define DATEGENERATOR_H
#include <string>

using std::string;


class DateGenerator
{
    void generateYear(char);
    void generateMonth();
    void generateDay(char);
public:
    DateGenerator();
    DateGenerator(short,short,short);
    short d;
    short m;
    short y;

    //static string toString(short);
    static DateGenerator d_today();
    static short getDays(short);
    string toString();
    void generateBad();
    void regenerate();

    static string birthDate();

    DateGenerator operator[](short);
};

#endif // DATEGENERATOR_H
