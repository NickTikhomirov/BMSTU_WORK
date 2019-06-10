#include "AdditionalWindow.h"
#include "Graphics/TutorialPage.h"

using std::to_string;

//p:

/* Паспорт:
 *      Имя
 *      Фамиля
 *      Дата Рождения
 *      Дата Выдачи
 *      Страна рождения
 *      Номер паспорта
 *      Слово "Паспорт"
 *      +Печать
 *      +Фото
 *
 * Полис:
 *      Имя
 *      Фамиля
 *      Дата Выдачи
 *      Номер полиса
 *      Слово "Полис"
 *      +Печать
 *
 *
 * Права:
 *      Имя
 *      Фамиля
 *      Дата Выдачи
 *      Предметы и оценки
 *      Слово "Водительские права"
 *      +Фото
 *      +Печать
 *
 * Справка:
 *      Имя
 *      Фамиля
 *      Дата Выдачи
 *      Вердикт
 *      Номер полиса
 *      Слово "Справка"
 *      +Печать
 *
 * Согласие:
 *      Имя
 *      Фамиля
 *      Дата Подписания
 *      Слово "Согласие на обработку"
 *
 * Правила:
 *      Листать вперёд
 *      Листать назад
 *
 * Досье:
 *   (имя, фамилия, время прихода, данные по уровню)
 *
 *
 */





AdditionalWindow::AdditionalWindow(char p, Level *l, QWidget *par): QGraphicsView(par)
{
    w_type = p;
    scene = new QGraphicsScene;
    setScene(scene);
    QPixmap pp(QString::fromStdString("://main//Pictures//backgrounds//fon"+to_string(short(p))+".png"));
    scene->addPixmap(pp);
    switch(p){
        case 1:{
            bool comicSans=l->mistakes->isSans('P');
            // 1 - Паспорт
            setWindowIcon(QIcon(QPixmap(QString::fromStdString("C:\\qtprojects\\ht2\\id4.png"))));

            SimpleButton *b_stamp = new SimpleButton(5);
            TextButton *title = new TextButton("Паспорт", 36,false,!comicSans);
            TextButton *num = new TextButton(Randomizer::generateDocumentNumber(),24,false,!comicSans);

            b_stamp->setPos(335,365);
            title->setPos(180,80);
            num->setPos(275,138);

            scene->addItem(b_stamp);
            scene->addItem(title);
            scene->addItem(num);

            connect(b_stamp,SIGNAL(clicked()),this,SLOT(close()));
            break;
        }
        case 2:{
            // 2 - Согласие
            setWindowIcon(QIcon(QPixmap(QString::fromStdString("C:\\qtprojects\\ht2\\id11.png"))));
            break;
        }
        case 3:{
            // 3 - Полис
            setWindowIcon(QIcon(QPixmap(QString::fromStdString("C:\\qtprojects\\ht2\\id13.png"))));
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

            setWindowIcon(QIcon(QPixmap(QString::fromStdString("C:\\qtprojects\\ht2\\id15.png"))));
            break;
        }
        case 5:{
            // 5 - Справка от психиатра
            setWindowIcon(QIcon(QPixmap(QString::fromStdString("C:\\qtprojects\\ht2\\id12.png"))));
            string n = "0";
            if(l!=0){
                if(l->xNumberProblems())
                    do n = Randomizer::generateDocumentNumber(); while(n==l->insuranceNumber);
                else n = l->insuranceNumber;
            }
            TextButton *num = new TextButton(n,12);
            n = "здоров";
            if(l!=0)
                if(!l->xHealthy())
                    n = "болен";
            TextButton *res = new TextButton(n,16);

            num->setPos(160,273);
            res->setPos(155,300);

            scene->addItem(num);
            scene->addItem(res);
            break;
        }
        case 6:{
            // 6 - Досье
            TextButton *time = new TextButton("Время визита: "+l->time,12);

            time->setPos(120,240);
            time->param*=11;

            scene->addItem(time);
            setWindowIcon(QIcon(QPixmap(QString::fromStdString("C:\\qtprojects\\ht2\\id17.png"))));
            break;
        }
        case 7:{
            // 7 - Правила
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




            setWindowIcon(QIcon(QPixmap(QString::fromStdString("C:\\qtprojects\\ht2\\id14.png"))));
            break;
        }
    }
}


void AdditionalWindow::closeEvent(QCloseEvent *event){
    emit closed();
}
