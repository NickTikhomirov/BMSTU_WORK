#include "SubWindow.h"

SubWindow::SubWindow()
{
    credits =
       string("Автор: Тихомиров Никита, студент ИУ8-23\n\n")+
       string("Посвящаю эту игру своим друзьям, которые \n")+
       "поддерживали меня в процессе разработки:\n"+
       "Горбачёву Алексею\nЕвуле Анджэю\nКильдишеву Жене\nТитову Анатолию\n"+
       "\n\n 2019 год, жаркий июнь";

    darkness = new QGraphicsPixmapItem(QPixmap("://main//Pictures//backgrounds//darkness.png"));
    box = new QGraphicsPixmapItem(QPixmap("://main//Pictures//backgrounds//box.png"));
    krestik = new CustomButton(19, true);
    t = new TextButton(credits,12);
}


SubWindow::~SubWindow(){
    delete t;
    delete box;
    delete darkness;
    delete krestik;
}