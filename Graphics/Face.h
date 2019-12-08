#ifndef FACE_H
#define FACE_H

#include "Graphics/SimpleButton.h"
#include "Resizer.h"
#include "Generators/Randomizer.h"

using std::to_string;


/*!
    \brief Изображение гостя

    Изображение, которое не меняет внешний вид и не реагирует на наведение курсора, но может отправлять сигналы при нажатии на него, а также может быть изменено по сигналу с числовым значением.
*/
class Face : public SimpleButton
{
    Q_OBJECT
public:
    Face(char,double k=1,bool corr=true,QGraphicsItem *parent = nullptr);
public slots:
    void regenerate(char);
};

#endif // FACE_H
