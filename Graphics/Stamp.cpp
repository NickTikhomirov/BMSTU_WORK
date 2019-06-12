#include "Stamp.h"

Stamp::Stamp(char n,double k,bool corr,QGraphicsItem *parent): SimpleButton(parent)
{
    char p;
    if(n=='P') p=5;
    if(n=='M') {
        if(rand()%2)p=7;
        else p=8;
    }
    if(n=='R') p=6;
    if(!corr)
        p=Randomizer::stampDegenerator(p);
    QPixmap p1 = QPixmap(QString::fromStdString("://b//Pictures//buttons//id"+to_string(p)+".png"));
    setPixmap(Resizer::m(p1,k));
}
