#include <QApplication>

#include <ctime>


#include "Windows/Game.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(time(0));
    Game *g;
    g = new Game();
    g->show();
    QObject::connect(g,SIGNAL(button_pressed()), &a, SLOT(closeAllWindows()));

    return a.exec();
}
