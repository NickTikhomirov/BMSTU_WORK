#ifndef SWITCHINGBUTTON_H
#define SWITCHINGBUTTON_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QMediaPlayer>
#include <QMediaPlaylist>

#include "Logic/ItemLockable.h"

class SwitchingButton: public QObject, public QGraphicsPixmapItem, public ItemLockable
{
     Q_OBJECT
public:
    short id;
    char cloud;
    explicit SwitchingButton(short n, bool k=false, char commentary=-1, QGraphicsItem *parent = nullptr);
    void setState(char, bool force=false);
public slots:
    virtual void update_b(char);
private:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void enable();
    void disable();
    void sendCloud(int,int,char);
};

#endif // SWITCHINGBUTTON_H
