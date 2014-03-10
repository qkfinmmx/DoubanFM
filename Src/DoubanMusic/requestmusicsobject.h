#ifndef REQUESTMUSICSOBJECT_H
#define REQUESTMUSICSOBJECT_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QVector>
#include <qmap.h>

typedef QMap<QString,QString> InfMap;

class RequestMusicsObject : public QObject
{
    Q_OBJECT
public:
    explicit RequestMusicsObject(QObject *parent = 0);

private:
    QNetworkAccessManager* mNetworkManage;
    QString mChannelId;
    QVector<InfMap> mInfVector;

private:
    QString BuildRequestUrl_NewList(QString ChannlId);
    QString BuildRequestUrl_NextList(QString ChannelId,QString sid);

private slots:
    void FinishedReply(QNetworkReply* reply);

signals:
    void sendmusiclist(QVector<InfMap> musiclistMap);

public:
    void SendRequest_NewList(QString ChannelId);
    void SendRequest_NextList(QString Sid);
};

#endif // REQUESTMUSICSOBJECT_H
