#include "Face.h"


/*!
  Конструктор изображения.
  \param n Номер изображения в пространстве лиц.
  \param k Коэффициент уменьшения изображения, используется в документах. Если k<1, то берётся не лицо, а фото.
  \param corr Если передать в это поле false, то будет сгенерировано любое лицо, только не с номером n.
*/
Face::Face(char n,double k,bool corr,QGraphicsItem *parent): SimpleButton(parent)
{
    if(!corr){
        char r;
        do r=Randomizer::randInPool(1,17);
        while(r==n);
        n=r;
    }
    val=0;
    if(k<1) n=-n;
    QPixmap p = QPixmap(QString::fromStdString("://main//Pictures//these_guys//g"+to_string(n)+".png"));
    setPixmap(Resizer::m(p,k));
}


/*!
  Пересоздаёт изображение, заменяя его на новое под номером a.
  \param a Номер изображения в пространстве лиц.
*/
void Face::regenerate(char a){
    QPixmap p = QPixmap(QString::fromStdString("://main//Pictures//these_guys//g"+to_string(a)+".png"));
    setPixmap(p);
}
