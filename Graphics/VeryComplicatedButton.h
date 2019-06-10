#ifndef VERYCOMPLICATEDBUTTON_H
#define VERYCOMPLICATEDBUTTON_H

#include "SwitchingButton.h"
#include "Logic\Level.h"
#include "Graphics\TextButton.h"

class VeryComplicatedButton: public SwitchingButton
{
    Q_OBJECT
public:
    TextButton *t;
    VeryComplicatedButton(Level *l1, short n, QGraphicsItem *parent = nullptr);
    Level *l;
signals:
    void time_pressed(char,char);
public slots:
    void update_b();
    void track_time();
private:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // VERYCOMPLICATEDBUTTON_H
