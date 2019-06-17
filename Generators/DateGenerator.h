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
};

#endif // DATEGENERATOR_H
