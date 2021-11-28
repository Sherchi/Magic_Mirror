//
// Created by darwin on 2021-11-26.
//

#include "imgDownloader.h"

imgDownloader::imgDownloader(QObject *parent) {
    QByteArray imgData;
    QPixmap pixMap;
}

void imgDownloader::download(QString location) {
    QByteArray tempBA;
    tempBA += location;
    QNetworkReply *imgReply = manager.get(QNetworkRequest(QUrl::fromUserInput(location)));
    QEventLoop loop;
    connect(imgReply, &QNetworkReply::finished,this,&imgDownloader::managerFinished);
    connect(imgReply, &QNetworkReply::finished,&loop,&QEventLoop::quit);
    loop.exec();

}

void imgDownloader::managerFinished() {
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());

    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error downloading. " << reply->errorString();
        return;
    }

    QPixmap pm;
    imgData = reply->readAll();
    pm.loadFromData(imgData);
    pixMap = pm;

    reply->deleteLater();
}

QPixmap imgDownloader::getPixmap() {
    return pixMap;
}