#include "DateGenerator.h"
#include "Randomizer.h"
#include <string>



// 0 - День рождения
// 1 - Паспорт
// 2 - Согласие
// 3 - Права
// 4 - Полис
// 5 - Справка
// 6 - Сегодня


DateGenerator::DateGenerator()
{
    dates.resize(7);
    dates[6] = Date(31,5,2019);
}


/*!
    Заполнение массива дат. Принимает в себя число, характеризующее ошибку в одной дате.
    Использует огромное количество приёмов, предоставленных классом Date.
    \param p =0. Расширенный индекс документа или ноль: 0, 'P', 'A', 'H', 'X', 'M', 'R'.
*/
void DateGenerator::generate(char p){
    if(rand()%2) p*=-1;
    dates[0]=(18<<=dates[6]);
    ++(dates[0]);
    Date _14 =(dates[0]>>=14);

    if(p==-'P'){
        dates[1]=(dates[0]<<_14);
    } else {
        dates[1] =_14;
        dates[1]++;
        if(p=='P') --dates[1];
    }

    if(p==-'R'){
        dates[3]=dates[0]<<_14;
    } else {
        dates[3] =_14;
        dates[3]++;
        if(p=='R') --dates[3];
    }

    if(p==-'X'){
        dates[5]=(_14|=dates[6]);
    } else {
        if(p=='X') dates[5]=Date(31,04,2019);
        else dates[5]=~dates[6];
    }

    if(p==-'M'){
        dates[4]=dates[0]<<_14;
    } else {
        dates[4]=_14<<dates[5];
        if(p=='M') --dates[4];
    }

    if(p==-'A'){
        dates[2]=(_14|=dates[6]);
    } else {
        if(p=='A') dates[2]=Date(31,04,2019);
        else dates[2]=~dates[6];
    }

    if(p=='H' || p==-'H')
        --dates[0];
}

/*!
    Получение даты в формате строки по расширенному индексу документа.
    При некорректном вводе возвращает "сегодняшний" день.
    \param r Расширенный индекс документа: 'P', 'A', 'H', 'X', 'M', 'R'.
*/
string DateGenerator::operator[](char r){
    if(r=='A') return dates[2];
    if(r=='P') return dates[1];
    if(r=='R') return dates[3];
    if(r=='M') return dates[4];
    if(r=='X') return dates[5];
    if(r=='H') return dates[0];
    return dates[6];
}
