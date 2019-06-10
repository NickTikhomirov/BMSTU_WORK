#ifndef MYPLAYER_H
#define MYPLAYER_H
#include "SwitchingButton.h"


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
public slots:
    void play_change();
};

#endif // MYPLAYER_H
