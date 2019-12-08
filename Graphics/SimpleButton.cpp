#include "SimpleButton.h"

using std::to_string;

/*!
    Конструктор простейшей кнопки
*/
SimpleButton::SimpleButton(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem (parent)
{
    ItemLockable();
}


/*!
    Событие нажатия на кнопку. Она проверяет себя на блокировку и излучает сигнал.
*/
void SimpleButton::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(isFree())
        if(val==0) emit clicked('P',0);
        else emit clicked(val);
}



/*!
    Метод обновления кнопки на заданную текстуру
    \param a Номер текстуры кнопки в пространстве людей (так как на практике это нужнее всего)
*/
void SimpleButton::regenerate(char a){
    QPixmap p = QPixmap(QString::fromStdString("://main//Pictures//these_guys//g"+to_string(a)+".png"));
    setPixmap(p);
}
