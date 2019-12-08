#pragma once
#include <string>
#include <unordered_set>

using std::string;
using std::unordered_set;


/*!
    \brief Генератор случайных чисел.

    Класс, отвечающий за генерацию случайных чисел и значений из множества (unordered_set). Никаких полей поэтому все методы статические. Низкоуровневая база всей программы.
*/
class Randomizer
{
public:
    static int randInPool(int, int);
    static string toString(short);
    static bool generatePerc(short);
    static string generateDocumentNumber();
    static unsigned char randomForMistakes(char);
    static char stampDegenerator(char);

    template<class T>
    static T randOfSet(unordered_set<T> s){
        if(s.size()==1) return *(s.begin());
        auto random_it = std::next(std::begin(s),rand()%s.size());
        return *random_it;
    }
};

