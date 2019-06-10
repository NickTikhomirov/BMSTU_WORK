#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <string>

#include <QGraphicsPixmapItem>

#include "Graphics/CustomButton.h"
#include "Graphics/TextButton.h"

using std::string;

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
