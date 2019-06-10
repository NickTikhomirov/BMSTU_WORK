#include "TwinButtons.h"

TwinButtons::TwinButtons(){
    left = new CustomButton(2, true);
    left->setPos(427,366);

    right = new CustomButton(3);
    right->setPos(461,366);
    lock();
    connect(right,SIGNAL(clicked()), this, SLOT(analyze_incorrect()));
    connect(left,SIGNAL(clicked()), this, SLOT(analyze_correct()));

}


void TwinButtons::analyze_incorrect(){
    emit result(-1);
}


void TwinButtons::analyze_correct(){
    emit result(1);
}

void TwinButtons::lock(){
    right->safe_lock();
    right->setPixmap(QPixmap(QString("C:\\qtprojects\\ht2\\id0.png")));
}

void TwinButtons::unlock(){
    right->unlock();
    right->setPixmap(QPixmap(QString("C:\\qtprojects\\ht2\\id3.png")));
}

void TwinButtons::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){}

QRectF TwinButtons::boundingRect() const{
    return QRectF(0,0,0,0);
}
