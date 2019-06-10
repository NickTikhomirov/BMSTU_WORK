#include "MyPlayer.h"

using std::to_string;

MyPlayer::MyPlayer(short n, QGraphicsItem *parent)
{
    par=parent;
    songNumber = n;
    lever = new SwitchingButton(n,parent);
    playlist = new QMediaPlaylist;
    player = new QMediaPlayer;
    player->setPlaylist(playlist);
    playlist->addMedia(QUrl(QString::fromStdString("qrc:/mus/Mus/Track"+to_string(n)+".mp3")));
    isPlaying=false;
    playlist->setPlaybackMode(playlist->Loop);
    QObject::connect(lever,SIGNAL(enable()),this,SLOT(play_change()));
    QObject::connect(lever,SIGNAL(disable()),this,SLOT(play_change()));
}


void MyPlayer::play_change(){
    if(isPlaying) player->pause();
    else player->play();
    isPlaying=!isPlaying;
}


void MyPlayer::setPos(int a, int b){
    lever->setPos(a,b);
}

void MyPlayer::init(short song, short icon){
    if(song!=songNumber){
        songNumber=song;
      playlist->clear();
      playlist->addMedia(QUrl(QString::fromStdString("qrc:/mus/Mus/Track"+to_string(song)+".mp3")));
    }
    isPlaying=false;
    lever = new SwitchingButton(icon,par);
    QObject::connect(lever,SIGNAL(enable()),this,SLOT(play_change()));
    QObject::connect(lever,SIGNAL(disable()),this,SLOT(play_change()));
}
