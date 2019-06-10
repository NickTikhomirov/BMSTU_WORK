#ifndef VISITORFACE_H
#define VISITORFACE_H

#include <QGraphicsPixmapItem>


class VisitorFace: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    char id;
    VisitorFace(char face=1,QGraphicsItem *par=0);
    void regenerate();
public slots:
    void regenerate_but_it_is_a_slot();
};

#endif // VISITORFACE_H
