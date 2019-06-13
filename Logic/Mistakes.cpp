#include "Mistakes.h"

using std::to_string;

Mistakes::Mistakes()
{
    forA=1;
    forH=1;
    forM=1;
    forP=1;
    forR=1;
    forX=1;
    if(!generateCorrectness()){
        if(maybeFlavor())
            forA = Randomizer::randomForMistakes(1);
        else if(maybeFlavor())
            forH = 0;
        else {
            char a;
            if(one_for_true_and_two_for_twrue())
                oneMistake(a);
            else {
                char b;
                twoMistakes(a,b);
                makeSomebodyHappy(b);
            }
            makeSomebodyHappy(a);
        }
    }
    if(forA!=1) forX=0;
}

char Mistakes::for_(char a){
    switch(a){
        case 'P':return forP;
        case 'M':return forM;
        case 'X':return forX;
        case 'A':return forA;
        case 'R':return forR;
        case 'H':return forH;
    }
    return 1;
}





bool Mistakes::isItYours_forH(char a){
    if(a==0 && forH==0) {
        forH=1;
        return true;
    }
    if(a==5 || a==11 || a==3){
        if(forH%a==0){
            forH/=a;
            return true;
        } else return false;
    } else return false;
}

bool Mistakes::isItYours_forA(char a){
    if(a==-1 || a==11 || a==7) return false;
    if(a==2 || a==4)
        return isItYour_Mistake_With_Name(forA,a);
    if(forA%a==0) {
        forA/=a;
        return true;
    }
    return false;
}

bool Mistakes::isItYours_forP(char a){
    if(a==-1) return false;
    if(a==2 || a==4)
        return isItYour_Mistake_With_Name(forP,a);
    if(forP%a==0) {
        forP/=a;
        return true;
    }
    return false;
}
bool Mistakes::isItYours_forM(char a){
    if(a==7 || a==-1) return false;
    if(a==2 || a==4)
        return isItYour_Mistake_With_Name(forM,a);
    if(forM%a==0) {
        forM/=a;
        return true;
    }
    return false;
}
bool Mistakes::isItYours_forR(char a){
    if(a==-1) return false;
    if(a==2 || a==4)
        return isItYour_Mistake_With_Name(forR,a);
    if(forR%a==0) {
        forR/=a;
        return true;
    }
    return false;
}

bool Mistakes::isItYours_forX(char a){
    if(a==-1 && forX<0) {
        forX*=-1;
        return true;
    }
    if(a==2 || a==4)
        return isItYour_Mistake_With_Name(forX,a);
    if(forX%a==0) {
        forX/=a;
        return true;
    }
    return false;
}



bool Mistakes::isItYour_Mistake_With_Name(char &f, char v){
    if(f==0 || v==0) return false;
    if(f%2!=0) return false;
    if(f%8==0){
        f/=8;
        return true;
    }
    if(f%8==v){
        f/=v;
        return true;
    }
    return false;
}








bool Mistakes::isA(){
    return forX==0;
}

bool Mistakes::isB(){
    return forH==0;
}

bool Mistakes::isCorrect(){
    return forP==1 && forH==1 && forA==1 && forM==1 && forR==1 && forX==1;
}

bool Mistakes::isDinner(){
    return forH%5==0 && !isB();
}

bool Mistakes::isItYours(char id, char val){
    switch(id){
        case 'H': return isItYours_forH(val);
        case 'A': return isItYours_forA(val);
        case 'P': return isItYours_forP(val);
        case 'M': return isItYours_forM(val);
        case 'R': return isItYours_forR(val);
        case 'X': return isItYours_forX(val);
    }
    return false;
}

string Mistakes::toString(){
    string p;
    if(isB()) return "B";
    if(isCorrect()) return "0";
    if(forA!=1) p+="A"+to_string(forA);
    if(forH!=1) p+="H"+to_string(forH);
    if(forP!=1) p+="P"+to_string(forP);
    if(forM!=1) p+="M"+to_string(forM);
    if(forX!=1) p+="X"+to_string(forX);
    if(forR!=1) p+="R"+to_string(forR);
    return p;
}


QString Mistakes::text_form(){
    if(forX==0) return " ";
    string p = "Оставшиеся ошибки:\n";
    if(isCorrect()) p+="<Отсутствуют>";
    else if(isB()) p+="Посетитель в чёрном списке";
    else if(forA>1) p+="Согласие на обработку:\n"+interpret_high(forA,'A');
    else {

        if(forP>1||forH>1) p+="Паспорт:\n";
        if(forP>1) p+=interpret_high(forP,'P')+"\n";
        if(forH>1) p+=interpret_high(forH,'H')+"\n";

        if(forM>1) p+="Полис:\n"+interpret_high(forM,'M')+"\n";
        if(forR>1) p+="Права:\n"+interpret_high(forR,'R')+"\n";

        if(forX!=1) {
            p+="Справка:\n";
            if(forX<0){
                forX*=-1;
                p+=" - Номер полиса";
                p+="\n";
            }
            if(forX>1)p+=interpret_high(forX,'X')+"\n";
        }
    }
    return QString::fromStdString(p);
}


bool Mistakes::hasCorrectCountry(){return (forH%11!=0 || forH==0);}
bool Mistakes::xHealthy(){return (forX%7!=0);}
bool Mistakes::medicineNumberMistakes(){return (forX<0);}

bool Mistakes::isNameCorrect(char a){return (for_(a)%8!=2);}
bool Mistakes::isName2Correct(char a){return (for_(a)%8!=4);}
bool Mistakes::isSwapped(char a){return (for_(a)%8==0);}
bool Mistakes::isSans(char a){return (for_(a)%5==0);}
bool Mistakes::isFaceCorrect(char a){return for_(a)%7!=0;}
bool Mistakes::isStampCorrect(char a){return for_(a)%11!=0;}

char Mistakes::anyDateMistakes(){
    if(isB()) return 0;
    if(forA%3==0) return 'A';
    if(forH%3==0) return 'H';
    if(forP%3==0) return 'P';
    if(forX%3==0) return 'X';
    if(forM%3==0) return 'M';
    if(forR%3==0) return 'R';
    return 0;
}






string Mistakes::interpret_high(char a, char doc){
    string p=" ";
    if(a==1 || a==0) return ".";
    if(interpret_low(a,8)) p+=" - Порядок имя-фамилия";
    if(interpret_low(a,4)) p+=" - Фамилия";
    if(interpret_low(a,2)) p+=" - Имя";
    if(a!=1 && p.length()>1) p+="\n";

    if(interpret_low(a,5)) {
        if(doc=='H') p+=" - Обеденное время";
        else p+=" - Шрифт";
        if(a!=1) p+="\n";
    }

    if(interpret_low(a,3)) {
        if(doc=='H') p+=" - Дата рождения";
        else p+=" - Дата выдачи";
        if(a!=1) p+="\n";
    }

    if(interpret_low(a,7)) {
        if(doc=='X') p+=" - Диагноз";
        else p+=" - Фото";
        if(a!=1) p+="\n";
    }

    if(interpret_low(a,11)) {
        if(doc=='H') p+=" - Страна рождения";
        else p+=" - Печать";
    }
    return p.substr(1,p.length()-1);
}

bool Mistakes::interpret_low(char &val, char eq){
    if(val==0 || val==1) return eq==val;
    if(val%eq==0){
        val/=eq;
        return true;
    } else return false;
}




void Mistakes::makeSomebodyHappy(char a){
    if(a==-1){
        forX*=a;
        return;
    }
    switch(
           (a==7)+rand()%(3+(a!=7)+(a==3 || a==5 || a==11))
          ){
        case 0:{
            forM*=a;
            break;
        }
        case 1:{
            forP*=a;
            break;
        }
        case 2:{
            forX*=a;
            break;
        }
        case 3:{
            forR*=a;
            break;
        }
        case 4:{
            forH*=a;
            break;
        }
    }
}






void Mistakes::oneMistake(char &a){
    a = Randomizer::randomForMistakes(0);
}

void Mistakes::twoMistakes(char &a, char &b){
    a = Randomizer::randomForMistakes(0);
    do{
        b=Randomizer::randomForMistakes(0);
        if(this->equals(a,b)==0) break;
    }while(true);
}





bool Mistakes::equals(char a, char b){
    return (a==b || ((a%2==0) && (b%2==0)));
}

bool Mistakes::maybeFlavor(){
    return Randomizer::generatePerc(10);
}

bool Mistakes::one_for_true_and_two_for_twrue(){
    return rand()%2==1;
}

bool Mistakes::generateCorrectness(){
    return Randomizer::generatePerc(30);
}


/*
 * A:
 * 2 - Имя
 * 3 - Дата
 * 4 - Фамилия
 * 5 - Комик Санс))))
 * 8 - Перепутаны местами
 *
 * P, X, M, R, H:
 *-1 - Номер полиса
 * 2 - Имя
 * 3 - Дата
 * 4 - Фамилия
 * 8 - Перепутаны
 * 5 - Комик Санс/прибытие в обед
 * 7 - Фото/вердикт
 * 11 - Печать/страна
 *
 * 3,5,11
 * 2,4,7,8
 * -1
 *
*/
