#ifndef DOMEDIAPLAYER_H
#define DOMEDIAPLAYER_H

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "requestmusicsobject.h"

class DoMediaPlayer : public QMediaPlayer
{
    Q_OBJECT
public:
    explicit DoMediaPlayer(QObject *parent = 0);

private:
    QString qsCurrentChannelId;
    QMediaPlaylist* medialist;
    int CurrentPlayIndex;
    RequestMusicsObject* mReMusicObj;
    QVector<InfMap> mMusicInf;

private:
    void startPlaylist();

private slots:
    void Getmusiclistmap(QVector<InfMap> vecMusicMap);
    void slot_mediaStateChanged(QMediaPlayer::State state);

public slots:
    void PlayNextMusic();
    void ChanegeChannel(QString channelid);

public:
    QString GetCurrentMusicTitle();
    QString GetCurrentMusicArtist();
};

#endif // DOMEDIAPLAYER_H
