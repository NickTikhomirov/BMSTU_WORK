#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <string>

#include <QGraphicsPixmapItem>

#include "Graphics/CustomButton.h"
#include "Graphics/TextButton.h"

using std::string;

/*!
    \brief Класс, хранящий все составляющие всплывающего окна

    Этот класс хранит кнопку, текст и несколько картинок, из которых составляется всплывающее окно, а также в нём хранится строка,
    являющаяся текстом этого окна по умолчанию. Важно понимать, что класс только хранит всё это. Основную работу по отображению окна производит класс Game.
*/
class SubWindow
{
public:
    SubWindow();
    ~SubWindow();
    string credits;
    QGraphicsPixmapItem *darkness;
    QGraphicsPixmapItem *box;
    CustomButton *krestik;
    TextButton *t;

};

#endif // SUBWINDOW_H
