#include "VeryComplicatedButton.h"

using std::to_string;

VeryComplicatedButton::VeryComplicatedButton(Level *l1, short n, QGraphicsItem *parent): SwitchingButton(n,parent)
{
   l=l1;
   if(l!=0) t = new TextButton(l->time,12,true,true,10);
   else t=new TextButton("0",12,true);
   connect(t,SIGNAL(clicked(char)),this,SLOT(track_time()));
}


void VeryComplicatedButton::update_b(char){
    if(param%3==0) {
        QString p = QString::fromStdString("://main//Pictures//switches//SwB"+to_string(id)+".png");
        setPixmap(QPixmap(p));
        param/=3;
    }
    if(l!=0) t->setPlainText(QString::fromStdString(l->time));
    else t->setPlainText("0");
}


void VeryComplicatedButton::track_time(){
    emit time_pressed('H',5);
}




void VeryComplicatedButton::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(isFree()){
        if(param%3==0) {
            QString p = QString::fromStdString("://main//Pictures//switches//SwB"+to_string(id)+"'.png");
            setPixmap(QPixmap(p));
            param/=3;
            if(l!=0) t->setPlainText(QString::fromStdString(l->time));
            else t->setPlainText("0");
            //emit disable();
        } else {
            QString p = QString::fromStdString("://main//Pictures//switches//SwB-"+to_string(id)+"'.png");
            setPixmap(QPixmap(p));
            param*=3;
            if(l!=0) t->setPlainText(QString::fromStdString(l->mistakes->toString()));
            else t->setPlainText("1");
            //emit enable();
        }
    }
}

void VeryComplicatedButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
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

void VeryComplicatedButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
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


