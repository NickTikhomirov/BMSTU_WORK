#include "Game.h"


Game::Game(QWidget *parent) : QGraphicsView(parent)
{
    mus = new MyPlayer(0,0);
    wm = new WindowManager;
    sw = new SubWindow;
    score = 0;
    levelsLeft=0;
    level = 0;
    b2=0;

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

    clear_items();
    scene->clear();
    level = new Level;
    wm->level=level;
    wm->dynamic_documents();
    contents.resize(15);
    sw = new SubWindow;

    Face *vis = new Face(level->face);
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
    contents.push_back(vis);


    connect(paper,SIGNAL(clicked()),this,SLOT(show_stamps()));
    connect(paper,SIGNAL(clicked()),this,SLOT(lock_screen()));
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


    connect(this,SIGNAL(addPoint()),b2,SLOT(score_increase()));
    connect(wm,SIGNAL(provide(char,char)),this,SLOT(playersGuess(char,char)));
    connect(b,SIGNAL(time_pressed(char,char)),this,SLOT(playersGuess(char,char)));
    connect(vis,SIGNAL(clicked(char,char)),this,SLOT(playersGuess(char,char)));


    connect(b2,SIGNAL(result(char)),this,SLOT(level_finalize(char)));
    connect(this,SIGNAL(waveOfChange(char)),b,SLOT(update_b(char)));
    connect(this,SIGNAL(waveOfChange(char)),vis,SLOT(regenerate(char)));



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
    clear_items();
    scene->clear();
    contents.resize(5);
    sw = new SubWindow;
    levelsLeft=3;


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
        sw->t->setPos(150,115);

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
        if(levelsLeft==0) switch_finalle();
    }
}





void Game::level_finalize(char a){
    bool greenPressed = (a>=0);
    bool level_complete = level->mistakes->isCorrect();
    if(!greenPressed){
        a++;
        a*=-1;
    }
    if(greenPressed && a==0 && level_complete){
        score+=5;
    } else if(!greenPressed){
        if(level_complete) score+=4;
        else score+=3;
    }

    wm->clear_dynamics();
    levelsLeft--;
    lock_screen();
    if(levelsLeft!=0) {
        level->regenerate();
        wm->dynamic_documents();
        emit waveOfChange(level->face);
    }
}



void Game::playersGuess(char a, char b){
    if(level->mistakes->isItYours(a,b))
        emit addPoint();
}




void Game::clear_items(){
    if(level!=0) delete level;
    level=0;

    if(sw!=0) delete sw;
    sw=0;

    if(wm!=0)wm->kill();
    if(wm!=0)wm->clear_dynamics();
    //if(wm!=0)delete wm;
    //wm = 0;

    if(b2!=0) delete b2;
    b2=0;

    if(mus->lever!=0)delete mus->lever;
    mus->lever=0;

    contents.clear();
}


void Game::switch_menu(){
    wm->kill();
    mode_menu();
}

void Game::switch_play(){
    mode_play();
}

void Game::switch_finalle(){
    clear_items();
    scene->clear();

    static QPixmap p1("://main//Pictures//backgrounds//fon-2.png");
    CustomButton *hand = new CustomButton(23);
    mus->init(2,0);
    hand->setPos(400,200);
    mus->lever->setPos(490,10);

    scene->addPixmap(p1);
    scene->addItem(hand);
    scene->addItem(mus->lever);

    connect(hand,SIGNAL(clicked()),this, SLOT(switch_finalle2()));
}

void Game::switch_finalle2(){
    clear_items();
    scene->clear();
    static QPixmap p2("://main//Pictures//backgrounds//fon-3.png");

    CustomButton *b1 = new CustomButton(2);
    CustomButton *b3 = new CustomButton(3);
    mus->init(2,0);
    mus->lever->setPos(490,10);
    b3->setPos(400,350);
    b1->setPos(370,350);

    scene->addPixmap(p2);
    scene->addItem(b1);
    scene->addItem(b3);
    scene->addItem(mus->lever);

    connect(b1,SIGNAL(clicked()),this,SLOT(switch_menu()));
    connect(b3,SIGNAL(clicked()),this,SLOT(exit0()));
}
