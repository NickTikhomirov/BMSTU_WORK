#include "WindowManager.h"


WindowManager::WindowManager(QObject *parent) : QObject(parent)
{
    level=0;
    first=0;
    second=0;
    passport = 0;
    agreement = 0;
    medicine = 0;
    rights = 0;
    psycho = 0;
    stenography = 0;
    tutorial = new AdditionalWindow(7);

    tutorial->setCursor(CursorManager::greenArrow());

}



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
}

void WindowManager::clear_dynamics(){
    if(passport!=0) delete passport;
    if(agreement!=0) delete agreement;
    if(stenography!=0) delete stenography;
    if(medicine!=0) delete medicine;
    if(rights!=0)delete rights;
    if(psycho!=0) delete psycho;

    passport=0;
    agreement=0;
    stenography=0;
    medicine=0;
    rights=0;
    psycho=0;
}


void WindowManager::provide_passport(char r){
    if(r==6) emit provide('H',3);
    else if(r==12) emit provide('H',11);
    else emit provide('P',r);
}

void WindowManager::provide_x(char r){
    emit provide('X',r);
}

void WindowManager::provide_license(char r){
    emit provide('R',r);
}

void WindowManager::provide_medicine(char r){
    emit provide('M',r);
}

void WindowManager::provide_agreement(char r){
    emit provide('A',r);
}
void WindowManager::s_kill(){
    kill();
}

void WindowManager::kill(){
    close1();
    close2();
}



void WindowManager::close1(){
    if(first!=0){
        if(first->isVisible()) first->close();
        first=0;
    }
}

void WindowManager::close2(){
    if(second!=0){
        if(second->isVisible()) second->close();
        second=0;
    }
}








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


void WindowManager::close(AdditionalWindow *pr){
    if(pr==0) return;
    if(pr==first){
        first->close();
        first=0;
    }
    if(pr==second){
        second->close();
        second=0;
    }
}

void WindowManager::toggle(AdditionalWindow *pr){
    if(pr==0) return;
    if(pr==first || pr==second) close(pr);
    else open(pr);

}

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

void WindowManager::openW(char a){
    if(a==1){ open(passport);
    } else if(a==2){ open(agreement);
    } else if(a==3){ open(medicine);
    } else if(a==4){ open(rights);
    } else if(a==5){ open(psycho);
    } else if(a==6){ open(stenography);
    } else if(a==7){ open(tutorial);
    }
}

void WindowManager::closeW(char a){
    if(a==1){ close(passport);
    } else if(a==2){ close(agreement);
    } else if(a==3){ close(medicine);
    } else if(a==4){ close(rights);
    } else if(a==5){ close(psycho);
    } else if(a==6){ close(stenography);
    } else if(a==7){ close(tutorial);
    }
}







void WindowManager::open_agreement(){toggleW(2);}
void WindowManager::open_stenography(){toggleW(6);}
void WindowManager::open_tutorial(){toggleW(7);}


void WindowManager::open_passport(){
    if(level!=0)
        if(level->agreementMistakes()){
            emit privacyBreak();
            return;
    }
    toggleW(1);
}
void WindowManager::open_medicine(){
    if(level!=0)
        if(level->agreementMistakes()){
            emit privacyBreak();
            return;
    }
    toggleW(3);
}
void WindowManager::open_license(){
    if(level!=0)
        if(level->agreementMistakes()){
            emit privacyBreak();
            return;
    }
    toggleW(4);
}
void WindowManager::open_x(){
    if(level!=0)
        if(level->agreementMistakes()){
            emit privacyBreak();
            return;
    }
    toggleW(5);
}
