#include "domediaplayer.h"
#include <QDebug>

DoMediaPlayer::DoMediaPlayer(QObject *parent) :
    QMediaPlayer(parent),
    qsCurrentChannelId("1"),
    medialist(new QMediaPlaylist),
    CurrentPlayIndex(0),
    mReMusicObj(new RequestMusicsObject)
{
    this->setPlaylist(medialist);

    QObject::connect(mReMusicObj,SIGNAL(sendmusiclist(QVector<InfMap>)),this,SLOT(Getmusiclistmap(QVector<InfMap>)));
    QObject::connect(this,SIGNAL(stateChanged(QMediaPlayer::State)),
                     this,SLOT(slot_mediaStateChanged(QMediaPlayer::State)));

    // Init Operator
    this->startPlaylist();
}

void DoMediaPlayer::startPlaylist()
{
    medialist->clear();
    mMusicInf.clear();
    mReMusicObj->SendRequest_NewList(qsCurrentChannelId);
}

void DoMediaPlayer::Getmusiclistmap(QVector<InfMap> vecMusicMap)
{
    foreach (InfMap tMap, vecMusicMap) {
        mMusicInf.push_back(tMap);
    }

    if(medialist->isEmpty()){
        foreach (InfMap tUrlMap, vecMusicMap) {
            medialist->addMedia(QUrl(tUrlMap["url"]));
        }
        medialist->setCurrentIndex(0);
        this->play();
    }else{
        foreach (InfMap tUrlMap, vecMusicMap) {
            medialist->addMedia(QUrl(tUrlMap["url"]));
        }
        medialist->next();
        this->play();
    }
}

void DoMediaPlayer::slot_mediaStateChanged(QMediaPlayer::State state)
{
    switch(state){
    case QMediaPlayer::StoppedState:{
        this->PlayNextMusic();
        break;
    }
    default:
        break;
    }
}

void DoMediaPlayer::PlayNextMusic()
{
    int tNextMediaIndex = medialist->nextIndex();
    if(tNextMediaIndex != -1){
        medialist->next();
        this->play();
    }else{
        mReMusicObj->SendRequest_NextList(mMusicInf.last()["sid"]);
    }
}

void DoMediaPlayer::ChanegeChannel(QString channelid)
{
    qsCurrentChannelId = channelid;
    this->startPlaylist();
}

QString DoMediaPlayer::GetCurrentMusicTitle()
{
    return mMusicInf.at(medialist->currentIndex())["title"];
}

QString DoMediaPlayer::GetCurrentMusicArtist()
{
    return mMusicInf.at(medialist->currentIndex())["artist"];
}
