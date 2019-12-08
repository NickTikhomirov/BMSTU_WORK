#include "CursorManager.h"

#include <QPixmap>

/*!
   Курсор типа "Зелёная стрелочка"
*/
QCursor CursorManager::greenArrow(){
    return QCursor(QPixmap("://main//Pictures//other//Cursor0.png"),0,0);
}

/*!
   Курсор типа "Карандаш"
*/
QCursor CursorManager::pencil(){
    return QCursor(QPixmap("://main//Pictures//other//Cursor1.png"),0,0);
}


/*!
   Курсор типа "Лупа"
*/
QCursor CursorManager::glass(){
    return QCursor(QPixmap("://main//Pictures//other//Cursor3.png"),0,0);
}


/*!
   Курсор типа "Знак вопроса"
*/
QCursor CursorManager::cloud(){
    return QCursor(QPixmap("://main//Pictures//other//Cursor2.png"),0,0);
}
