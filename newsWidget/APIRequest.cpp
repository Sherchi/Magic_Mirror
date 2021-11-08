//
// Created by darwin on 2021-11-05.
//
#include "APIRequest.h"
#include "unistd.h"

//Init
APIRequest::APIRequest(QObject *parent){
    QByteArray data;
    QJsonObject articleList;


}
//Sends a Get request to the Location specified
void APIRequest::get(QString location) {
    qInfo()<<"Getting Data from Web...";
    QNetworkReply *reply = manager.get(QNetworkRequest(QUrl(location)));
    QEventLoop loop;
    connect(reply,&QNetworkReply::finished,this,&APIRequest::managerFinished);
    connect(reply,&QNetworkReply::readyRead,this,&APIRequest::readyRead);
    connect(reply,&QNetworkReply::readyRead,&loop,&QEventLoop::quit);
    loop.exec();


}

//If it's ready, then give me the reply
//      And then format the info into an array.
//  Strips away unneccesary Data (Total amount of articles in world, etc.)
void APIRequest::readyRead() {
    qInfo()<<"ReadyRead";
    QNetworkReply *reply= qobject_cast<QNetworkReply*>(sender());
    if(reply){
        qDebug()<<"REPLY IS RECEIVED";
        data = reply->readAll();
        auto doc = QJsonDocument::fromJson(data);
        articleList = doc.object();
        QJsonArray tempArr = articleList["articles"].toArray();
        articleArr = tempArr;
        //qDebug()<<tempArr;

    };
}

//The Check if request is finished
void APIRequest::managerFinished() {
    ;

}

//Returns the Array of Articles
QJsonArray APIRequest::getJsonArr() {
    return articleArr;

}


