//
// Created by darwin on 2021-11-05.
//
#include "APIRequest.h"
#include "articleData.h"
#include <QApplication>


int main(int argc, char  *argv[]){
    QApplication app(argc, argv);
    //List of Articles.
    QVector<articleData> dataList;

    //Makes APIRequest obj.
    APIRequest api;
    //API Token is: 9aadf377ffbec1aa1d09e593b43262c5
    //Only 100 Requests a Day, so don't test with it too much.
    //Documentation of the API is here--> https://gnews.io/docs/v4?javascript#search-endpoint
    //  If you want to make a new account, and use it's API token, then feel free.
    //  Just replace the token= with yours.
    api.get("https://gnews.io/api/v4/top-headlines?&lang=en&country=ca&max=10&token=9aadf377ffbec1aa1d09e593b43262c5");

    //Requests the JSonArray of the Article JsonObjs
    QJsonArray tempArr = api.getJsonArr();

    //Makes articleData Object with the Above Info.
    //Allows for easier Access of the Info with .getTitle() etc.
    for(int i = 0; i < 10; i++){
        articleData article(tempArr[i].toObject());
        dataList.append(article);
    }


    //Prints stuff out.
    for(int i = 0; i < dataList.length(); i++){
        qDebug()<<"TITLE: " << dataList[i].getTitle();

    }

    return app.exec();
}