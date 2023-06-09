#ifndef FIREBASESIGNIN_H
#define FIREBASESIGNIN_H

#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QVariantMap>
#include "user.h"
#include <firebasedbhelper.h>

class FirebaseSignIn : public QObject
{
    Q_OBJECT
public:
    explicit FirebaseSignIn(QObject *parent = nullptr);
    FirebaseSignIn(User *user);
    void signUserIn(QString username, QString password);
    QNetworkReply *networkReply;
    User *user;
    void setUser(User *user) { this->user = user; }
    bool isLogin = false;

public slots:
    void networkReplyResponse();
    void importUserInfo();

private:
    QString localID;
    QString apiKey = "<apiKey>";
    QNetworkAccessManager *networkAccessManager;
    void performPOST(QString &url, QJsonDocument &payload);

signals:
    void finishedImportUserInfo();
};

#endif // FIREBASESIGNIN_H
