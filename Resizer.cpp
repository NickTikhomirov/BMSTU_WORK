#include "Resizer.h"
#include <cmath>

Resizer::Resizer()
{

}


/*!
   Увеличивает целое число в дробное число раз и округляет.
   \param a Число
   \param p Порядок
*/
int Resizer::m(int a, double p){
    return (p>0)?round(a*p):a;
}

/*!
   Увеличивает целое число в 2 раза.
   \param a Число
*/
int Resizer::d(int a){
    return m(a,2);
}

/*!
   Увеличивает изображение по обеим осям в дробное число раз.
   \param q Изображение
   \param p Порядок
*/
QPixmap Resizer::m(QPixmap q, double p){
    q=q.scaled(m(q.width(),p), m(q.height(),p));
    return q;
}

/*!
   Увеличивает изображение в два раза.
   \param q Изображение
*/
QPixmap Resizer::d(QPixmap q){
    return m(q,2);
}
