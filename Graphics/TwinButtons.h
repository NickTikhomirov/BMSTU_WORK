#ifndef TWINBUTTONS_H
#define TWINBUTTONS_H

#include "Graphics\CustomButton.h"

class TwinButtons : public QObject
{
    Q_OBJECT
public:
    TwinButtons();
    CustomButton *right;
    CustomButton *left;
    void unlock();
    void lock();

public slots:
    void analyze_correct();
    void analyze_incorrect();
signals:
    void result(int);
};

#endif // TWINBUTTONS_H
