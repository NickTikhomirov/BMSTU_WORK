#include "Follower.h"

Follower::Follower(QGraphicsItem *par): QGraphicsPixmapItem(par)
{
    ItemLockable();
}

using std::to_string;

void Follower::drawAt(int xm, int ym, char s){
    if(!isFree()) return;
    setPixmap(QPixmap(QString::fromStdString("://main//Pictures//other//cloud"+to_string(s)+".png")));
    recount(xm,ym,s);
    setPos(xm,ym);
    show();
}


int Follower::getWidth(char a){
    return (QPixmap(QString::fromStdString("://main//Pictures//other//cloud"+to_string(a)+".png"))).width();
}

int Follower::getHeight(char a){
    return (QPixmap(QString::fromStdString("://main//Pictures//other//cloud"+to_string(a)+".png"))).height();
}


void Follower::recount(int &x1, int &y1, char s1){
    if(s1==11){
        x1=80;
        y1=350;
        return;
    }
    int h = getHeight(s1);
    int w = getWidth(s1);
    y1-=h;
    if(y1<3) y1+=h+7;
    if(x1+w>509) x1-=w-7;
}


void Follower::hider(){
    hide();
}

void Follower::f_lock(){
    hide();
    safe_lock();
}

void Follower::f_unlock(){
    unlock();
}
