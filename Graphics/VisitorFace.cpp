#include "VisitorFace.h"

using std::to_string;

VisitorFace::VisitorFace(char face,QGraphicsItem *par): QObject(), QGraphicsPixmapItem(par)
{
    id=face;
    regenerate();
}

void VisitorFace::regenerate(){
    QPixmap p = QPixmap(QString::fromStdString("C:\\qtprojects\\ht2\\Pictures\\these_guys\\Паспорт"+to_string(id)+".png"));
    setPixmap(p);
}


void VisitorFace::regenerate_but_it_is_a_slot(){
    regenerate();
}
