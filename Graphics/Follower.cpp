#include "Follower.h"

Follower::Follower(QGraphicsItem *par): QGraphicsPixmapItem(par)
{
    ItemLockable();
}

using std::to_string;


/*!
  Рисует облако-подсказку, предварительно пересчитывая координаты с учётом размера окна.
  Считается, что сдвиг с кончика курсора на будущее место отрисовки облака (чуть выше оного) произведен вне функции.
  \param xm X-координата отрисовки
  \param ym Y-координата отрисовки
  \param s Номер спрайта облака в пространстве облаков
*/
void Follower::drawAt(int xm, int ym, char s){
    if(!isFree()) return;
    setPixmap(QPixmap(QString::fromStdString("://main//Pictures//other//cloud"+to_string(s)+".png")));
    recount(xm,ym,s);
    setPos(xm,ym);
    show();
}



/*!
  Получение X-координаты изображения (ширины)
  \param a Номер изображения
*/
int Follower::getWidth(char a){
    return (QPixmap(QString::fromStdString("://main//Pictures//other//cloud"+to_string(a)+".png"))).width();
}


/*!
  Получение Y-координаты изображения (высоты)
  \param a Номер изображения
*/
int Follower::getHeight(char a){
    return (QPixmap(QString::fromStdString("://main//Pictures//other//cloud"+to_string(a)+".png"))).height();
}


/*!
  Пересчёт координат отрисовки с поправкой на размеры окна
  \param x1 X-координата (изменяется функцией)
  \param y1 Y-координата (изменяется функцией)
  \param s1 Номер изображения в пространстве облаков
*/
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
    if(x1+w>509) x1-=w;
}

/*!
  Метод сокрытия отрисованного облака.
*/
void Follower::hider(){
    hide();
}


/*!
  Слот сокрытия и последующей блокировки (класс ItemLockable)
*/
void Follower::f_lock(){
    hide();
    safe_lock();
}


/*!
  Слот разблокировки (класс ItemLockable)
*/
void Follower::f_unlock(){
    unlock();
}
