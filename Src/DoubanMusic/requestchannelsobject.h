#ifndef REQUESCHANNELSOBJECT_H
#define REQUESCHANNELSOBJECT_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QStringList>

class RequestChannelsObject : public QObject
{
    Q_OBJECT
public:
    explicit RequestChannelsObject(QObject *parent = 0);

private:
    QNetworkAccessManager* mNetworkManage;
    QStringList mNameList,mIdList;

private slots:
    void FinishedReply(QNetworkReply* reply);

public:
    void SendRequest();
    QStringList GetChannelsName();
    QStringList GetChannelsId();

signals:
    void sendchannellist(QStringList Name,QStringList id);
};

#endif // REQUESCHANNELSOBJECT_H
