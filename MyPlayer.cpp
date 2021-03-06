#include "MyPlayer.h"

using std::to_string;


/*!
   Конструктор плеера
   \param n Номер песни
*/
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


/*!
   Инвертор состояния проигрывания музыки
*/
void MyPlayer::play_change(){
    if(isPlaying) player->pause();
    else player->play();
    isPlaying=!isPlaying;
}


/*!
   Вызывает одноимённый метод класса QWidget у переключателя плеера
   \param a X-координата
   \param b Y-координата
*/
void MyPlayer::setPos(int a, int b){
    lever->setPos(a,b);
}


/*!
   Устанавливает проигрываемый трек и внешний вид переключателя.
   \param song Номер трека
   \param icon Номер спрайта переключателя
*/
void MyPlayer::init(short song, short icon){
    player->pause();
    if(song!=songNumber){
      songNumber=song;
      playlist->clear();
      playlist->addMedia(QUrl(QString::fromStdString("qrc:/mus/Mus/Track"+to_string(songNumber)+".mp3")));
    }
    if(isPlaying) player->play();
    lever = new SwitchingButton(icon, isPlaying,4);
    QObject::connect(lever,SIGNAL(enable()),this,SLOT(play_change()));
    QObject::connect(lever,SIGNAL(disable()),this,SLOT(play_change()));
}


/*!
   Возвращает номер играющего трека
*/
char MyPlayer::getPlaying(){
    if(isPlaying) return songNumber+1;
    return 0;
}
