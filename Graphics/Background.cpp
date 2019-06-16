#include "Background.h"

using std::to_string;

Background::Background(char n,QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    setAcceptHoverEvents(true);
    setPos(0,0);
    setPixmap(QString::fromStdString("://main//Pictures//backgrounds//fon"+to_string(n)+".png"));
}


void Background::hoverMoveEvent(QGraphicsSceneHoverEvent *event){
    emit tingle();
    QGraphicsPixmapItem::hoverMoveEvent(event);
}
