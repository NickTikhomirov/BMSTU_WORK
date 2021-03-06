#include "Mekanism.h"

using std::string;
using std::to_string;

/*!
    Конструктор класса, в котором инициализируются все объекты, производятся все подключения и задаются все координаты
    \param l Указатель на объект уровня
*/
Mekanism::Mekanism(Level *l)
{
    level = l;
    tick = new CustomButton(2, true, 6);
    cross = new CustomButton(3,true,8);
    placeHolder = new CustomButton(0,false,7);
    counter = new TextButton(timeString(),12,true,true,10);
    cup = new SwitchingButton(2);
    pause = new CustomButton(18,true,12);
    timer = new QTimer;
    timer->start(1000);

    tick->setPos(420,366);
    cross->setPos(440,366);
    pause->setPos(485,366);
    placeHolder->setPos(440,366);
    cup->setPos(400,295);
    counter->setPos(435,400);

    connect(timer,SIGNAL(timeout()), this, SLOT(time_flow()));
    connect(cup,SIGNAL(enable()),this,SLOT(setDebug()));
    connect(cup,SIGNAL(disable()),this,SLOT(unsetDebug()));
    connect(cross,SIGNAL(clicked()), this, SLOT(finishLevel_r()));
    connect(tick,SIGNAL(clicked()), this, SLOT(finishLevel_g()));
    connect(pause,SIGNAL(clicked()), this, SLOT(pausePress()));

    buttonReset();
}


/*!
    Перевод оставшегося времени в формат "м:с" в тип данных string
*/
string Mekanism::timeString(){
    int min = timeleft/60;
    int sec = timeleft%60;
    return to_string(min)+":"+to_string(sec);
}


/*!
    Метод обновления промежуточного счёта
*/
void Mekanism::scoreUpdate(){
    bool cor = level->mistakes->isCorrect();
    bool empt = (score==0);
    if(cor&empt) score = 2;
    if(empt) score+=1;
    score+=1;
    crossUnlock();
}

/*!
    Метод завершения уровня с зелёной кнопки
*/
void Mekanism::finishLevel_g(){
    char fin_score = 0;
    if(score>0 || !(level->mistakes->isCorrect())) fin_score = -3;
    else fin_score = 6;
    buttonReset();
    emit result(fin_score);
}

/*!
    Метод завершения уровня с красной кнопки
*/
void Mekanism::finishLevel_r(){
    char fin_score = 0;
    if(score==0 && level->mistakes->isCorrect()) fin_score = -2;
    else fin_score = score+2;
    buttonReset();
    emit result(fin_score);
}


/*!
    Метод завершения уровня принудительно
*/
void Mekanism::finishLevel_force(){
    char fin_score = 100;
    buttonReset();
    emit result(fin_score);
}


/*!
    Метод переключения счётчика в режим дебага
*/
void Mekanism::setDebug(){
    counter->setPlainText(QString::fromStdString(level->mistakes->toString()));
}


/*!
    Метод отключения режима дебага
*/
void Mekanism::unsetDebug(){
    counter->setPlainText(QString::fromStdString(timeString()));
}



/*!
    Метод реакции на обновление уровня
    \param noname не используется
*/
void Mekanism::levelUpdate(char){
    if(cup->param%3==0) {
        QString p = QString::fromStdString("://main//Pictures//switches//SwB"+to_string(cup->id)+".png");
        cup->setPixmap(QPixmap(p));
        cup->param/=3;
    }
}


/*!
    Метод обновления счётчика (внутреннего и строкового), который подключается к таймеру
*/
void Mekanism::time_flow(){
    if(timeleft>0) --timeleft;
    if((cup->param)%3!=0){
        counter->setPlainText(QString::fromStdString(timeString()));
    }
}


/*!
    Метод, вызываемый при нажатии кнопки паузы. Остановка таймера, изменение соответствующего параметра в уровне и сигнал на закрытие всех окон.
*/
void Mekanism::pausePress(){
    if(timer->isActive()) {
        timer->stop();
        level->paused = true;
    } else {
        timer->start();
        level->paused = false;
    }
}

/*!
    Обновление кнопок в начале уровня.
*/
void Mekanism::buttonReset(){
    score = 0;
    cross->safe_lock();
    placeHolder->unlock();
    cross->hide();
    placeHolder->show();
}

/*!
    Активация кнопки отказа посетителю после первой найденной ошибки.
*/
void Mekanism::crossUnlock(){
    cross->unlock();
    placeHolder->safe_lock();
    placeHolder->hide();
    cross->show();
}

