#include "Mistakes.h"

using std::to_string;
using std::unordered_map;

Mistakes::Mistakes()
{
    mistakes = unordered_map<char,unsigned char>{
        {'A',1},
        {'P',1},
        {'R',1},
        {'M',1},
        {'X',1}
    };
    if(!generateCorrectness()){
        if(maybeFlavor())
            mistakes['A'] = Randomizer::randomForMistakes(1);
        else if(maybeFlavor())
            mistakes['P'] = 0;
        else {
            unsigned char a,b;
            twoMistakes(a,b);
            makeSomebodyHappy(a);
            makeSomebodyHappy(b);
        }
    }
    if(mistakes['A']!=1){
        if(77%mistakes['A']!=0)
            mistakes['X']=0;
    }
}





bool Mistakes::isItYour_Mistake_With_Name(unsigned char &f, unsigned char v){
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
    return mistakes['X']==0;
}

bool Mistakes::isB(){
    return mistakes['P']==0;
}

bool Mistakes::isCorrect(){
    for(std::pair a: mistakes){
        if(a.second!=1 && a.first!='X' && a.second!=0)
            return false;
    }
    return true;
}

bool Mistakes::isItYours(char id, unsigned char val){
    if(mistakes[id]==0){
        if(val==0){
            mistakes[id] = 1;
            return true;
        }
        return false;
    }
    if(val%2==0){
        return isItYour_Mistake_With_Name(mistakes[id],val);
    }
    if(mistakes[id]%val==0){
        mistakes[id]/=val;
        return true;
    }
    return false;
}

string Mistakes::toString(){
    string p;
    if(isB()) return "B";
    if(isCorrect()) return "0";
    for(std::pair a: mistakes){
        if(a.second!=1){
            p+=char(a.first)+to_string(a.second);
        }
    }
    return p;
}


QString Mistakes::text_form(){
    string p = "Оставшиеся ошибки:\n";
    if(isCorrect()) p+="<Отсутствуют>";
    else if(isB()) p+="Посетитель в чёрном списке";
    else if(mistakes['A']>1) p+="Согласие на обработку:\n"+interpret_high(mistakes['A'],'A');
    else {

        if(mistakes['P']>1||(mistakes['A']>1&&mistakes['X']!=0)) p+="Паспорт:\n";
        if(mistakes['P']>1) p+=interpret_high(mistakes['P'],'P')+"\n";
        if(mistakes['A']>1) p+=interpret_high(mistakes['A'],'H')+"\n";

        if(mistakes['M']>1) p+="Полис:\n"+interpret_high(mistakes['M'],'M')+"\n";
        if(mistakes['R']>1) p+="Права:\n"+interpret_high(mistakes['R'],'R')+"\n";
        if(mistakes['X']>1) p+="Справка:\n"+interpret_high(mistakes['X'],'X')+"\n";
    }
    return QString::fromStdString(p);
}


bool Mistakes::hasCorrectCountry(){return mistakes['A']%11!=0;}
bool Mistakes::xHealthy(){
    return mistakes['X']%7!=0 || mistakes['X']==0;
}
bool Mistakes::medicineNumberMistakes(){return mistakes['M']%7==0;}

bool Mistakes::isNameCorrect(char a){
    unsigned char r = mistakes[a];
    return (r%2!=0 || r%4==0);
}
bool Mistakes::isName2Correct(char a){
    unsigned char r = mistakes[a];
    return r%4!=0 || r%8==0;
}
bool Mistakes::isSwapped(char a){
    unsigned char r = mistakes[a];
    return r%8==0 && r!=0;
}
bool Mistakes::isSans(char a){
    unsigned char r = mistakes[a];
    return r%5==0 && r!=0;
}
bool Mistakes::isFaceCorrect(char a){
    unsigned char r = mistakes[a];
    return r%7!=0 || r==0;
}
bool Mistakes::isStampCorrect(char a){
    unsigned char r = mistakes[a];
    return r%11!=0 || r==0;
}

char Mistakes::anyDateMistakes(){
    if(isB()) return 0;
    for(auto a: mistakes){
        if(a.second%3==0 && a.second!=0)
            return a.first;
    }
    if(mistakes['A']%7==0) return 'H';
    return 0;
}






string Mistakes::interpret_high(unsigned char a, char doc){
    string p=" ";
    if(doc=='H') {
        if(interpret_low(a,3))
            p+=" - Дата рождения\n";
        if(interpret_low(a,11))
            p+=" - Страна рождения";
        return p.substr(1,p.length()-1);
    }

    if(a==1 || a==0) return ".";
    if(interpret_low(a,8)) p+=" - Порядок имя-фамилия";
    if(interpret_low(a,4)) p+=" - Фамилия";
    if(interpret_low(a,2)) p+=" - Имя";
    if(a!=1 && p.length()>1) p+="\n";

    if(interpret_low(a,5)) {
        p+=" - Шрифт";
        if(a!=1) p+="\n";
    }

    if(interpret_low(a,3)) {
        p+=" - Дата выдачи";
        if(a!=1) p+="\n";
    }

    if(interpret_low(a,7)) {
        if(doc=='X') p+=" - Диагноз";
        else if(doc=='M') p+=" - Номера полиса в самом полисе и справке";
        else p+=" - Фото";
        if(a!=1) p+="\n";
    }

    if(interpret_low(a,11)) {
        p+=" - Печать";
    }
    return p.substr(1,p.length()-1);
}

bool Mistakes::interpret_low(unsigned char &val, unsigned char eq){
    if(val==0 || val==1) return eq==val;
    if(val%eq==0){
        val/=eq;
        return true;
    } else return false;
}




void Mistakes::makeSomebodyHappy(unsigned char a){
    switch(
           rand()%(4+(a==7 || a==11))
          ){
        case 0:{
            mistakes['M']*=a;
            break;
        }
        case 1:{
            mistakes['P']*=a;
            break;
        }
        case 2:{
            mistakes['X']*=a;
            break;
        }
        case 3:{
            mistakes['R']*=a;
            break;
        }
        case 4:{
            mistakes['A']*=a;
            break;
        }
    }
}






void Mistakes::oneMistake(unsigned char &a){
    a = Randomizer::randomForMistakes(0);
}

void Mistakes::twoMistakes(unsigned char &a, unsigned char &b){
    a = Randomizer::randomForMistakes(0);
    do{
        b=Randomizer::randomForMistakes(0);
        if(this->equals(a,b)==0) break;
    }while(true);
}





bool Mistakes::equals(unsigned char a, unsigned char b){
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
    //return false;
}
