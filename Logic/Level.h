#pragma once

#include <string>

#include "Generators/DateGenerator.h"
#include "Generators/Randomizer.h"
#include "Generators/NameGenerator.h"
#include "Mistakes.h"

using std::string;



/*!
    \brief Класс уровня. Содержит информацию о посетителе и уровне, доступен почти отовсюду.

    Генерирует и хранит информацию о посетителе - имя, фамилию, лицо, номер страхового полиса.
    Кроме того, генерирует и хранит объекты классов DateGenerator и Mistakes, в силу чего также управляет ошибками и датами.
    На основании предоставляемых уровнем данных заполняются все документы в игре.
    Помимо этого является местом хранения информации, поставлен ли уровень на паузу, так как объект этого класса доступен практически отовсюду, и это просто удобно.
*/

class Level
{
public:
    DateGenerator dates;
	Level();
    ~Level();
    string name;
    string secondName;
    string birtday;
    char face;
    Mistakes *mistakes;
    bool paused = false;
    string insuranceNumber;

    string getNameFor(char);
    string getName2For(char);

    void setBlackList();
    void regenerate();
};

