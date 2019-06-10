#include "CursorManager.h"

#include <QPixmap>

QCursor CursorManager::greenArrow(){
    return QCursor(QPixmap("://main//Pictures//other//Cursor0.png"),0,0);
}

QCursor CursorManager::pencil(){
    return QCursor(QPixmap("://main//Pictures//other//Cursor1.png"),0,0);
}

QCursor CursorManager::glass(){
    return QCursor(QPixmap("://main//Pictures//other//Cursor3.png"),0,0);
}


QCursor CursorManager::cloud(){
    return QCursor(QPixmap("://main//Pictures//other//Cursor2.png"),0,0);
}
