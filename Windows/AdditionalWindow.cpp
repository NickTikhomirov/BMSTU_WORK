#include "AdditionalWindow.h"

using std::to_string;
using std::swap;



AdditionalWindow::AdditionalWindow(char p, Level *l, QWidget *par): QGraphicsView(par)
{
    scene = new QGraphicsScene;
    setScene(scene);
    QPixmap pp(QString::fromStdString("://main//Pictures//backgrounds//fon"+to_string(short(p))+".png"));
    scene->addPixmap(pp);
    switch(p){
        case 1:{ // 1 - Паспорт
            bool comicSans=l->mistakes->isSans('P');
            setWindowIcon(QIcon(QPixmap(QString::fromStdString("://b//Pictures//buttons//id4.png"))));

            Stamp *b_stamp = new Stamp('P',2,l->mistakes->isStampCorrect('P'));
            TextButton *num = new TextButton(Randomizer::generateDocumentNumber(),24,false,!comicSans);
            TextButton *country = new TextButton(
                        (l->mistakes->hasCorrectCountry())?
                            NameGenerator::generateCountry():NameGenerator::generateBadCountry()
                            ,24,false,!comicSans);
            TextButton *birt = new TextButton(l->dateH,20,false,!comicSans);
            Face *face = new Face(l->face,0.375,l->mistakes->isFaceCorrect('P'));
            country->val=12;
            b_stamp->val=11;
            birt->val=6;
            face->val=7;
            b_stamp->setPos(335,365);
            num->setPos(275,138);
            country->setPos(220,367);
            birt->setPos(240,317);
            face->setPos(120,290);
            scene->addItem(b_stamp);
            scene->addItem(num);
            scene->addItem(country);
            scene->addItem(birt);
            scene->addItem(face);
            connect(b_stamp,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));
            connect(country,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));
            connect(birt,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));
            connect(face,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));


            TextButton *title = new TextButton("Паспорт", 36,false,!comicSans);
            TextButton *name = new TextButton(l->getNameFor('P'),12,false,!comicSans);
            TextButton *name2 = new TextButton(l->getName2For('P'),12,false,!comicSans);
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
        case 2:{ // 2 - Согласие
            bool comicSans=l->mistakes->isSans('A');
            setWindowIcon(QIcon(QPixmap(QString::fromStdString("://b//Pictures//buttons//id11.png"))));
            string text = string("Я, ______________________\n")+
                                 "    (имя)     (фамилия)\n\n"+
                                 "даю вашей конторе своё со-\n"+
                                 "гласие на обработку, храние\n"+
                                 "и продажу моих персональных\n"+
                                 "данных. В случае кражи или\n"+
                                 "утери вами моих данных либо\n"+
                                 "документов обязуюсь выпла-\n"+
                                 "тить вам штраф в размере\n"+
                                 "пяти тысяч танцев.\n\n\n Дата:_________________";
            TextButton *txt = new TextButton(text,14,false,!comicSans);

            txt->param*=11;
            txt->setPos(145,95);
            scene->addItem(txt);

            TextButton *title = new TextButton("Согласие",20,false,!comicSans);
            TextButton *name = new TextButton(l->getNameFor('A'),12,false,!comicSans);
            TextButton *name2 = new TextButton(l->getName2For('A'),12,false,!comicSans);
            TextButton *date = new TextButton(l->dateA,12,false,!comicSans);
            if(l->mistakes->isSwapped('A')) swap(name,name2);
            name->val=2;
            name2->val=4;
            title->val=5;
            date->val=3;
            name->setPos(170,97);
            name2->setPos(240,97);
            title->setPos(190,57);
            date->setPos(190,302);
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
        case 3:{ // 3 - Полис
            bool comicSans=l->mistakes->isSans('M');
            setWindowIcon(QIcon(QPixmap(QString::fromStdString("://b//Pictures//buttons//id13.png"))));

            Stamp *b_stamp = new Stamp('M',2,l->mistakes->isStampCorrect('M'));
            TextButton *num = new TextButton(l->insuranceNumber,12);
            b_stamp->val=11;
            num->setPos(180,273);
            scene->addItem(num);
            connect(b_stamp,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));

            TextButton *title = new TextButton("Страховой полис",18,false,!comicSans);
            TextButton *name = new TextButton(l->getNameFor('M'),12,false,!comicSans);
            TextButton *name2 = new TextButton(l->getName2For('M'),12,false,!comicSans);
            TextButton *date = new TextButton(l->dateM,12,false,!comicSans);
            if(l->mistakes->isSwapped('M')) swap(name,name2);
            name->val=2;
            name2->val=4;
            title->val=5;
            date->val=3;
            name->setPos(180,110);
            name2->setPos(250,110);
            title->setPos(180,70);
            date->setPos(170,303);
            b_stamp->setPos(265,320);
            scene->addItem(name);
            scene->addItem(name2);
            scene->addItem(title);
            scene->addItem(date);
            scene->addItem(b_stamp);
            connect(name,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));
            connect(name2,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));
            connect(title,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));
            connect(date,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));
            break;
        }
        case 4:{ // 4 - Права
            bool comicSans=l->mistakes->isSans('R');
            setWindowIcon(QIcon(QPixmap(QString::fromStdString("://b//Pictures//buttons//id15.png"))));

            Stamp *b_stamp = new Stamp('R',1,l->mistakes->isStampCorrect('R'));
            Face *face = new Face(l->face,0.25,l->mistakes->isFaceCorrect('R'));
            face->setPos(300,280);
            b_stamp->setPos(240,310);
            face->val=7;
            b_stamp->val=11;
            scene->addItem(face);
            scene->addItem(b_stamp);
            connect(face,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));
            connect(b_stamp,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));


            TextButton *title = new TextButton("Лицензия на вождение",20,false,!comicSans);
            TextButton *name = new TextButton(l->getNameFor('R'),12,false,!comicSans);
            TextButton *name2 = new TextButton(l->getName2For('R'),12,false,!comicSans);
            TextButton *date = new TextButton(l->dateR,12,false,!comicSans);
            if(l->mistakes->isSwapped('R')) swap(name,name2);
            name->val=2;
            name2->val=4;
            title->val=5;
            date->val=3;
            name->setPos(145,257);
            name2->setPos(215,257);
            title->setPos(150,215);
            date->setPos(150,305);
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
        case 5:{ // 5 - Справка от психиатра
            bool comicSans=(l->mistakes->isSans('X'));
            setWindowIcon(QIcon(QPixmap(QString::fromStdString("://b//Pictures//buttons//id12.png"))));
            string n = "0";

            Stamp *b_stamp = new Stamp('X',2,l->mistakes->isStampCorrect('X'));
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
            b_stamp->val=11;
            num->setPos(160,273);
            res->setPos(155,300);
            b_stamp->setPos(275,330);
            scene->addItem(num);
            scene->addItem(res);
            scene->addItem(b_stamp);
            connect(num,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));
            connect(res,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));
            connect(b_stamp,SIGNAL(clicked(char)),this,SLOT(provide_input(char)));

            TextButton *title = new TextButton("Заключение", 20,false,!comicSans);
            TextButton *name = new TextButton(l->getNameFor('X'),12,false,!comicSans);
            TextButton *name2 = new TextButton(l->getName2For('X'),12,false,!comicSans);
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
            TextButton *name = new TextButton("Имя: "+l->name,22);
            TextButton *sName = new TextButton("Фамилия: "+l->secondName,22);

            time->setPos(120,240);
            name->setPos(215,170);
            sName->setPos(215,195);
            time->param*=11;
            name->param*=11;
            sName->param*=11;

            scene->addItem(time);
            scene->addItem(name);
            scene->addItem(sName);
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

        case 78:{
            SwitchingButton *de_thing = new SwitchingButton(18,l!=0);
            de_thing->setPos(100,50);
            scene->addItem(de_thing);
            connect(de_thing, SIGNAL(enable()), this, SLOT(flavor_input()));
            connect(de_thing, SIGNAL(disable()), this, SLOT(flavor_input()));
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

void AdditionalWindow::flavor_input(){
    emit provide(113);
}

void AdditionalWindow::simpleCloser(){
    if(isVisible()) hide();
    else show();
}
