#ifndef RESIZER_H
#define RESIZER_H

#include <QPixmap>


class Resizer
{
public:
    Resizer();
    static int d(int);
    static QPixmap d(QPixmap);
    static int m(int, short);
    static QPixmap m(QPixmap, short);
};

#endif // RESIZER_H
