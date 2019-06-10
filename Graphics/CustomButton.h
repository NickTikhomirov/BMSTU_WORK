#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
//#include <QGraphicsRectItem>


#include "Logic/ItemLockable.h"

class CustomButton : public QObject, public QGraphicsPixmapItem, public ItemLockable{
    Q_OBJECT
public:
    explicit CustomButton(short n, bool self_offing=false,QGraphicsItem *parent = nullptr);
    short id;
private:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
public slots:
    void lock();
    void unlock_s();
signals:
    void clicked();
};

#endif // CUSTOMBUTTON_H
