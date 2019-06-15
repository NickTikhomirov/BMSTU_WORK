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
    explicit SwitchingButton(short n, bool k=false, QGraphicsItem *parent = nullptr);
    void setState(char, bool force=false);
public slots:
    virtual void update_b(char);
private:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:
    void enable();
    void disable();
};

#endif // SWITCHINGBUTTON_H
