#ifndef DATE_H
#define DATE_H

#include <string>
#include "Generators/Randomizer.h"

using std::string;
using std::to_string;


/*!
    \brief Класс одиночной даты. Используется при генерации набора дат классом DateGenerator.

    Дата может быть ошибочной (31 апреля), поэтому нельзя использовать какие-либо из уже реализованных классов дат-времени.
    Процесс генерации реализовывался с большим трудом и не с первого раза, поэтому в случае этого класса принцип "работает - не трогай" побеждает правило делать всё понятно.
*/

class Date
{
    static bool longMonth(int);
public:
    Date();
    Date(int,int,int);

    int day;
    int month;
    int year;
    friend bool operator<(const Date &l, const Date &r);
    friend bool operator>(const Date &l, const Date &r);
    friend void operator^(Date &l,bool r);
    friend Date operator<<=(int a, const Date &r);
    friend Date operator>>=(const Date &l,int a);
    friend Date operator<<(Date l, Date r);
    friend Date operator~(Date);
    friend Date operator|=(const Date &l, const Date &r);
    operator string();

    void operator+();
    void operator-();

    void operator++(int);
    void operator++();
    void operator--();
};

#endif // DATE_H
