#include "Game.h"

//id:
// 1 - Дверь
// 0,2,3 - Парные кнопки
// 4 - Паспорт
// 5-8 - Печати
// Кнопка "Играть"
// Ручка двери
// 11-15 - Документы
// 16 - Справка по печатям
// 17 - Факс
// 18 - Фото
//SwB:
// 0 - Нота
// 1 - Динамик
// 2 - Кофе


Game::Game(QWidget *parent) : QGraphicsView(parent)
{
    mus = new MyPlayer(0,0);
    wm = new WindowManager;
    sw = new SubWindow;
    score = 0;
    levelsLeft=0;
    level = 0;

    setFixedSize(517,517);
    scene = new QGraphicsScene;
    setScene(scene);
    setCursor(CursorManager::greenArrow());
    setWindowIcon(QIcon(QPixmap(QString::fromStdString("://main//Pictures//other//icon.png"))));

    mode_menu();
}


void Game::exit0(){
    emit button_pressed();
}


void Game::mode_play(){
    score = 0;
    levelsLeft=3;

    delete sw;
    delete mus->lever;
    contents.clear();
    scene->clear();
    wm->clear_dynamics();
    level = new Level;
    wm->level=level;
    wm->dynamic_documents();
    contents.resize(15);
    sw = new SubWindow;

    VisitorFace *vis = new VisitorFace(14);
    vis->setPos(50,54);

    //Чашка
    VeryComplicatedButton *b = new VeryComplicatedButton(level,2);
    b->setPos(450,300);
    b->t->setPos(435,400);
    if(level!=0) b->t->setPlainText(QString::fromStdString(level->time));

    //Дверь
    QGraphicsPixmapItem *d0 = new QGraphicsPixmapItem;
    d0->setPixmap(QPixmap(QString::fromStdString("://main//Pictures//other//door0.png")));
    d0->setPos(50,61);
    CustomButton *door;
    door = new CustomButton(1);
    door->setPos(56,65);

    //Документы
    CustomButton *passport = new CustomButton(4);
    passport->setPos(56,315);
    CustomButton *agreement = new CustomButton(11);
    agreement->setPos(90,316);
    CustomButton *xPaper = new CustomButton(12);
    xPaper->setPos(150,316);
    CustomButton *medicine = new CustomButton(13);
    medicine->setPos(130,316);
    CustomButton *tutorial = new CustomButton(14);
    tutorial->setPos(90,410);
    CustomButton *license = new CustomButton(15);
    license->setPos(56,334);

    //Прочая интерфейсня
    CustomButton *faks = new CustomButton(17);
    CustomButton *paper = new CustomButton(16,true);
    faks->setPos(385,370);
    paper->setPos(40,370);


    //Парные кнопки и плеер
    TwinButtons *b2;
    b2 = new TwinButtons;
    mus->init(1 ,1);
    mus->setPos(380,395);

    QPixmap pp("://main//Pictures//backgrounds//fon0.png");
    scene->addPixmap(pp);
    scene->addItem(b2->left);
    scene->addItem(b2->right);
    scene->addItem(mus->lever);
    scene->addItem(d0);
    scene->addItem(door);
    scene->addItem(passport);
    scene->addItem(agreement);
    scene->addItem(xPaper);
    scene->addItem(medicine);
    scene->addItem(tutorial);
    scene->addItem(license);
    scene->addItem(b->t);
    scene->addItem(b);
    scene->addItem(faks);
    scene->addItem(paper);
    scene->addItem(vis);


    contents.push_back(b2->left);
    contents.push_back(b2->right);
    contents.push_back(door);
    contents.push_back(passport);
    contents.push_back(agreement);
    contents.push_back(xPaper);
    contents.push_back(medicine);
    contents.push_back(license);
    contents.push_back(faks);
    contents.push_back(tutorial);
    contents.push_back(paper);
    contents.push_back(b);
    contents.push_back(b->t);
    contents.push_back(mus->lever);



//    connect(b2->left,SIGNAL(clicked()),this, SLOT(renovation()));
  //  connect(b2->left,SIGNAL(clicked()),b, SLOT(update_b()));
    connect(b2->left,SIGNAL(clicked()), this,SLOT(lock_screen()));
    connect(door, SIGNAL(clicked()), this, SLOT(switch_menu()));
    if(wm!=0){
        connect(passport,SIGNAL(clicked()),wm,SLOT(open_passport()));
        connect(medicine,SIGNAL(clicked()),wm,SLOT(open_medicine()));
        connect(license,SIGNAL(clicked()),wm,SLOT(open_license()));
        connect(xPaper,SIGNAL(clicked()),wm,SLOT(open_x()));
        connect(agreement,SIGNAL(clicked()),wm,SLOT(open_agreement()));
        connect(faks,SIGNAL(clicked()),wm,SLOT(open_stenography()));
        connect(tutorial, SIGNAL(clicked()),wm, SLOT(open_tutorial()));
    }

    connect(paper,SIGNAL(clicked()),this,SLOT(show_stamps()));
    connect(paper,SIGNAL(clicked()),this,SLOT(lock_screen()));




    b->setCursor(CursorManager::cloud());
    passport->setCursor(CursorManager::glass());
    agreement->setCursor(CursorManager::glass());
    xPaper->setCursor(CursorManager::glass());
    medicine->setCursor(CursorManager::glass());
    tutorial->setCursor(CursorManager::cloud());
    license->setCursor(CursorManager::glass());
    faks->setCursor(CursorManager::glass());
    paper->setCursor(CursorManager::cloud());
}



void Game::mode_menu(){
    delete sw;
    sw=0;
    delete mus->lever;
    if(level!=0) delete level;
    level = 0;
    contents.clear();
    scene->clear();
    contents.resize(5);
    sw = new SubWindow;


    QPixmap pp("://main//Pictures//backgrounds//fon-1.png");
    CustomButton *playbutton = new CustomButton(9);
    playbutton->setPos(300,20);
    CustomButton *auth = new CustomButton(22, true);
    auth->setPos(300,110);
    CustomButton *exiter = new CustomButton(10);
    exiter->setPos(53,18);


    mus->init(0,0);
    mus->setPos(490,10);

    scene->addPixmap(pp);
    scene->addItem(playbutton);
    scene->addItem(exiter);
    scene->addItem(mus->lever);
    scene->addItem(auth);

    contents.push_back(playbutton);
    contents.push_back(exiter);
    contents.push_back(mus->lever);
    contents.push_back(auth);


    connect(playbutton,SIGNAL(clicked()),this, SLOT(switch_play()));
    connect(auth, SIGNAL(clicked()), this, SLOT(lock_screen()));
    connect(exiter,SIGNAL(clicked()),this, SLOT(exit0()));
}






void Game::lock_screen(){
    for(auto &a: contents){
        if(a!=0) a->unsafe_lock();
    }
    subwindowSetuper(1);
}

void Game::unlock_screen(){
    for(auto &a: contents){
        if(a!=0) a->unlock();
    }
    subwindowSetuper(0);
}

void Game::show_stamps(){
    if(sw!=0)
        if(sw->t!=0)
            sw->t->val=-1;
}



void Game::subwindowSetuper(char a){
    if(sw->krestik->param%7!=0){
        sw->krestik->setPos(400,110);
        sw->box->setPos(140,100);
        sw->t->setPos(150,120);

        connect(sw->krestik, SIGNAL(clicked()), this, SLOT(unlock_screen()));
        sw->darkness->setCursor(CursorManager::greenArrow());
        sw->t->safe_lock();
        sw->t->param*=11;

        scene->addItem(sw->darkness);
        scene->addItem(sw->box);
        scene->addItem(sw->krestik);
        scene->addItem(sw->t);
        sw->krestik->param*=7;
    }

    if(sw->t->val==-1){
        if(a==1){
            sw->box->setPixmap(QPixmap("://main//Pictures//backgrounds//stamps.png"));
            sw->box->setPos(130, 60);
            sw->krestik->setPos(400, 70);

            sw->t->hide();
            sw->darkness->show();
            sw->box->show();
            sw->krestik->show();
            sw->krestik->unlock();
        } else {
            sw->box->setPixmap(QPixmap("://main//Pictures//backgrounds//box.png"));
            sw->box->setPos(140, 100);
            sw->krestik->setPos(400, 110);

            sw->darkness->hide();
            sw->box->hide();
            sw->krestik->hide();
            sw->t->val=0;
            sw->krestik->safe_lock();
        }
        return;
    }
    if(a==1){
        if(level==0) sw->t->setPlainText(QString::fromStdString(sw->credits));
        else sw->t->setPlainText(level->mistakes->text_form());
        sw->darkness->show();
        sw->box->show();
        sw->krestik->show();
        sw->t->show();
        sw->krestik->unlock();
    } else if(a==0){
        sw->darkness->hide();
        sw->box->hide();
        sw->krestik->hide();
        sw->t->hide();
        sw->krestik->safe_lock();
    }
}











void Game::renovation(){
    level->regenerate();
    wm->clear_dynamics();
    wm->dynamic_documents();
}


void Game::mode_finalle(bool first){
    static QPixmap p1("://main//Pictures//backgrounds//fon-2.png");
    static QPixmap p2("://main//Pictures//backgrounds//fon-3.png");
    if(first){
        sw->krestik->setPixmap(QPixmap("C:\\qtprojects\\ht2\\id23.png"));
        sw->krestik->id=23;
        mus->init(2,0);
        sw->krestik->setPos(400,200);
        mus->lever->setPos(490,10);

        scene->addPixmap(p1);
        //scene->addItem(sw->krestik);
        sw->krestik->show();
        scene->addItem(mus->lever);

        connect(sw->krestik,SIGNAL(clicked()),this, SLOT(switch_finalle2()));
    } else {
        score=100;
        sw->krestik->hide();
        sw->krestik->safe_lock();
        CustomButton *b1 = new CustomButton(2);
        CustomButton *b2 = new CustomButton(3);
        b2->setPos(400,350);
        b1->setPos(370,350);

        scene->addPixmap(p2);
        scene->addItem(b1);
        scene->addItem(b2);

        connect(b1,SIGNAL(clicked()),this,SLOT(switch_menu()));
        connect(b2,SIGNAL(clicked()),this,SLOT(exit0()));
    }
}

void Game::switch_menu(){
    wm->kill();
    mode_menu();
}

void Game::switch_play(){
    mode_play();
}

void Game::switch_finalle(){
    delete mus->lever;
    //delete sw;
    //sw=0;
    wm->kill();
    delete level;
    level=0;
    scene->clear();
    sw = new SubWindow;
    mode_finalle(true);
}

void Game::switch_finalle2(){
    mode_finalle(false);
}
