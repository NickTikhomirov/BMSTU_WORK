#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>


#include "Logic/ItemLockable.h"

class CustomButton : public QObject, public QGraphicsPixmapItem, public ItemLockable{
    Q_OBJECT
public:
    explicit CustomButton(short n, bool self_offing=false,QGraphicsItem *parent = nullptr);
    short id;
    char cloud;
private:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
public slots:
    void lock();
    void unlock_s();
signals:
    void clicked();
    void sendCloud(int,int,char);
    void hideCloud();
};

#endif // CUSTOMBUTTON_H
