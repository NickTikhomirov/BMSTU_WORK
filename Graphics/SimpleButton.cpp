#include "SimpleButton.h"
#include "Resizer.h"
#include "Generators/StampGenerator.h"

using std::to_string;


SimpleButton::SimpleButton(short n, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem (parent)
{
    bool mode = true;
    // Истина: реальное лицо или правильная печать
    // Ложь: фото или подделка
    bool target = true;
    // Истина: лицо
    // Ложь: печать
    if(n<0){
        mode = false;
        n*=-1;
    }
    if(n>'A' && n<'Z'){
        target = false;
        val=11;
    }
    if(mode && target) val = -n;
    if(!mode && target) val = 7;
    if(!target) setPixmap(Resizer::m(StampGenerator::generate(n,mode),2));
    else{
        if(!mode)
            if(false) n=-n;
        QPixmap p = QPixmap(QString::fromStdString("://main//Pictures//these_guys//g"+to_string(n)+".png"));
        setPixmap(Resizer::m(p,(mode)?1:0.375));
    }
    setEnabled(true);
    free=true;
}


void SimpleButton::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(free)
        if(val<0) emit clicked('H',0);
        else emit clicked(val);
}


void SimpleButton::regenerate(){
    QPixmap p = QPixmap(QString::fromStdString("://main//Pictures//these_guys//g"+to_string(-val)+".png"));
    setPixmap(p);
}
