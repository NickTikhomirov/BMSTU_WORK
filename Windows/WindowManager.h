#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <QObject>

#include "Logic\Level.h"
#include "AdditionalWindow.h"
#include "CursorManager.h"


class WindowManager : public QObject
{
    Q_OBJECT
public:
    explicit WindowManager(QObject *parent = nullptr);
    Level *level;
    AdditionalWindow *passport;
    AdditionalWindow *medicine;
    AdditionalWindow *psycho;
    AdditionalWindow *agreement;
    AdditionalWindow *rights;
    AdditionalWindow *tutorial;
    AdditionalWindow *stenography;

    AdditionalWindow *first;
    AdditionalWindow *second;
    void toggleW(char);
    AdditionalWindow *getSpace();
    void dynamic_documents();
    void clear_dynamics();
private:
    void open(AdditionalWindow *);
    void close(AdditionalWindow *);
    void toggle(AdditionalWindow *);



signals:
    void privacyBreak();
    void provide(char,char);
public slots:
    void kill();
    void close1();
    void close2();
    void open_passport();
    void open_x();
    void open_license();
    void open_medicine();
    void open_tutorial();
    void open_agreement();
    void open_stenography();

    void provide_passport(char);
    void provide_x(char);
    void provide_license(char);
    void provide_medicine(char);
    void provide_agreement(char);
};

#endif // WINDOWMANAGER_H
