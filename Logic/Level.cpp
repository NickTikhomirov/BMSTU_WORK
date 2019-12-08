#include "Level.h"

using std::string;
using std::to_string;


Level::Level()
{
    mistakes = nullptr;
    regenerate();
}


Level::~Level()
{
    delete mistakes;
}


/*!
    Получение имени человека для документа.
    Сразу же производит перегенерацию имени, если объект класса ошибок диктует, что должна быть ошибка.
    Проще говоря, документ по своему индексу получает значение поля и использует (если нет необходимости предварительно поменять местами имя и фамилию).
    \param a Индекс документа (Варианты: P, A, R, M, X)
*/
string Level::getNameFor(char a){
    if(mistakes->isNameCorrect(a)) return name;
    else if(rand()%2) return (NameGenerator::degenerateName(name));
    else {
        string p;
        do p = NameGenerator::generateName();
        while(p==(name));
        return p;
    }
}

/*!
    Получение фамилии человека для документа.
    Сразу же производит перегенерацию фамилии, если объект класса ошибок диктует, что должна быть ошибка.
    Проще говоря, документ по своему индексу получает значение поля и использует (если нет необходимости предварительно поменять местами имя и фамилию).
    \param a Индекс документа (Варианты: P, A, R, M, X)
*/
string Level::getName2For(char a){
    if(mistakes->isName2Correct(a)) return secondName;
    else if(rand()%2) return (NameGenerator::degenerateName(secondName));
    else {
        string p;
        do p = NameGenerator::generateName2();
        while(p==(secondName));
        return p;
    }
}


/*!
    Метод, который необходимо вызывать при смене уровня.
    Обновляет данные ошибок, дат, полей для имени, фамилии, полиса и лица
*/
void Level::regenerate(){
    delete mistakes;
    mistakes = new Mistakes;
    if(mistakes->isB()) setBlackList();
    else {
        face = (short)Randomizer::randInPool(1, 17);
        name = NameGenerator::generateName();
        secondName = NameGenerator::generateName2();
    }
    insuranceNumber = Randomizer::generateDocumentNumber();

    dates = DateGenerator();
    dates.generate(mistakes->anyDateMistakes());
}


/*!
    Хардкод-инициализация полей данными чёрного списка. Используется методом regenerate(), и этого достаточно.
*/
void Level::setBlackList(){
    face=1;
    name = "Evgeny";
    secondName = "Ponasenkov";
}
