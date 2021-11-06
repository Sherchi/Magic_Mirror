//
// Created by darwin on 2021-11-05.
//

#ifndef NEWSPROJECT_APIREQUEST_H
#define NEWSPROJECT_APIREQUEST_H
//Include
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QAuthenticator>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QEventLoop>


//Obj init
class APIRequest: public QObject{
Q_OBJECT public:
    explicit APIRequest(QObject *parent = nullptr);

//ReadyRead Slot to know when data is retrieved and
// ready to be read.
private slots:
    void readyRead();

//Network Manager, The data from request, and some
// Json stuff to temperarily hold some values
private:
    QNetworkAccessManager manager;
    QByteArray data;
    QJsonObject articleList;
    QJsonArray articleArr;

    // ok This should be a private slot, but it wasn't working
    //and doesn't do much so I left it here. Might need later
public slots:
    void managerFinished();

//Public Access to Asking for a request and
//getting the jsonarray
public:
    QJsonArray getJsonArr();
    void get(QString location);


};


#endif //NEWSPROJECT_APIREQUEST_H
