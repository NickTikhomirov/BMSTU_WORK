#include "SwitchingButton.h"
#include <exception>
#include <QTextStream>

using std::to_string;
SwitchingButton::SwitchingButton(short n, bool k, QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    ItemLockable();
    id=n;
    setState(2*k,true);
    setAcceptHoverEvents(true);
    setEnabled(true);
    //3 for pressed
    //2 for not free

}

void SwitchingButton::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(isFree()){
        if(param%3==0) {
            setState(1,true);
            emit disable();
        } else {
            setState(3,true);
            emit enable();
        }
    }
}

void SwitchingButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    if(isFree()){
        if(param%3==0) setState(3);
        else setState(1);
    }
}

void SwitchingButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    if(isFree()){
        if(param%3==0) setState(2);
        else setState(0);
    }
}



void SwitchingButton::setState(char a, bool force){
    QString p;
    if(a>1){
        if(force)
            if(param%3!=0) param*=3;
        if(a==2) p=QString::fromStdString("://main//Pictures//switches//SwB-"+to_string(id)+".png");
        else p=QString::fromStdString("://main//Pictures//switches//SwB-"+to_string(id)+"'.png");
    } else {
        if(force)
            if(param%3==0) param/=3;
        if(a==0) p=QString::fromStdString("://main//Pictures//switches//SwB"+to_string(id)+".png");
        else p=QString::fromStdString("://main//Pictures//switches//SwB"+to_string(id)+"'.png");
    }
    setPixmap(QPixmap(p));
}

void SwitchingButton::update_b(char){}
