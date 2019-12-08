#include "SubWindow.h"


/*!
  Инициализация объектов окна
*/
SubWindow::SubWindow()
{
    credits =
       string("Автор: Тихомиров Никита, студент ИУ8-33\n\n")+
       "Посвящаю эту игру своим друзьям, кото-\nрые "+
       "поддерживали меня в процессе \nразработки:\n"+
       "Горбачёву Алексею\nЕвула Анджэю\nКильдишеву Жене\nТитову Анатолию\n"+
       "\n\n 2019 год, осень";

    darkness = new QGraphicsPixmapItem(QPixmap("://main//Pictures//backgrounds//darkness.png"));
    box = new QGraphicsPixmapItem(QPixmap("://main//Pictures//backgrounds//box.png"));
    krestik = new CustomButton(19, true);
    t = new TextButton(credits,12);
}

/*!
  Удаление всех объектов окна
*/
SubWindow::~SubWindow(){
    delete t;
    delete box;
    delete darkness;
    delete krestik;
}
