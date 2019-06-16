#include "Follower.h"

Follower::Follower(QGraphicsItem *par): QGraphicsPixmapItem(par)
{

}

using std::to_string;

void Follower::drawAt(int xm, int ym, char s){
    setPixmap(QPixmap(QString::fromStdString("://main//Pictures//other//cloud"+to_string(s)+".png")));
    setPos(xm+10,ym+50);
    show();
}


void Follower::hider(){
    hide();
}
