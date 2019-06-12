#ifndef STAMP_H
#define STAMP_H

#include "SimpleButton.h"
#include "Generators/Randomizer.h"
#include "Resizer.h"

using std::to_string;

class Stamp : public SimpleButton
{
    Q_OBJECT
public:
    Stamp(char,double k=1,bool corr=true,QGraphicsItem *parent = nullptr);
};

#endif // STAMP_H
