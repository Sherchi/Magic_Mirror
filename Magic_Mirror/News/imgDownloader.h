//
// Created by darwin on 2021-11-26.
//

#ifndef NEWSPROJECT_IMGDOWNLOADER_H
#define NEWSPROJECT_IMGDOWNLOADER_H
//Include
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QAuthenticator>
#include <QFile>
#include <QPixmap>
#include <QIODevice>
#include <QEventLoop>

class imgDownloader: public QObject {
Q_OBJECT public:
    explicit imgDownloader(QObject *parent = nullptr);

private slots:
    void managerFinished();


//Network Manager, The data from request, and some
// Json stuff to temperarily hold some values
private:
    QNetworkAccessManager manager;
    QByteArray imgData;
    QPixmap pixMap;
    // ok This should be a private slot, but it wasn't working
    //and doesn't do much so I left it here. Might need later

//Public Access to Asking for a request and
//getting the jsonarray
public:
    QPixmap getPixmap();
    void download(QString location);


};


#endif //NEWSPROJECT_IMGDOWNLOADER_H
