#include "TutorialPage.h"

TutorialPage::TutorialPage(QObject *par): QObject(par)
{
    guys = new QGraphicsPixmapItem(QPixmap("://main//Pictures//other//egg1.jpg"));
    captain = new QGraphicsPixmapItem(QPixmap("://main//Pictures//other//egg2.jpg"));
    guys->setPos(20,100);
    captain->setPos(50,100);
    guys->hide();
    captain->hide();
    max = 4;
    page=0;
    t.resize(max);
    text = new QGraphicsTextItem();
    text->setFont(QFont("Consolas"));
    t[0] =
            string("Содержание:\n")+
            "  - Управление\n"+
            "  - Общие положения\n"+
            "  - Список документов\n";
    t[1] =
            string("Управление 1.\n\n")+
            "  Для управления вам понадобится только мышь.\n"+
            "  Нажимайте на активные предметы, чтобы взаи-\nмодействовать с ними.\n"+
            "  Некоторые предметы открывают новые окна.\n"+
            "  У вас может быть открыто не более двух вспо-\nмогательных окон.\n"+
            "  Динамик включает и выключает музыку.\n Выход - дверь.\n\n";
    t[2] =
            string("Управление 2.\n\n")+
            "  Ваша задача: вынести вердикт, верно ли оформ-\nлены документы.\n\n"+
            "  Нажмите на неправильное поле в документе,\nчтобы зафиксировать ошибку.\n"+
            "  На уровне генерируется 0-2 ошибок.\n"+
            "  Обнаружение ошибки открывает кнопку отказа.\n"+
            "  Посетителям с правильными документами надо \nдавать разрешение, "+
            "с неправильными - отказ.\n"+
            "  Неправильный шрифт фиксируется нажатием \nна название документа\n\n"+
            "  При входе посетитель называет имя, фамилию \nи дату рождения - "+
            "их можно прочитать на листке \nбумаги, торащем из принтера."+
            " Там же можно по-\nсмотреть информацию о найденных ошибках.\n";

    t[3] =
            string("Общие положения.\n\n")+
            "  При наличии ошибок в документе он считается \n"+
            "недействительным. Если согласие на обработку \nданных"+
            " недействительно, то вы не имеете права \nчитать другие документы.\n"+
            "  Названные имя, фамилия и дата рождения долж-\nны совпадать с данными документов.\n"+
            "  Шрифт общей части док-та: GOST Common.\n"+
            "  Шрифт индивидуальной части док-та: Arial.\n"+
            "  Справка от психиатра должна содержать кор-\nректный номер полиса\n";

    text->setPlainText(QString::fromStdString(t[0]));
    text->show();
}


TutorialPage::~TutorialPage(){
    t.clear();
    delete text;
}

void TutorialPage::list_forward(){
    page++;
    if(page==max) guys->show();
    if(page==max+1){
        guys->hide();
        captain->show();
        emit lock_right();
    }
    if(page==1){
        emit unlock_left();
    }
    if(page<max){
        text->setPlainText(QString::fromStdString(t[page]));
        text->show();
    } else text->hide();
}


void TutorialPage::list_backward(){
    page--;
    if(page==max) {
        guys->show();
        captain->hide();
        emit unlock_right();
    } else guys->hide();
    if(page==0){
        emit lock_left();
    }
    if(page<max){
       text->setPlainText(QString::fromStdString(t[page]));
       text->show();
    } else text->hide();
}
