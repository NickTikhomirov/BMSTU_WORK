#include "CustomButton.h"

using std::to_string;

/*!
    Конструктор кнопки.
    \param v Номер изображения в пространстве кнопок.
    \param self_offing Должна ли кнопка переключаться на погасшую текстуру после клика.
    \param commentary Номер облачка для объекта класса Follower.
*/
CustomButton::CustomButton(short v, bool self_offing, char commentary, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem (parent)
{
    ItemLockable();
    if(self_offing) param*=5;
    id=v;
    cloud = commentary;
    QString p = QString::fromStdString("://b//Pictures//buttons//id"+to_string(v)+".png");
    setPixmap(QPixmap(p));
    setAcceptHoverEvents(true);
    setEnabled(true);
}


/*!
    Событие нажатия на кнопку. Кнопка проверяет себя на свободность, гасит себя при необходимости и подаёт сигнал о нажатии.
*/
void CustomButton::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(isFree()) {
        if(param%5==0) {
            QString p = QString::fromStdString("://b//Pictures//buttons//id"+to_string(id)+".png");
            setPixmap(QPixmap(p));
        }
        emit clicked();
    }
}


/*!
  Событие наведения на кнопку. Она проверяет себя на свободность и меняет внешний вид.
*/
void CustomButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    if(isFree()){
        QString p = QString::fromStdString("://b//Pictures//buttons//id-"+to_string(id)+".png");
        setPixmap(QPixmap(p));
    }
}

/*!
  Событие отведения мыши с кнопки. Она проверяет себя на свободность и меняет внешний вид.
*/
void CustomButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    if(isFree()){
        QString p = QString::fromStdString("://b//Pictures//buttons//id"+to_string(id)+".png");
        setPixmap(QPixmap(p));
    }
}

/*!
  Событие перемещения мыши по кнопке. Она проверяет себя на свободность и подаёт сигнал, который принимает объект класса Follower.
*/
void CustomButton::hoverMoveEvent(QGraphicsSceneHoverEvent *event){
    if(cloud>0 && isFree()) emit sendCloud(x()+event->pos().toPoint().x(),y()+event->lastPos().toPoint().y(),cloud);
}


/*!
  Слот закрытия, привязанный к методу интерфейса ItemLockable.
*/
void CustomButton::lock(){
    safe_lock();
}

/*!
  Слот открытия, привязанный к методу интерфейса ItemLockable.
*/
void CustomButton::unlock_s(){
    unlock();
}
