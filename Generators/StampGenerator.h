#ifndef STAMPGENERATOR_H
#define STAMPGENERATOR_H

#include <QPixmap>

using std::to_string;


class StampGenerator
{
    static char generate();
    static char generate(char);
    static char generate_not(char);
public:
    static QPixmap generate(char,bool);
};

#endif // STAMPGENERATOR_H
