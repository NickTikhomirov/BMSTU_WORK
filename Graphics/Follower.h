#ifndef FOLLOWER_H
#define FOLLOWER_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Follower : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Follower(QGraphicsItem *par=0);
public slots:
    void drawAt(int,int,char);
    void hider();
};

#endif // FOLLOWER_H
