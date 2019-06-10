#include "TwinButtons.h"

TwinButtons::TwinButtons(){
    left = new CustomButton(2, true);
    left->setPos(427,366);

    right = new CustomButton(3);
    right->setPos(461,366);
    ennul();
    connect(right,SIGNAL(clicked()), this, SLOT(analyze_incorrect()));
    connect(left,SIGNAL(clicked()), this, SLOT(analyze_correct()));

}


void TwinButtons::analyze_incorrect(){
    score++;
    score*=-1;
    emit result(score);
}


void TwinButtons::analyze_correct(){
    emit result(score);
}


void TwinButtons::score_increase(){
    unlock();
    score++;
}


void TwinButtons::lock(){
    right->safe_lock();
    right->setPixmap(QPixmap(QString("://b//Pictures//buttons//id0.png")));
}

void TwinButtons::unlock(){
    right->unlock();
    right->setPixmap(QPixmap(QString("://b//Pictures//buttons//id3.png")));
}

void TwinButtons::ennul(){
    score =0;
    lock();
}
