#ifndef VERYCOMPLICATEDBUTTON_H
#define VERYCOMPLICATEDBUTTON_H

#include "SwitchingButton.h"
#include "Logic\Level.h"
#include "Graphics\TextButton.h"

class VeryComplicatedButton: public SwitchingButton
{
public:
    TextButton *t;
    VeryComplicatedButton(Level *l1, short n, QGraphicsItem *parent = nullptr);
    Level *l;
public slots:
    void update_b();
private:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // VERYCOMPLICATEDBUTTON_H
