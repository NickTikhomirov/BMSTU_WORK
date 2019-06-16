#include "CustomButton.h"

using std::to_string;

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

void CustomButton::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(isFree()) {
        if(param%5==0) {
            QString p = QString::fromStdString("://b//Pictures//buttons//id"+to_string(id)+".png");
            setPixmap(QPixmap(p));
        }
        emit clicked();
    }
}

void CustomButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    if(isFree()){
        QString p = QString::fromStdString("://b//Pictures//buttons//id-"+to_string(id)+".png");
        setPixmap(QPixmap(p));
    }
}
void CustomButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    if(isFree()){
        QString p = QString::fromStdString("://b//Pictures//buttons//id"+to_string(id)+".png");
        setPixmap(QPixmap(p));
    }
}

void CustomButton::hoverMoveEvent(QGraphicsSceneHoverEvent *event){
    if(cloud>0 && isFree()) emit sendCloud(x()+event->pos().toPoint().x(),y()+event->lastPos().toPoint().y(),cloud);
}



void CustomButton::lock(){
    safe_lock();
}

void CustomButton::unlock_s(){
    unlock();
}
