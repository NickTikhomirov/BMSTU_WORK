#include "Face.h"

Face::Face(char n,double k,bool corr,QGraphicsItem *parent): SimpleButton(parent)
{
    if(!corr){
        char r;
        do r=Randomizer::randInPool(1,17);
        while(r==n);
        n=r;
    }
    if(k<1) n=-n;
    QPixmap p = QPixmap(QString::fromStdString("://main//Pictures//these_guys//g"+to_string(n)+".png"));
    setPixmap(Resizer::m(p,k));
}



void Face::regenerate(char a){
    QPixmap p = QPixmap(QString::fromStdString("://main//Pictures//these_guys//g"+to_string(a)+".png"));
    setPixmap(p);
}
