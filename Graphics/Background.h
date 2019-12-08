#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>



/*!
    \brief Фоновое изображение.

    Изображения можно устанавливать и просто на фон QGraphicsScene, но этот класс используется в программе в тех случаях,
    когда надо засечь смещение игроком курсора на фон - то есть прочь ото всех кнопок, на которых привязаны всплывающие облачка класса Follower.
*/
class Background : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Background(char n=0,QGraphicsItem *parent = nullptr);
private:
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void tingle();
    void sendCloud(int,int,char);
};

#endif // BACKGROUND_H
