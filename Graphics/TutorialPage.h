#ifndef TUTORIALPAGE_H
#define TUTORIALPAGE_H

#include <string>
#include <vector>

#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QFont>

using std::string;
using std::vector;


/*!
    \brief Правила игры

    Класс реализует все логику окна правил игры - листание страниц, пасхалки на последних страницах и блокировку кнопок листания, а также содержит текст правил игры.
*/
class TutorialPage : public QObject
{
      Q_OBJECT
public:
    explicit TutorialPage(QObject *par=0);
    virtual ~TutorialPage();
    char page;
    char max;
    QGraphicsPixmapItem *guys;
    QGraphicsPixmapItem *captain;
    vector<string> t;
    QGraphicsTextItem *text;
public slots:
    void list_forward();
    void list_backward();
signals:
    void lock_left();
    void lock_right();
    void unlock_left();
    void unlock_right();
};

#endif // TUTORIALPAGE_H
