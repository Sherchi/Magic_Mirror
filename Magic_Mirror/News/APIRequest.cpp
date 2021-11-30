//
// Created by darwin on 2021-11-05.
//
#include "APIRequest.h"

/*
 * @brief Constructor for APIRequest Obj
 *
 * Constructor for the API call. Just sets up
 *
 * @param Parent Main Window QObject
 *
 * @return No return.
 *
 * @authors Darwin Liao
 */
APIRequest::APIRequest(QObject *parent){
    QByteArray imgData;


}
/*
 * @brief get Function to Call API
 *
 * Tries to call the request URL location. Converts the Location
 * to a ByteArray, then passes it to a QNetworkRequest.
 * the Reply is then constantly checked to see if it is finished
 * transmitting. If it is, then toggle a flag, and Process the info.
 *
 * In case of Timeout, Built in Timeout that will give Print Error
 *
 * @param QString Location: The URL of the request
 *
 * @return No Return.
 *
 * @author Darwin Liao.
 */
void APIRequest::get(QString location) {
    qInfo()<<"Getting Data from Web...";
    gotInfo = 0;
    QByteArray tempBA;
    tempBA += location;
    QNetworkReply *reply = manager.get(QNetworkRequest(QUrl::fromUserInput(location)));
    QEventLoop loop;
    //connect(reply,&QNetworkReply::finished,this,&APIRequest::managerFinished);
    connect(reply,&QNetworkReply::finished,this,&APIRequest::readyRead);
    connect(reply,&QNetworkReply::readyRead,&loop,&QEventLoop::quit);
    loop.exec();


}
/*
 * @brief Slot to process Information
 *
 * Data retrieved from API is in the form of {articles:{{article info1}{Article info2}}...}
 * as a JsonObject with a JsonArray as it's info. The Inner JsonArray contains the data we want.
 * We create a QJsonDocument from the info provided, Make an JsonArray out of the "Articles" Field
 * then we have the JsonArray of the JsonObjects we need.
 *
 * Set the flag to 1, meaning that the info processing is done, and is available for
 * other parts of the system to use.
 *
 * @param none
 *
 * @return none
 *
 * @author Darwin Liao
 */
void APIRequest::readyRead() {
    //qInfo()<<"ReadyRead";
    QNetworkReply *reply= qobject_cast<QNetworkReply*>(sender());
    if(reply){
        try {
            //qDebug()<<"REPLY IS RECEIVED";
            data = reply->readAll();
            auto doc = QJsonDocument::fromJson(data);
            articleList = doc.object();
            QJsonArray tempArr = articleList["articles"].toArray();
            articleArr = tempArr;

            //qDebug()<<tempArr;
            gotInfo = 1;
            reply->deleteLater();

        }catch(std::exception){
            qDebug()<<"ERROR IN API REQUEST DATA";

        }
    };
}

//The Check if request is finished ...
// Should never be finished unless main program exits since it will be called every X min..
// Is here because in case in future revisions, will be required. But for now does not
// Do anything
// @author Darwin Liao
void APIRequest::managerFinished() {
    ;

}

/*
 * @brief Returns the Article Array that contains all the information
 *
 * @param: None
 *
 * @return Article Array. An Array that has all QJsonObj articles
 *
 * @author: Darwin Liao
 */
QJsonArray APIRequest::getJsonArr() {
    return articleArr;

}
/*
 * @brief Returns the state of the Information processing/Downloading
 *
 * @param none
 *
 * @return boolean gotInfo
 *
 * @author Darwin Liao
 */
int APIRequest::isDone(){
    return gotInfo;
}


