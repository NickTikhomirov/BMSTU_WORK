#ifndef TEXTBUTTON_H
#define TEXTBUTTON_H

#include <QGraphicsTextItem>
#include <string>

#include "Logic/ItemLockable.h"

using std::string;

class TextButton: public QGraphicsTextItem, public ItemLockable
{
    Q_OBJECT
    char size;
public:
    TextButton(string t, char s, bool col=false ,bool style=true, char commentary=-1);
    string text;
    char val;
    char cloud;
    void lock();
    void unlock();
private:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void clicked(char);
    void sendCloud(int,int,char);
};

#endif // TEXTBUTTON_H
