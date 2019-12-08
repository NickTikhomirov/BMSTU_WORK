#ifndef CURSORMANAGER_H
#define CURSORMANAGER_H

#include <QCursor>

/*!
    \brief Словарь курсоров.

    Предоставляет доступ к четырём используемым в игре текстурам курсора - зелёной стрелке, карандашу, облачку со знаком вопроса и лупе.
    Принято решение хранить курсоры в отдельном классе с минимумом зависимостей, чтобы не возникало проблем с получением к ним доступа из любой точки программы.
*/
class CursorManager
{
public:
    static QCursor greenArrow();
    static QCursor pencil();
    static QCursor cloud();
    static QCursor glass();

};

#endif // CURSORMANAGER_H
