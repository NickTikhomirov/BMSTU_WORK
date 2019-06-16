#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Background : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Background(char n=0,QGraphicsItem *parent = nullptr);
private:
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void tingle();
    void sendCloud(int,int,char);
};

#endif // BACKGROUND_H
