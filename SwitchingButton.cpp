#include "SwitchingButton.h"
#include <exception>
#include <QTextStream>

using std::to_string;
SwitchingButton::SwitchingButton(short n, QGraphicsItem *parent)
{
    ItemLockable();
    reInit(n);
    setAcceptHoverEvents(true);
    setEnabled(true);
    //3 for pressed
    //2 for not free

}

void SwitchingButton::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(isFree()){
        if(param%3==0) {
            QString p = QString::fromStdString("://main//Pictures//switches//SwB"+to_string(id)+"'.png");
            setPixmap(QPixmap(p));
            param/=3;
            emit disable();
        } else {
            QString p = QString::fromStdString("://main//Pictures//switches//SwB-"+to_string(id)+"'.png");
            setPixmap(QPixmap(p));
            param*=3;
            emit enable();
        }
    }
}

void SwitchingButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    if(isFree()){
        if(param%3==0){
            QString p = QString::fromStdString("://main//Pictures//switches//SwB-"+to_string(id)+"'.png");
            setPixmap(QPixmap(p));
        } else {
            QString p = QString::fromStdString("://main//Pictures//switches//SwB"+to_string(id)+"'.png");
            setPixmap(QPixmap(p));
        }
    }
}

void SwitchingButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    if(isFree()){
        if(param%3==0){
            QString p = QString::fromStdString("://main//Pictures//switches//SwB-"+to_string(id)+".png");
            setPixmap(QPixmap(p));
        } else {
            QString p = QString::fromStdString("://main//Pictures//switches//SwB"+to_string(id)+".png");
            setPixmap(QPixmap(p));
        }
    }
}


void SwitchingButton::reInit(short n){
    QGraphicsPixmapItem();
    id=n;
    QString p = QString::fromStdString("://main//Pictures//switches//SwB"+to_string(n)+".png");
    setPixmap(QPixmap(p));
}

void SwitchingButton::update_b(){}
