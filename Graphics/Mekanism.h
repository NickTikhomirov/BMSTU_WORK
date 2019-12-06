#ifndef MEKANISM_H
#define MEKANISM_H

#include <QGraphicsItem>
#include <QTimer>
#include "CustomButton.h"
#include "Logic/Level.h"
#include "TextButton.h"
#include "SwitchingButton.h"

class Mekanism : public QObject
{
    Q_OBJECT
    char score = 0;
public:
    Mekanism(Level *l);
    int timeleft = 180;
    int getScore();
    string timeString();
    CustomButton* placeHolder = nullptr;
    QTimer* timer = nullptr;
    CustomButton* cross = nullptr;
    CustomButton* tick = nullptr;
    CustomButton* pause = nullptr;
    SwitchingButton* cup = nullptr;
    TextButton *counter = nullptr;
    Level* level=nullptr;

    void buttonReset();
    void crossUnlock();
signals:
    void result(char);
public slots:
    void finishLevel_g();
    void finishLevel_r();
    void finishLevel_force();
    void time_flow();
    void pausePress();
    void setDebug();
    void unsetDebug();
    void levelUpdate(char);
    void scoreUpdate();
};

#endif // MEKANISM_H
