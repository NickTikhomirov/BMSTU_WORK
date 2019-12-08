#include "Mistakes.h"

using std::to_string;
using std::unordered_map;


/*!
    Конструктор, в котором происходит первая и единственная за время жизни объекта генерация ошибок.
*/
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
    char fix = anyDateMistakes();
    if(fix!='H' && fix!=0 && mistakes['A']==7){
        mistakes = unordered_map<char,unsigned char>{
            {'A',1},
            {'P',0},
            {'R',1},
            {'M',1},
            {'X',1}
        };
    }
    if(mistakes['A']!=1){
        if(77%mistakes['A']!=0)
            mistakes['X']=0;
    }
}




/*!
    Метод, позволяющий проверить, существует ли ошибка с именем, фамилией или их порядком в выбранном документе.
    Считается, что в поле v передаётся только значение 2 или 4.
    Если ошибка найдена, она тут же удаляется и возвращается значение true, иначе - false.
    \param f Индекс документа (Варианты: P, A, R, X, M)
    \param v Код ошибки (Варианты: 2, 4)
*/
bool Mistakes::isItYour_Mistake_With_Name(char f, unsigned char v){
    unsigned char val = mistakes[f];
    if(val==0 || v==0) return false;
    if(val%2!=0) return false;
    if(val%8==0){
        mistakes[f]/=8;
        return true;
    }
    if((v==4 && val%4==0)||(v==2 && val%4!=0)){
        mistakes[f]/=v;
        return true;
    }
    return false;
}







/*!
    Проверка наличия на уровне ошибок с согласием на обработку персональных данных.
*/
bool Mistakes::isA(){
    return mistakes['X']==0;
}

/*!
    Проверка на ошибку "чёрный список".
*/
bool Mistakes::isB(){
    return mistakes['P']==0;
}

/*!
    Проверка, остались ли на уровне ещё ошибки.
*/
bool Mistakes::isCorrect(){
    for(auto a: mistakes){
        if(a.second!=1 && a.first!='X' && a.second!=0)
            return false;
    }
    return true;
}

/*!
    Проверка, принадлежит названная ошибка выбранному документу. Возвращается соответствующее значение и в случае истины эта ошибка удаляется.
    \param f Индекс документа (Варианты: P, A, R, X, M)
    \param v Код ошибки (Варианты: 0, 2, 3, 4, 5, 7, 11)
*/
bool Mistakes::isItYours(char id, unsigned char val){
    unsigned char value = mistakes[id];
    if(value==0){
        if(val==0){
            mistakes[id] = 1;
            return true;
        }
        return false;
    }
    if(val%2==0){
        return isItYour_Mistake_With_Name(id,val);
    }
    if(value%val==0){
        mistakes[id]/=val;
        return true;
    }
    return false;
}


/*!
    Преобразование текущих ненайденных ошибок в строку для Debug-вывода.
*/
string Mistakes::toString(){
    string p;
    if(isB()) return "B";
    if(isCorrect()) return "0";
    for(auto  a: mistakes){
        if(a.second!=1){
            p+=char(a.first)+to_string(a.second);
        }
    }
    return p;
}


/*!
    Преобразование текущих ненайденных ошибок в текст для финала уровня.
*/
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


/*!
    Проверка наличия на уровне ошибки неправильной страны.
    True: ошибки нет
*/
bool Mistakes::hasCorrectCountry(){return mistakes['A']%11!=0;}


/*!
    Проверка наличия на уровне ошибки диагноза психиатра.
    True: ошибки нет
*/
bool Mistakes::xHealthy(){
    return mistakes['X']%7!=0 || mistakes['X']==0;
}


/*!
    Проверка наличия на уровне ошибки номера полиса.
    True: ошибка есть
*/
bool Mistakes::medicineNumberMistakes(){return mistakes['M']%7==0;}


/*!
    Проверка правильности имени в выбранном документе.
    True: ошибки нет
    \param f Индекс документа (Варианты: P, A, R, X, M)
*/
bool Mistakes::isNameCorrect(char a){
    unsigned char r = mistakes[a];
    return (r%2!=0 || r%4==0);
}


/*!
    Проверка правильности фамилии в выбранном документе.
    True: ошибки нет
    \param f Индекс документа (Варианты: P, A, R, X, M)
*/
bool Mistakes::isName2Correct(char a){
    unsigned char r = mistakes[a];
    return r%4!=0 || r%8==0;
}


/*!
    Проверка запутанности имени-фамилии в выбранном документе.
    True: ошибка есть
    \param f Индекс документа (Варианты: P, A, R, X, M)
*/
bool Mistakes::isSwapped(char a){
    unsigned char r = mistakes[a];
    return r%8==0 && r!=0;
}


/*!
    Проверка неправильного шрифта в выбранном документе.
    True: ошибка есть
    \param f Индекс документа (Варианты: P, A, R, X, M)
*/
bool Mistakes::isSans(char a){
    unsigned char r = mistakes[a];
    return r%5==0 && r!=0;
}


/*!
    Проверка неправильной фотографии в выбранном документе.
    True: ошибки нет
    \param f Индекс документа (Варианты: P, A, R, X, M)
*/
bool Mistakes::isFaceCorrect(char a){
    unsigned char r = mistakes[a];
    return r%7!=0 || r==0;
}


/*!
    Проверка неправильной печати в выбранном документе.
    True: ошибка есть
    \param f Индекс документа (Варианты: P, A, R, X, M)
*/
bool Mistakes::isStampCorrect(char a){
    unsigned char r = mistakes[a];
    return r%11!=0 || r==0;
}


/*!
    Проверка ошибок с датой в выбранном документе.
    Возвращает расширенный индекс документа (Варианты: P, A, R, X, M, H), если ошибка есть.
    Возвращает 0, если ошибки нет.
*/
char Mistakes::anyDateMistakes(){
    if(isB()) return 0;
    for(auto a: mistakes){
        if(a.second%3==0 && a.second!=0)
            return a.first;
    }
    if(mistakes['A']%7==0) return 'H';
    return 0;
}





/*!
    "Разбирает" поле ошибок обратно на ошибки, которые преобразуются в их текстовое описание и подаются на выход.
    Используется только методом text_form().
    \param a Значение в поле документа. (Комментарий: избыточно)
    \param doc Расширенный индекс документа (Варианты: P, A, R, X, M, H).
*/
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


/*!
    Проверка кратности с последующим делением в случае истинности. Используется только методом interpret_high()
    \param val Делимое.
    \param eq Делитель.
*/
bool Mistakes::interpret_low(unsigned char &val, unsigned char eq){
    if(val==0 || val==1) return eq==val;
    if(val%eq==0){
        val/=eq;
        return true;
    } else return false;
}



/*!
    Распределяет значение как множитель одного из полей ошибок. В поле 'A' метод может положить только значения 7 или 11, остальные распределяются в него конструкторе.
    \param a Распределяемое значение.
*/
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





/*!
    Генерирует одну ошибку - число из множества {2, 3, 4, 5, 7, 8, 11}
    \param a Переменная для ошибки.
*/
void Mistakes::oneMistake(unsigned char &a){
    a = Randomizer::randomForMistakes(0);
}


/*!
    Генерирует две ошибки - пару разных чисел из множества {2, 3, 4, 5, 7, 8, 11}
    \param a Переменная для первой ошибки.
    \param b Переменная для второй ошибки.
*/
void Mistakes::twoMistakes(unsigned char &a, unsigned char &b){
    a = Randomizer::randomForMistakes(0);
    do{
        b=Randomizer::randomForMistakes(0);
        if(this->equals(a,b)==0) break;
    }while(true);
}




/*!
    Сравнение чисел а и b на равенство, но все чётные числа считаются равными друг другу
    \param a Первое сравниваемое число
    \param b Второе сравниваемое число
*/
bool Mistakes::equals(unsigned char a, unsigned char b){
    return (a==b || ((a%2==0) && (b%2==0)));
}


/*!
    Возвращает истину с шансом 10%. Используется для генерации случайных событий (чёрный список и ошибка в согласии на обработку персональных данных).
*/
bool Mistakes::maybeFlavor(){
    return Randomizer::generatePerc(10);
}

/*!
    Возвращает истину с шансом 50%. В текущей версии программы не используется.
*/
bool Mistakes::one_for_true_and_two_for_twrue(){
    return rand()%2==1;
}


/*!
    Возвращает истину с шансом 30%. Используется для определения случаев, когда ошибок не генерируется вообще.
*/
bool Mistakes::generateCorrectness(){
    return Randomizer::generatePerc(30);
    //return false;
}
