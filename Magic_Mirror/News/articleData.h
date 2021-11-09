//
// Created by darwin on 2021-11-06.
//

#ifndef NEWSPROJECT_ARTICLEDATA_H
#define NEWSPROJECT_ARTICLEDATA_H

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QVector>
#include <QString>

//A Class that holds the information of an article,
// Made for easier access of articles.
class articleData{
private:
    QJsonObject  rawData;
    QString title;
    QString desc;
    QString content;
    QString url;
    QString img;

public:
    articleData();
    articleData(QJsonObject data);
    QString getTitle();
    QString  getDesc();
    QString  getContent();
    QString  getURL();
    QString  getImage();

};

#endif //NEWSPROJECT_ARTICLEDATA_H
