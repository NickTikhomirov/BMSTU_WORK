#ifndef NAMEGENERATOR_H
#define NAMEGENERATOR_H
#include <string>

using std::string;


/*!
    \brief Сборник словарей имён, фамилий и стран.

    Содержит методы для генерации случайного имени, страны или фамилии - как правильных, так и неправильных. Работает силами класса Randomizer и фантазии разработчика,
 а сам является основой для функционирования самой наглядной части системы документов.
    Методы вынесены в отдельный класс, чтобы не забивать важные классы.
*/
class NameGenerator{
public:
    static string generateName();
    static string generateName2();
    static string generateCountry();
    static string generateBadCountry();
    static string degenerateName(string);
};

#endif // NAMEGENERATOR_H
