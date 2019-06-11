#ifndef RESIZER_H
#define RESIZER_H

#include <QPixmap>


class Resizer
{
public:
    Resizer();
    static int d(int);
    static QPixmap d(QPixmap);
    static int m(int, double);
    static QPixmap m(QPixmap, double);
};

#endif // RESIZER_H
