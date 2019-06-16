#include "TwinButtons.h"

TwinButtons::TwinButtons(){
    left = new CustomButton(2, true, 6);
    left->setPos(420,366);

    right = new CustomButton(3,true,8);
    right->setPos(440,366);

    tech = new CustomButton(0,false,7);
    tech->setPos(440,366);
    ennul();
    connect(right,SIGNAL(clicked()), this, SLOT(analyze_incorrect()));
    connect(left,SIGNAL(clicked()), this, SLOT(analyze_correct()));

}

TwinButtons::~TwinButtons(){
    delete right;
    delete left;
    delete tech;
    right=0;
    left=0;
    tech=0;
}



void TwinButtons::analyze_incorrect(){
    score++;
    score*=-1;
    emit result(score);
    ennul();
}


void TwinButtons::analyze_correct(){
    emit result(score);
    ennul();
}


void TwinButtons::forceFinish(){
    emit result(100);
    ennul();
}

void TwinButtons::score_increase(){
    unlock();
    score++;
}


void TwinButtons::lock(){
    right->safe_lock();
    tech->unlock();
    right->hide();
    tech->show();
}

void TwinButtons::unlock(){
    right->unlock();
    tech->safe_lock();
    tech->hide();
    right->show();
}

void TwinButtons::ennul(){
    score =0;
    lock();
}
