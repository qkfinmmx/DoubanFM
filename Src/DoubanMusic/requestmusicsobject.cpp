#include "requestmusicsobject.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QScriptEngine>
#include <QScriptValue>
#include <QScriptValueIterator>
#include <QDebug>

RequestMusicsObject::RequestMusicsObject(QObject *parent) :
    QObject(parent),
    mNetworkManage(new QNetworkAccessManager)
{
    QObject::connect(mNetworkManage,SIGNAL(finished(QNetworkReply*)),this,SLOT(FinishedReply(QNetworkReply*)));
}

QString RequestMusicsObject::BuildRequestUrl_NewList(QString ChannlId)
{
    QString tUrlstr;
    tUrlstr = "http://www.douban.com/j/app/radio/people?app_name=radio_desktop_win&version=100&type=n&channel=$channel$";
    tUrlstr = tUrlstr.replace("$channel$",ChannlId);
    return tUrlstr;
}

QString RequestMusicsObject::BuildRequestUrl_NextList(QString ChannelId, QString sid)
{
    QString tUrlstr;
    tUrlstr = "http://www.douban.com/j/app/radio/people?app_name=radio_desktop_win&version=100&sid=$sidNum$&channel=$channel$&type=s";
    tUrlstr = tUrlstr.replace("$channel$",ChannelId);
    tUrlstr = tUrlstr.replace("$sidNum$",sid);
    return tUrlstr;
}

void RequestMusicsObject::FinishedReply(QNetworkReply *reply)
{
    mInfVector.clear();

    if(reply->error() == QNetworkReply::NoError){
        QByteArray readBytes = reply->readAll();
        QString strData = "value=" + QString::fromUtf8(readBytes);
        QScriptEngine qsEngine;
        QScriptValue qsValue = qsEngine.evaluate(strData);
        if(qsValue.property("song").isArray()){
            QScriptValueIterator qsit(qsValue.property("song"));
            while(qsit.hasNext()){
                qsit.next();
                InfMap tMap;
                if(!qsit.value().property("picture").toString().isEmpty()){
                    tMap.insert("picture",qsit.value().property("picture").toString());
                }
                if(!qsit.value().property("artist").toString().isEmpty()){
                    tMap.insert("artist",qsit.value().property("artist").toString());
                }
                if(!qsit.value().property("url").toString().isEmpty()){
                    tMap.insert("url",qsit.value().property("url").toString());
                }
                if(!qsit.value().property("company").toString().isEmpty()){
                    tMap.insert("company",qsit.value().property("company").toString());
                }
                if(!qsit.value().property("title").toString().isEmpty()){
                    tMap.insert("title",qsit.value().property("title").toString());
                }
                if(!qsit.value().property("length").toString().isEmpty()){
                    tMap.insert("length",qsit.value().property("length").toString());
                }
                if(!qsit.value().property("kbps").toString().isEmpty()){
                    tMap.insert("kbps",qsit.value().property("kbps").toString());
                }
                if(!qsit.value().property("sid").toString().isEmpty()){
                    tMap.insert("sid",qsit.value().property("sid").toString());
                }
                mInfVector.push_back(tMap);
            }
            if(!mInfVector.isEmpty()){
                mInfVector.removeLast();
            }
            emit sendmusiclist(mInfVector);
        }
    }else{
        mNetworkManage->get(QNetworkRequest(QUrl(BuildRequestUrl_NewList(mChannelId))));
    }
}

void RequestMusicsObject::SendRequest_NewList(QString ChannelId)
{
    mChannelId = ChannelId;
    mNetworkManage->get(QNetworkRequest(QUrl(BuildRequestUrl_NewList(ChannelId))));
}

void RequestMusicsObject::SendRequest_NextList(QString Sid)
{
    mNetworkManage->get(QNetworkRequest(QUrl(BuildRequestUrl_NextList(mChannelId,Sid))));
}
