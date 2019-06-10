#ifndef SIMPLEBUTTON_H
#define SIMPLEBUTTON_H



#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>


class SimpleButton: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
    bool free;
public:
    explicit SimpleButton(short n, QGraphicsItem *parent = nullptr);
private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:
    void clicked();
};

#endif // SIMPLEBUTTON_H
