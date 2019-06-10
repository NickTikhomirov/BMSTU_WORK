#include "Graphics\TextButton.h"
#include <QFont>
#include <QFontDatabase>


TextButton::TextButton(string t, char s, bool col ,bool style)
{
    text=t;
    val=0;
    size=s;
    ItemLockable();

    setPlainText(QString::fromStdString(text));
    if(style){
        QFont o("Arial");
        o.setPixelSize(s);
        param *= 3;
        setFont(o);
    } else {
        QFont o("Comic Sans");
        o.setPixelSize(s);
        setFont(o);
    }

    if(col){
        setDefaultTextColor(Qt::darkGreen);
        param*=5;
    } else
        setDefaultTextColor(Qt::black);
}


void TextButton::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(isFree()) emit clicked(val);
}

void TextButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    if(param%11!=0)
        if(param%5==0)setDefaultTextColor(Qt::green);
        else setDefaultTextColor(Qt::darkGray);
}

void TextButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    if(param%11!=0)
        if(param%5==0) setDefaultTextColor(Qt::darkGreen);
        else setDefaultTextColor(Qt::black);
}

void TextButton::lock(){
    safe_lock();
}

void TextButton::unlock(){
    unlock();
}
