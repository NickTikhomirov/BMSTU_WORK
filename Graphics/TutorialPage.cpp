#include "TutorialPage.h"

TutorialPage::TutorialPage(QObject *par): QObject(par)
{
    guys = new QGraphicsPixmapItem(QPixmap("://main//Pictures//other//egg1.jpg"));
    captain = new QGraphicsPixmapItem(QPixmap("://main//Pictures//other//egg2.jpg"));
    guys->setPos(20,100);
    captain->setPos(50,100);
    guys->hide();
    captain->hide();
    max = 7;
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
            "  Динамик включает и выключает музыку.\n  Выход - дверь.\n"+
            "  Обратите внимание, в игре всегда одна и та\nже дата (31.05.2019) и свой ход времени.\n\n"+
            "  При входе посетитель называет имя и фамилию, \n"+
            "их можно прочитать на листке бумаги, торащем\nиз принтера."+
            "\n";
    t[2] =
            string("Управление 2.\n\n")+
            "  Ваша задача: вынести вердикт, верно ли оформ-\nлены документы.\n"+
            "  Нажмите на неправильное поле в документе,\nчтобы зафиксировать ошибку.\n"+
            "  На уровне генерируется 0-2 ошибок.\n"+
            "  Обнаружение ошибки открывает кнопку отказа.\n"+
            "  Посетителям с правильными документами надо \nдавать разрешение, "+
            "с неправильными - отказ.\n"+
            "  Неправильный шрифт фиксируется нажатием \nна название документа.\n"+
            "  Неправильное время визита фиксируется на-\nжатием на часы.\n"+
            "  Чёрный список фиксируется нажатием на само-\nго посетителя.\n"+
            "  Если дата рождения неправильна, все осталь-\nные даты считать правильными.";

    t[3] =
            string("Общие положения 1.\n\n")+
            "  При наличии ошибок в документе он считается \n"+
            "недействительным. Если согласие на обработку \nданных"+
            " недействительно, то вы не имеете права \nчитать другие документы.\n"+
            "  Названные имя, фамилия и дата рождения долж-\nны совпадать с данными документов.\n"+
            "  Обращайте внимание на порядок написания\nимени и фамилии, в этом фальсификаторы до-\nкументов часто прокалываются\n"+
            "  Шрифт общей части док-та: GOST Common.\n"+
            "  Шрифт индивидуальной части док-та: Arial.\n"+
            "  Справка от психиатра должна содержать кор-\nректный номер полиса\n"+
            "  Психически больные люди получают отказ.\n";

    t[4] =
            string("Общие положения 2.\n\n")+
            "  Документы граждане получают не раньше 14 лет\n"+
            "  Справка ссылается на действующий полис, по-\nэтому дата её выдачи будет позже полиса.\n"+
            "  Срок действия справки - 1 месяц. Более позд-\n"+
            "ние справки недействительны. Аналогично для сог-\n"+
            "ласия на обработку данных.\n\n\n"+
            "  Обращаем Ваше внимание, что у запрет на под-\nделку печатей распространяется и на эту мето-\nдичку, "+
            "поэтому мы не можем приводить здесь об-\nразцы верных печатей.\n  Надеемся, вы запомнили их в ходе стажировки.";

    t[5] =
            string("Список требуемых документов.\n\n")+
            "  Согласие на обработку персональных данных\n"+
            "  Паспорт\n"+
            "  Полис медицинского страхования\n"+
            "  Водительские права\n"+
            "  Справка от психиатра\n\n\n\n\n\n\n\n\n\n\n      --Конец методички--";

    t[6] = " ";

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
