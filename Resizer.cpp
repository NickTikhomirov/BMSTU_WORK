#include "Resizer.h"
#include <cmath>

Resizer::Resizer()
{

}


int Resizer::m(int a, double p){
    return (p>0)?round(a*p):a;
}

int Resizer::d(int a){
    return m(a,2);
}


QPixmap Resizer::m(QPixmap q, double p){
    q=q.scaled(m(q.width(),p), m(q.height(),p));
    return q;
}


QPixmap Resizer::d(QPixmap q){
    return m(q,2);
}
