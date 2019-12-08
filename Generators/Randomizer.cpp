#include "Randomizer.h"
#include <string>
#include <unordered_set>

using std::string;
using std::to_string;
using std::pair;
using std::unordered_set;


/*!
    Преобразует число в его строковое представление. Числа 1-9 представляет в виде 01-09.
    \param a Само число.
*/
string Randomizer::toString(short a) {
    string p;
    if (a == a % 10) p = "0" + to_string(a);
    else p = to_string(a);
    return p;
}



/*!
    Генерирует одно число из множества {2, 3, 4, 5, 7, 8, 11}
    Используется генератором ошибок
    \param a Характеристика числа: при a=0 классическое (2,3,4,5,8), при a=1 расширенное (2,3,4,5,7,8,11).
*/
unsigned char Randomizer::randomForMistakes(char a){
    char c;
    if(a==1){
        c=rand()%5;
        if(c==1) c = 8;
        if(c==0) c = 5;
    } else {
        c = rand()%7;
        if(c==1) c=7;
        if(c==6) c=8;
        if(c==0) c=11;
    }
    return c;
}


/*!
    Генерирует целое число в диапазоне [b;e]
    \param b Начало отрезка
    \param e Конец отрезка
*/
int Randomizer::randInPool(int b, int e) {
    if (e < b) return 0;
    if (e == b) return b;
    return b + (rand() % (e - b + 1));
}


/*!
    Возвращает истину с вероятностью a%
    \param a Шанс получения истины в процентах
*/
bool Randomizer::generatePerc(short a) {
	if (a > 99) return true;
	if (a < 1) return false;
    return (randInPool(1, 100)<a);
}


/*!
    Генерирует число с десятичной записью длиной в 11 символов (может начинаться с нуля).
    Используется для получения номеров документов (полис, паспорт, справка).
*/
string Randomizer::generateDocumentNumber(){
    string p = to_string(rand()%10);
    for(int i=0;i<9;i++)
        p+=to_string(rand()%10);
    return p;
}



/*!
    Получает на вход число из множества {5,6,7,8} и возвращает число из множества {-8, -7, -6, -5, 5, 6, 7, 8},
используя генерацию случайных чисел и некоторые правила. Этот метод нужен для получения неправильной печати в документе.
    \param a Число из множества {5,6,7,8}
*/
char Randomizer::stampDegenerator(char a){
    if(rand()%4)
        return -a;
    if(56%a==0){
        return ((rand()%2+5)*(-1+rand()%2*2));
    }
    unordered_set<char> variants {-8,-7,-6,-5,5,6,7,8};
    variants.erase(variants.find(a));
    variants.erase(variants.find(-a));
    return Randomizer::randOfSet<char>(variants);


    /*
    if(a==5)
        return ((rand()%3+6)*(-1+rand()%2*2));
    if(56%a==0)
        return ((rand()%2+5)*(-1+rand()%2*2));
    if(a==6){
        return (a=(-1+rand()%2*2)*(rand()%3+6))-(a==6)+(a==-6);
    }
    */
}
