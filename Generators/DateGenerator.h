#ifndef DATEGENERATOR_H
#define DATEGENERATOR_H


#include <vector>
#include "Logic/Date.h"

using std::vector;



/*!
    \brief Класс генерации и хранения дат.

    Содержит вектор объектов класса Date и способен заполнить его случайными данными на основании данных об ошибках.
    Объект этого класса содержится в объекте класса Level, благодаря чему доступен почти из любой точки программы.
*/
class DateGenerator
{
public:
    vector<Date> dates;
    DateGenerator();
    void generate(char p=0);
    string operator[](char);
};

#endif // DATEGENERATOR_H
