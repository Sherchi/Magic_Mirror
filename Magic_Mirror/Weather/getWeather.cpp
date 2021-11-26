#include <iostream>
#include "getWeather.h"

// Constructor for the getWeather object
getWeather::getWeather(QWidget *parent)
{
}

// This function will fetch the weather from the provided url using an API key from openweather.org
void getWeather::fetchWeather(QString url)
{

    // Creating a network access manager to send a request using the given url
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkRequest request;
    QUrl qurl(url);
    request.setUrl(qurl);

    // Storing the reply from the network request, and upon its completion, parsing it in the parseWeather slot
    QNetworkReply *reply = manager->get(request);

    QEventLoop loop; //forces to execute the parseWeather method before completing
    connect(reply, SIGNAL(finished()), this, SLOT(parseWeather()));
    connect(reply,&QNetworkReply::readyRead,&loop,&QEventLoop::quit);
    loop.exec();
}

//This slot will called to parse the raw JSON that would have been received by the Network Access Manager
void getWeather::parseWeather() {

    QNetworkReply* reply = qobject_cast<QNetworkReply*> (QObject::sender());

    // Stop the execution in case there is an error
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error downloading. " << reply->errorString();
        return;
    }

    // Storing all the information in the reply, at this point in the form of raw JSON, into a QByte Array
    // then turning that into a QJson Document
    QByteArray data = reply->readAll();
    QJsonDocument weatherDoc = QJsonDocument::fromJson(data);

    // Double checking that the converstion to QJson was successful
    if(weatherDoc.isNull())
        qDebug() << "Error converting to QJsonDocument";

    // Since the whole of the JSON document is in the Object form, an object is created for the document from which
    // certain parts will be extracted
    QJsonObject weatherObj = weatherDoc.object();

    // Extracting just the "main" and "weather" objects from the overall JSon Document.
    QJsonArray descriptionArray = weatherObj["weather"].toArray();
    QJsonObject descriptionObject = descriptionArray.at(0).toObject();
    QJsonObject temperatureObj = weatherObj["main"].toObject();

    // Parsing the value of temperature and the main weather description using their respective keys
    QJsonValue temp = temperatureObj["temp"];
    QJsonValue mainWeather = descriptionObject["main"];

    // Storing the parsed values into the class' local variables of types double and QString.
    tempResult = temp.toDouble();
    weatherResult = mainWeather.toString();

    // this code can be used to see what was parsed for debugging purposes:
    /*
    qDebug() << tempResult;
    qDebug() << weatherResult;
    */


    // Cleaning up the Network Reply.
    reply->deleteLater();

}
double getWeather::getTemperature(){
    return tempResult - 273.15; //converts temp to celsius
}

QString getWeather::getWeatherDescription(){
    return weatherResult;
}

