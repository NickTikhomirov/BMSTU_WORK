#ifndef SIMPLEBUTTON_H
#define SIMPLEBUTTON_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>


#include "Logic/ItemLockable.h"


class SimpleButton: public QObject, public QGraphicsPixmapItem, public ItemLockable{
    Q_OBJECT
public:
    explicit SimpleButton(QGraphicsItem *parent = nullptr);
    char val;
private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:
    void clicked(char);
    void clicked(char,char);
public slots:
    void regenerate(char);
};

#endif // SIMPLEBUTTON_H
