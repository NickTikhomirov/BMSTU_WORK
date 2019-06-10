#ifndef ADDITIONALWINDOW_H
#define ADDITIONALWINDOW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QIcon>

#include "Graphics/CustomButton.h"
#include "Graphics/SimpleButton.h"
#include "Graphics/TextButton.h"
#include "Graphics/TutorialPage.h"

#include "Resizer.h"
#include "Generators/Randomizer.h"
#include "Logic/Level.h"

class AdditionalWindow : public QGraphicsView
{
    Q_OBJECT
public:
    char w_type;
    explicit AdditionalWindow(char p, Level *l=0, QWidget *par=0);
    QGraphicsScene *scene;
private:
    void closeEvent(QCloseEvent *event);
signals:
    void closed();
};

#endif // ADDITIONALWINDOW_H
