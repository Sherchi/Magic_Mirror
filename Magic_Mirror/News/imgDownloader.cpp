//
// Created by darwin on 2021-11-26.
//

#include "imgDownloader.h"
/**
 * @breif constructor of the ImgDownloader
 * @paragraph Makes an object that makes a connection using
 *          QNetworkManager and QNetworkRequest/Reply
 *
 * @param parent
 *
 * @Author: Darwin Liao
 */
imgDownloader::imgDownloader(QObject *parent) {
    QByteArray imgData;
    QPixmap pixMap;
}
/**
 * @brief Download Method. Takes in URL tries to download an image from the URL
 *
 * @paragraph Turns the location param into a QByteArray so that
 *      The URL is processed properly. Then Tries to make a connection and retrive the
 *      Image from the given URL. Once the ENTIRE image/page is recieved, then we
 *      can go onto putting it into a pixmap for usage.
 *
 * @param location
 *
 * @return none
 *
 * @author Darwin Liao
 */
void imgDownloader::download(QString location) {
    QByteArray tempBA;
    tempBA += location;
    QNetworkReply *imgReply = manager.get(QNetworkRequest(QUrl::fromUserInput(location)));
    QEventLoop loop;
    connect(imgReply, &QNetworkReply::finished,this,&imgDownloader::managerFinished);
    connect(imgReply, &QNetworkReply::finished,&loop,&QEventLoop::quit);
    loop.exec();

}
/**
 * @brief Slot that is called when the QNetworkReply is Finished
 * @paragraph Once the Network Reply is finish, and we get all the information
 *          of the image, we can now put the data into a pixmap
 *
 * @param none
 * @return none
 * @Author Darwin Liao
 */
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

/**
 * @Breif Returns the pixmap
 * @return pixmap
 * author Darwin Liao
 */
QPixmap imgDownloader::getPixmap() {
    return pixMap;
}