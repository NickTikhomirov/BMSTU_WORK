#include "Background.h"

using std::to_string;

/*!
    Конструктор изображения.
    \param n Номер изображения в пространстве фонов.
*/
Background::Background(char n,QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    setAcceptHoverEvents(true);
    setPos(0,0);
    setPixmap(QString::fromStdString("://main//Pictures//backgrounds//fon"+to_string(n)+".png"));
}


/*!
    Событие наведения. Фон оповещает, когда игрок наводит на него курсор, переводя его с кнопки.
*/void Background::hoverMoveEvent(QGraphicsSceneHoverEvent *event){
    emit tingle();
    QGraphicsPixmapItem::hoverMoveEvent(event);
}
