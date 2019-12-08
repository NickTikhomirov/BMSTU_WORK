#ifndef MYPLAYER_H
#define MYPLAYER_H
#include "Graphics/SwitchingButton.h"


/*!
    \brief Класс с плеером и кнопкой для его переключения.

    Музыка не является неотъемлемой частью игры, поэтому её реализация была в ходе разработки категоризирована как "хоть как-нибудь", поэтому был разработан этот класс.
    Это условно простая обёртка над всей системой воспроизведения музыки и контроллирования этого процесса.
*/
class MyPlayer:public QObject
{
    Q_OBJECT
    bool isPlaying;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QGraphicsItem *par;
    char songNumber;
public:
    SwitchingButton *lever;
    void setPos(int,int);
    void init(short,short);
    explicit MyPlayer(short n, QGraphicsItem *parent = nullptr);
    char getPlaying();
public slots:
    void play_change();
};

#endif // MYPLAYER_H
