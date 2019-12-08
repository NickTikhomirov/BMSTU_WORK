#ifndef RESIZER_H
#define RESIZER_H

#include <QPixmap>


/*!
    \brief Класс изменения размеров изображений.

    Позволяет приемлемым образом изменять размеры изображений в заданное число раз, однако эта технология нигде не была использована за ненадобностью.
*/
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
