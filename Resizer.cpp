#include "Resizer.h"

Resizer::Resizer()
{

}


int Resizer::m(int a, short p){
    return (p>0)?a*p:a;
}

int Resizer::d(int a){
    return m(a,2);
}


QPixmap Resizer::m(QPixmap q, short p){
    q=q.scaled(m(q.width(),p), m(q.height(),p));
    return q;
}


QPixmap Resizer::d(QPixmap q){
    return m(q,2);
}
