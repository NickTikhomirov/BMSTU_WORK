#include "SimpleButton.h"

using std::to_string;


SimpleButton::SimpleButton(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem (parent)
{
    ItemLockable();
}


void SimpleButton::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(isFree())
        if(val==0) emit clicked('P',0);
        else emit clicked(val);
}



void SimpleButton::regenerate(char a){
    QPixmap p = QPixmap(QString::fromStdString("://main//Pictures//these_guys//g"+to_string(a)+".png"));
    setPixmap(p);
}
