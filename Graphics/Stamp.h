#ifndef STAMP_H
#define STAMP_H

#include "SimpleButton.h"
#include "Generators/Randomizer.h"
#include "Resizer.h"

using std::to_string;

/*!
    \brief Печать в документе

    Печати пришлось вынести в отдельный класс, а не использовать, например, Face или SimpleButton, потому что печати имеют почти прозрачные текстуры,
    а все реализованные до сих пор кнопки "чувствуют" нажатия только в те части, где есть рисунок. В своём конструкторе объекты класса Stamp решают эту проблему.
*/
class Stamp : public SimpleButton
{
    Q_OBJECT
public:
    Stamp(char,double k=1,bool corr=true,QGraphicsItem *parent = nullptr);
};

#endif // STAMP_H
