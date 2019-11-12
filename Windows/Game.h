#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>

#include <QMainWindow>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "WindowManager.h"
#include "SubWindow.h"

#include "MyPlayer.h"
#include "CursorManager.h"

#include "Graphics/Background.h"
#include "Graphics/CustomButton.h"
#include "Graphics/TextButton.h"
#include "Graphics/VeryComplicatedButton.h"
#include "Graphics/TwinButtons.h"
#include "Logic/ItemLockable.h"

using std::vector;

class Game : public QGraphicsView
{
    Q_OBJECT
    vector<ItemLockable*> contents;
    TwinButtons *b2;
public:
    explicit Game(QWidget *parent = nullptr);

    QGraphicsScene *scene;
    MyPlayer *mus;
    WindowManager *wm;
    SubWindow *sw;
    Level *level;
    short score;
    char levelsLeft;

    void mode_play();
    void mode_menu();
    void subwindowSetuper(char);
    void clear_items();
signals:
    void button_pressed();
    void addPoint();
    void waveOfChange(char);
public slots:
    void lock_screen();
    void unlock_screen();
    void show_stamps();

    void playersGuess(char,char);
    void level_finalize(char);

    void switch_menu();
    void switch_play();
    void switch_finalle();
    void switch_finalle2();
    void exit0();
};

#endif // MAINWINDOW_H
