#include "requestchannelsobject.h"
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QScriptEngine>
#include <QScriptValueIterator>
#include <QDebug>

RequestChannelsObject::RequestChannelsObject(QObject *parent) :
    QObject(parent),
    mNetworkManage(new QNetworkAccessManager)
{
    QObject::connect(mNetworkManage,SIGNAL(finished(QNetworkReply*)),this,SLOT(FinishedReply(QNetworkReply*)));
}

void RequestChannelsObject::FinishedReply(QNetworkReply *reply)
{
    mNameList.clear();
    mIdList.clear();

    if(reply->error() == QNetworkReply::NoError){
        QByteArray readBytes = reply->readAll();
        QString strDatas = "value="+QString::fromUtf8(readBytes);
        QScriptEngine qsEngine;
        QScriptValue qsValue = qsEngine.evaluate(strDatas);
        if(qsValue.property("channels").isArray()){
            QScriptValueIterator qsit(qsValue.property("channels"));
            while(qsit.hasNext()){
                qsit.next();
                if(!qsit.value().property("channel_id").toString().isEmpty()){
                    mIdList.push_back(qsit.value().property("channel_id").toString());
                }
                if(!qsit.value().property("name").toString().isEmpty()){
                    mNameList.push_back(qsit.value().property("name").toString());
                }
            }
        }
        emit sendchannellist(mNameList,mIdList);
    }
    else{
        mNetworkManage->get(QNetworkRequest(QUrl("http://www.douban.com/j/app/radio/channels")));
    }
}

void RequestChannelsObject::SendRequest()
{
    mNetworkManage->get(QNetworkRequest(QUrl("http://www.douban.com/j/app/radio/channels")));
}

QStringList RequestChannelsObject::GetChannelsName()
{
    return mNameList;
}

QStringList RequestChannelsObject::GetChannelsId()
{
    return mIdList;
}
