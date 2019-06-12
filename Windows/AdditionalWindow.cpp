#include "AdditionalWindow.h"

using std::to_string;
using std::swap;



AdditionalWindow::AdditionalWindow(char p, Level *l, QWidget *par): QGraphicsView(par)
{
    w_type = p;
    scene = new QGraphicsScene;
    setScene(scene);
    QPixmap pp(QString::fromStdString("://main//Pictures//backgrounds//fon"+to_string(short(p))+".png"));
    scene->addPixmap(pp);
    switch(p){
        case 1:{ // 1 - Паспорт
            bool comicSans=l->mistakes->isSans('P');
            setWindowIcon(QIcon(QPixmap(QString::fromStdString("://b//Pictures//buttons//id4.png"))));

            SimpleButton *b_stamp = new SimpleButton('P');
            TextButton *num = new TextButton(Randomizer::generateDocumentNumber(),24,false,!comicSans);
            TextButton *country = new TextButton(
                        (l->mistakes->hasCorrectCountry())?
                            NameGenerator::generateCountry():NameGenerator::generateBadCountry()
                            ,24,false,!comicSans);
            TextButton *birt = new TextButton(l->dateH,20,false,!comicSans);
            country->val=12;
            b_stamp->val=11;
            birt->val=6;
            b_stamp->setPos(335,365);
            num->setPos(275,138);
            country->setPos(220,367);
            birt->setPos(240,317);
            scene->addItem(b_stamp);
            scene->addItem(num);
            scene->addItem(country);
            scene->addItem(birt);
            connect(b_stamp,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));
            connect(country,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));
            connect(birt,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));


            TextButton *title = new TextButton("Паспорт", 36,false,!comicSans);
            TextButton *name = new TextButton(l->getNameFor('P'),12);
            TextButton *name2 = new TextButton(l->getName2For('P'),12);
            TextButton *date = new TextButton(l->dateP,24,false,!comicSans);
            if(l->mistakes->isSwapped('P')) swap(name,name2);
            name->val=2;
            name2->val=4;
            title->val=5;
            date->val=3;
            name->setPos(250,290);
            name2->setPos(320,290);
            title->setPos(180,80);
            date->setPos(275,190);
            scene->addItem(name);
            scene->addItem(name2);
            scene->addItem(title);
            scene->addItem(date);
            connect(name,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));
            connect(name2,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));
            connect(title,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));
            connect(date,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));
            break;
        }
        case 2:{
            // 2 - Согласие
            setWindowIcon(QIcon(QPixmap(QString::fromStdString("://b//Pictures//buttons//id11.png"))));
            break;
        }
        case 3:{
            // 3 - Полис
            setWindowIcon(QIcon(QPixmap(QString::fromStdString("://b//Pictures//buttons//id13.png"))));
            string n = "0";
            if(l!=0){
                n = l->insuranceNumber;
            }

            TextButton *num = new TextButton(n,12);

            num->setPos(180,273);

            scene->addItem(num);
            break;
        }
        case 4:{
            // 4 - Права
            CustomButton *photo = new CustomButton(18);
            photo->setPos(390,350);

            connect(photo,SIGNAL(clicked()),photo,SLOT(lock()));

            scene->addItem(photo);

            setWindowIcon(QIcon(QPixmap(QString::fromStdString("://b//Pictures//buttons//id15.png"))));
            break;
        }
        case 5:{ // 5 - Справка от психиатра
            bool comicSans=(l->mistakes->isSans('X'));
            setWindowIcon(QIcon(QPixmap(QString::fromStdString("://b//Pictures//buttons//id12.png"))));
            string n = "0";

            if(l!=0){
                if(l->mistakes->medicineNumberMistakes())
                    do n = Randomizer::generateDocumentNumber(); while(n==(l->insuranceNumber));
                else n = l->insuranceNumber;
            }
            TextButton *num = new TextButton(n,12);
            n = "здоров";
            if(l!=0)
                if(l->mistakes->xHealthy()==0)
                    n = "болен";
            TextButton *res = new TextButton(n,16);

            num->val=-1;
            res->val=7;
            num->setPos(160,273);
            res->setPos(155,300);
            scene->addItem(num);
            scene->addItem(res);
            connect(num,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));
            connect(res,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));

            TextButton *title = new TextButton("Заключение", 20,false,!comicSans);
            TextButton *name = new TextButton(l->getNameFor('X'),12);
            TextButton *name2 = new TextButton(l->getName2For('X'),12);
            TextButton *date = new TextButton(l->dateX,12,false,!comicSans);
            if(l->mistakes->isSwapped('X')) swap(name,name2);
            name->val=2;
            name2->val=4;
            title->val=5;
            date->val=3;
            name->setPos(150,227);
            name2->setPos(210,227);
            title->setPos(190,180);
            date->setPos(160,360);
            scene->addItem(name);
            scene->addItem(name2);
            scene->addItem(title);
            scene->addItem(date);
            connect(name,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));
            connect(name2,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));
            connect(title,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));
            connect(date,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));
            break;
        }
        case 6:{ // 6 - Досье
            setWindowIcon(QIcon(QPixmap(QString::fromStdString("://b//Pictures//buttons//id17.png"))));
            TextButton *time = new TextButton("Время визита: "+l->time,12);

            time->setPos(120,240);
            time->param*=11;

            scene->addItem(time);
            break;
        }
        case 7:{ // 7 - Правила
            setWindowIcon(QIcon(QPixmap(QString::fromStdString("://b//Pictures//buttons//id14.png"))));
            CustomButton *arrowLeft = new CustomButton(20,true);
            CustomButton *arrowRight = new CustomButton(21,true);
            TutorialPage *tut = new TutorialPage;

            arrowLeft->setPos(185,430);
            arrowRight->setPos(225,430);
            arrowLeft->safe_lock();
            tut->text->setPos(7,75);

            connect(arrowLeft,SIGNAL(clicked()),tut,SLOT(list_backward()));
            connect(arrowRight,SIGNAL(clicked()),tut,SLOT(list_forward()));

            connect(tut,SIGNAL(lock_right()), arrowRight, SLOT(lock()));
            connect(tut,SIGNAL(unlock_right()), arrowRight, SLOT(unlock_s()));
            connect(tut,SIGNAL(lock_left()), arrowLeft, SLOT(lock()));
            connect(tut,SIGNAL(unlock_left()), arrowLeft, SLOT(unlock_s()));


            scene->addItem(arrowLeft);
            scene->addItem(arrowRight);
            scene->addItem(tut->text);
            scene->addItem(tut->guys);
            scene->addItem(tut->captain);
            break;
        }
    }
}


void AdditionalWindow::closeEvent(QCloseEvent *event){
    emit closed();
}


void AdditionalWindow::provide_input(char r){
    if(r*r!=r) emit provide(r);
}
