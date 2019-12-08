#include "WindowManager.h"

/*!
  Создание окна с правилами.
*/
WindowManager::WindowManager(QObject *parent) : QObject(parent)
{
    level=nullptr;
    first=nullptr;
    second=nullptr;
    passport = nullptr;
    agreement = nullptr;
    medicine = nullptr;
    rights = nullptr;
    psycho = nullptr;
    stenography = nullptr;
    tutorial = new AdditionalWindow(7);
    tutorial->setCursor(CursorManager::greenArrow());
}


/*!
  Создание всех окон с документами, установка их курсоров и подключение сигналов от них.
*/
void WindowManager::dynamic_documents(){
    passport = new AdditionalWindow(1,level);
    agreement = new AdditionalWindow(2,level);
    medicine = new AdditionalWindow(3,level);
    rights = new AdditionalWindow(4,level);
    psycho = new AdditionalWindow(5,level);
    stenography = new AdditionalWindow(6,level);

    passport->setCursor(CursorManager::pencil());
    agreement->setCursor(CursorManager::pencil());
    medicine->setCursor(CursorManager::pencil());
    rights->setCursor(CursorManager::pencil());
    psycho->setCursor(CursorManager::pencil());
    stenography->setCursor(CursorManager::greenArrow());

    connect(passport,SIGNAL(provide(char)),this,SLOT(provide_passport(char)));
    connect(rights,SIGNAL(provide(char)),this,SLOT(provide_license(char)));
    connect(psycho,SIGNAL(provide(char)),this,SLOT(provide_x(char)));
    connect(medicine,SIGNAL(provide(char)),this,SLOT(provide_medicine(char)));
    connect(agreement,SIGNAL(provide(char)),this,SLOT(provide_agreement(char)));
}


/*!
  Закрытие и удаление всех окон кроме окна правил.
*/
void WindowManager::clear_dynamics(){
    kill();
    delete passport;
    delete agreement;
    delete stenography;
    delete medicine;
    delete rights;
    delete psycho;
    passport=nullptr;
    agreement=nullptr;
    stenography=nullptr;
    medicine=nullptr;
    rights=nullptr;
    psycho=nullptr;
}

/*!
  Обработка сигнала от окна паспорта для транспортировки в класс Game, откуда он будет передан на проверку ошибок.
*/
void WindowManager::provide_passport(char r){
    if(r==6) emit provide('A',7);
    else if(r==12) emit provide('A',11);
    else emit provide('P',r);
}


/*!
  Обработка сигнала от окна справки для транспортировки в класс Game, откуда он будет передан на проверку ошибок.
*/
void WindowManager::provide_x(char r){
    if(r==6) emit provide('M',7);
    else emit provide('X',r);
}


/*!
  Обработка сигнала от окна водительских прав для транспортировки в класс Game, откуда он будет передан на проверку ошибок.
*/
void WindowManager::provide_license(char r){
    emit provide('R',r);
}


/*!
  Обработка сигнала от окна полиса для транспортировки в класс Game, откуда он будет передан на проверку ошибок.
*/
void WindowManager::provide_medicine(char r){
    emit provide('M',r);
}


/*!
  Обработка сигнала от окна согласия на обработку для транспортировки в класс Game, откуда он будет передан на проверку ошибок.
*/
void WindowManager::provide_agreement(char r){
    emit provide('A',r);
}


/*!
  Закрытие активных окон.
*/
void WindowManager::kill(){
    close1();
    close2();
}



/*!
  Закрытие первого активного окна.
*/
void WindowManager::close1(){
    if(first!=0){
        disconnect(first, SIGNAL(closed()), this, SLOT(close1()));
        if(first->isVisible()) first->close();
        first=0;
    }
}


/*!
  Закрытие второго активного окна.
*/
void WindowManager::close2(){
    if(second!=0){
        disconnect(second, SIGNAL(closed()), this, SLOT(close2()));
        if(second->isVisible()) second->close();
        second=0;
    }
}







/*!
  Открытие выбранного из принадлежащих окон. Вызывается самим собой от своих объектов.
*/
void WindowManager::open(AdditionalWindow *pr){
    if(pr==0) return;
    if(first!=pr && second!=pr){
        if(first==0) {
            first = pr;
            first->show();
            connect(first, SIGNAL(closed()), this, SLOT(close1()));
        } else if(second==0) {
            second = pr;
            second->show();
            connect(second, SIGNAL(closed()), this, SLOT(close2()));
        }
    }
}


/*!
  Закрытие выбранного из принадлежащих окон. Вызывается самим собой от своих объектов.
*/
void WindowManager::close(AdditionalWindow *pr){
    if(pr==0) return;
    if(pr==first){
        first->close();
        first=0;
    } else
    if(pr==second){
        second->close();
        second=0;
    }
}

/*!
  Инвертирование состояния выбранного из принадлежащих окон (по объекту).
*/
void WindowManager::toggle(AdditionalWindow *pr){
    if(pr==0) return;
    if(pr==first || pr==second) close(pr);
    else open(pr);

}


/*!
  Инвертирование состояния выбранного из принадлежащих окон (по оконному индексу).
*/
void WindowManager::toggleW(char a){
    if(a==1){ toggle(passport);
    } else if(a==2){ toggle(agreement);
    } else if(a==3){ toggle(medicine);
    } else if(a==4){ toggle(rights);
    } else if(a==5){ toggle(psycho);
    } else if(a==6){ toggle(stenography);
    } else if(a==7){ toggle(tutorial);
    }
}



/*!
  Переключение окна правил.
*/
void WindowManager::open_tutorial(){toggleW(7);}



/*!
  Переключение окна согласия.
*/
void WindowManager::open_agreement(){
    if(level->paused) return;
    toggleW(2);
}

/*!
  Переключение окна досье.
*/
void WindowManager::open_stenography(){
    if(level->paused) return;
    toggleW(6);
}


/*!
  Переключение окна паспорта.
*/
void WindowManager::open_passport(){
    if(level->paused) return;
    if(level->mistakes->isA()){
        emit privacyBreak();
        return;
    }
    toggleW(1);
}

/*!
  Переключение окна полиса.
*/
void WindowManager::open_medicine(){
    if(level->paused) return;
    if(level->mistakes->isA()){
        emit privacyBreak();
        return;
    }
    toggleW(3);
}


/*!
  Переключение окна прав.
*/
void WindowManager::open_license(){
    if(level->paused) return;
    if(level->mistakes->isA()){
        emit privacyBreak();
        return;
    }
    toggleW(4);
}


/*!
  Переключение окна справки от психиатра.
*/
void WindowManager::open_x(){
    if(level->paused) return;
    if(level->mistakes->isA()){
        emit privacyBreak();
        return;
    }
    toggleW(5);
}



/*!
  Команда закрытия всех окон, какие нельзя читать при игре на паузе.
*/
void WindowManager::pausePressed(){
    close(passport);
    close(psycho);
    close(medicine);
    close(rights);
    close(agreement);
    close(stenography);
}
