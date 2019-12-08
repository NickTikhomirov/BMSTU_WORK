#include "SwitchingButton.h"
#include <exception>
#include <QTextStream>

using std::to_string;

/*!
    Конструктор кнопки-переключателя.
    \param n Номер изображения (в пространстве переключателей).
    \param k Должна ли кнопка гасить себя после нажатия на неё.
    \param commentary Номер облачка для объекта класса Follower.
*/
SwitchingButton::SwitchingButton(short n, bool k, char commentary, QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    ItemLockable();
    id=n;
    cloud=commentary;
    setState(2*k,true);
    setAcceptHoverEvents(true);
    setEnabled(true);
    //3 for pressed
    //2 for not free

}



/*!
    События нажатия на кнопку. Она проверяет себя на блокировку, меняет состояние (текстуру) и испускает соответствующий сигнал.
*/
void SwitchingButton::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(isFree()){
        if(param%3==0) {
            setState(1,true);
            emit disable();
        } else {
            setState(3,true);
            emit enable();
        }
    }
}

/*!
    События наведения на кнопку. Она проверяет себя на блокировку, меняет состояние (текстуру).
*/
void SwitchingButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    if(isFree()){
        if(param%3==0) setState(3);
        else setState(1);
    }
}

/*!
    События отведения мыши с кнопки. Она проверяет себя на блокировку, меняет состояние (текстуру).
*/
void SwitchingButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    if(isFree()){
        if(param%3==0) setState(2);
        else setState(0);
    }
}



/*!
    События проведения мышью по кнопке. Она проверяет себя на блокировку и испускает сигнал, предназначенный для объекта класса Follower.
*/
void SwitchingButton::hoverMoveEvent(QGraphicsSceneHoverEvent *event){
    if(cloud>0 && isFree()) emit sendCloud(x()+event->pos().toPoint().x(),y()+event->lastPos().toPoint().y(),cloud);
}



/*!
    Внутренний метод изменения состояния кнопки (включено/выключено, подсвечено/погашено)
    \param a 0: выкл, тусклая. 1: выкл, яркая. 2: вкл., тусклая. 3: вкл, яркая.
    \param force В случае истины также будет выравнивать её состояние под внешний вид
*/
void SwitchingButton::setState(char a, bool force){
    QString p;
    if(a>1){
        if(force)
            if(param%3!=0) param*=3;
        if(a==2) p=QString::fromStdString("://main//Pictures//switches//SwB-"+to_string(id)+".png");
        else p=QString::fromStdString("://main//Pictures//switches//SwB-"+to_string(id)+"'.png");
    } else {
        if(force)
            if(param%3==0) param/=3;
        if(a==0) p=QString::fromStdString("://main//Pictures//switches//SwB"+to_string(id)+".png");
        else p=QString::fromStdString("://main//Pictures//switches//SwB"+to_string(id)+"'.png");
    }
    setPixmap(QPixmap(p));
}

void SwitchingButton::update_b(char){}
