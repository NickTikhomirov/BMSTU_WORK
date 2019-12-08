#include "Graphics/TextButton.h"
#include <QFont>


/*!
       Конструктор текстовой кнопки.
       \param t Текст на кнопке.
       \param s Размер текста.
       \param col 1:зелёный, 0: чёрный.
       \param style 1:Arial, 0:Comic Sans MS.
       \param commentary Номер облачка для объекта класса Follower.
*/
TextButton::TextButton(string t, char s, bool col ,bool style, char commentary)
{
    text=t;
    val=0;
    size=s;
    cloud=commentary;
    ItemLockable();

    setPlainText(QString::fromStdString(text));
    if(style){
        QFont o("Arial");
        o.setPixelSize(s);
        param *= 3;
        setFont(o);
    } else {
        QFont o("Comic Sans MS");
        o.setPixelSize(s);
        setFont(o);
    }

    if(col){
        setDefaultTextColor(Qt::darkGreen);
        param*=5;
    } else
        setDefaultTextColor(Qt::black);
}


/*!
    Событие нажатия на кнопку. Кнопка проверяет себя на свободность и подаёт сигнал о нажатии.
*/
void TextButton::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(isFree()) emit clicked(val);
}


/*!
  Событие наведения на кнопку. Она проверяет себя на свободность и меняет внешний вид.
*/
void TextButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    if(param%11!=0)
        if(param%5==0)setDefaultTextColor(Qt::green);
        else setDefaultTextColor(Qt::darkGray);
}


/*!
  Событие отведения мыши с кнопки. Она проверяет себя на свободность и меняет внешний вид.
*/
void TextButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    if(param%11!=0)
        if(param%5==0) setDefaultTextColor(Qt::darkGreen);
        else setDefaultTextColor(Qt::black);
}


/*!
  Событие перемещения мыши по кнопке. Она проверяет себя на свободность и подаёт сигнал, который принимает объект класса Follower.
*/
void TextButton::hoverMoveEvent(QGraphicsSceneHoverEvent *event){
    if(cloud>0 && isFree()) emit sendCloud(x()-10,y()+3,cloud);
}



/*!
  Слот закрытия, привязанный к методу интерфейса ItemLockable.
*/
void TextButton::lock(){
    safe_lock();
}



/*!
  Слот открытия, привязанный к методу интерфейса ItemLockable.
*/
void TextButton::unlock(){
    ItemLockable::unlock();
}
