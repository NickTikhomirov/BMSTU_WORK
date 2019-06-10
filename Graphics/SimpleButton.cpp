#include "SimpleButton.h"
#include "Resizer.h"

using std::to_string;


SimpleButton::SimpleButton(short v, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem (parent)
{
    QString p = QString::fromStdString("://b//Pictures//buttons//id"+to_string(v)+".png");
    setPixmap(Resizer::m(QPixmap(p),2));
    setEnabled(true);
    free=true;
}


void SimpleButton::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(free) emit clicked();
}
