/*
 * @brief This class is responsible for calling the weather API, parsing it and storing the resulting values
 * and making them easily accessible via getter methods.
 *
 * @authors Nathan Dinatale, Nolan Morris.
 * */
#include <iostream>
#include "getWeather.h"

/*
 * @brief Constructor for the class. Receives a Qwidget parent.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nathan Dinatale.
 * */
getWeather::getWeather(QWidget *parent)
{
    celsius = true; //by default, returns temp in celsius
}
/*
 * @brief this function fetches the current weather using a provided API key and city, and updates the object's
 * internal values given the result. Upon successful API call, the parseWeather() function is called.
 *
 * @param APIkey for openweather.org
 * @param city for which to make the call
 *
 * @return No return.
 *
 * @authors Nathan Dinatale.
 * */
void getWeather::fetchWeather(QString APIkey, QString city)
{
    // Creating a network access manager to send a request using the given url
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkRequest request;
    QString url = "https://api.openweathermap.org/data/2.5/weather?q=";
    url.append(city);
    url.append("&appid=");
    url.append(APIkey);
    QUrl qurl = QUrl(url);
    request.setUrl(qurl);

    // Storing the reply from the network request, and upon its completion, parsing it in the parseWeather slot
    QNetworkReply *reply = manager->get(request);
    QEventLoop loop; //forces to execute the parseWeather method before completing
    connect(reply, SIGNAL(finished()), this, SLOT(parseWeather()));
    connect(reply,&QNetworkReply::readyRead,&loop,&QEventLoop::quit);
    loop.exec();
}
/*
 * @brief this function fetches the 5 day forecast using a provided API key and city, and updates the object's
 * internal values given the result. Upon successful API call, the parseWeather() function is called.
 *
 * @param APIkey for openweather.org
 * @param city for which to make the call
 *
 * @return No return.
 *
 * @authors Nathan Dinatale.
 * */
void getWeather::fetchForecast(QString APIkey, QString city)
{
    // Creating a network access manager to send a request using the given url
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkRequest request;
    QString url = "https://api.openweathermap.org/data/2.5/forecast?q=";
    url.append(city);
    url.append("&appid=");
    url.append(APIkey);
    QUrl qurl(url);
    request.setUrl(qurl);

    // Storing the reply from the network request, and upon its completion, parsing it in the parseForecast slot
    QNetworkReply *reply = manager->get(request);
    QEventLoop loop;
    connect(reply,SIGNAL(finished()),this,SLOT(parseForecast()));
    connect(reply,&QNetworkReply::readyRead,&loop,&QEventLoop::quit);
    loop.exec();
}
/*
 * @brief This slot is called to parse the raw JSON that would have been received by the Network Access Manager
 * in the fetchWeather method
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nathan Dinatale.
 * */
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

    // Double-checking that the conversion to QJson was successful
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
/*
 * @brief This slot is called to parse the raw JSON that would have been received by the Network Access Manager
 * in the fetchForecast method
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nathan Dinatale.
 * */

void getWeather::parseForecast() {

    QNetworkReply* reply = qobject_cast<QNetworkReply*> (QObject::sender());
    // Stop the execution in case there is an error
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error downloading. " << reply->errorString();
        return;
    }
    QByteArray data = reply->readAll();
    QJsonDocument forecastDoc = QJsonDocument::fromJson(data);

    // Double-checking that the conversion to QJson was successful
    if(forecastDoc.isNull())
        qDebug() << "Error converting to QJsonDocument";

    // extracting the Json object from the document
    QJsonObject forecastObj = forecastDoc.object();

    // getting the arrays that will contain the temperatures and descriptions
    QJsonArray forecastList = forecastObj["list"].toArray();
    QJsonArray descriptionArray = forecastList.at(0)["weather"].toArray();

    // declaring the necessary values that will be used for parsing the values
    QJsonObject forecastTempObject;
    QJsonValue mainForecast;
    QJsonValue descriptionValue;
    QJsonObject descriptionObject;

    // declaring variables for getting the min/max temps
    double forecastMinTemp;
    double forecastMaxTemp;
    double currentMinTemp;
    double currentMaxTemp;


    // initializing the initial variables for the first forecast object.
    forecastTempObject = forecastList.at(0).toObject();
    mainForecast = forecastTempObject["main"];
    forecastMinTemp = mainForecast["temp_min"].toDouble();
    forecastMaxTemp = mainForecast["temp_max"].toDouble();

    // the API returns 40 instances of forecasts, this loop iterates over them
    for(int i = 0; i < 40; i ++){
        // initializing the current forecast info
        forecastTempObject = forecastList.at(i).toObject();
        mainForecast = forecastTempObject["main"];

        // grabbing the max/mins stored in this forecast
        currentMinTemp = mainForecast["temp_min"].toDouble();
        currentMaxTemp = mainForecast["temp_max"].toDouble();

        // intervals of 8 correspond to each 24 hour period of time
        if((i+1) % 8 == 0){
            // Storing the max/mins of the forecast
            forecastTempMinResults.append(round(forecastMinTemp-273.15));
            forecastTempMaxResults.append(round(forecastMaxTemp - 273.15));

            // Storing the description at the midpoint
            descriptionArray = forecastList.at(i-4)["weather"].toArray();
            descriptionObject = descriptionArray.at(0).toObject();
            forecastDescriptionResult.append(descriptionObject["main"].toString());

            // Resetting the min/maxes
            forecastMinTemp = currentMinTemp;
            forecastMaxTemp = currentMaxTemp;
        }
        if(currentMinTemp < forecastMinTemp)
            forecastMinTemp = currentMinTemp;

        if(currentMaxTemp > forecastMaxTemp)
            forecastMaxTemp = currentMaxTemp;

    }
    /* can be used for debugging purposes
    qDebug() << forecastTempMinResults;
    qDebug() << forecastTempMaxResults;
    qDebug() << forecastDescriptionResult;
     */

}
/*
 * @brief Getter method for the current temperature in celsius
 *
 * @param No parameters.
 *
 * @return tempResult celsius.
 *
 * @authors Nolan Morris
 * */
double getWeather::getTemperature(){
    return round(tempResult - 273.15); //converts temp to celsius
}
/*
 * @brief Getter method for the current weather description
 *
 * @param No parameters.
 *
 * @return weatherResult
 *
 * @authors Nathan Dinatale
 * */
QString getWeather::getWeatherDescription(){
    return weatherResult;
}
/*
 * @brief Getter method for the forecast daily minimum temperatures
 *
 * @param No parameters.
 *
 * @return forecastTempMinResults vector
 *
 * @authors Nathan Dinatale
 * */
QVector<double> getWeather::getForecastTempMins(){
    return forecastTempMinResults;
}
/*
 * @brief Getter method for the forecast daily maximum temperatures
 *
 * @param No parameters.
 *
 * @return forecastTempMaxResults vector
 *
 * @authors Nathan Dinatale
 * */
QVector<double> getWeather::getForecastTempMaxes(){
    return forecastTempMaxResults;
}
/*
 * @brief Getter method for the forecast daily descriptions
 *
 * @param No parameters.
 *
 * @return forecastDescriptionResult vector
 *
 * @authors Nathan Dinatale
 * */
QVector<QString> getWeather::getForecastDescriptions(){
    return forecastDescriptionResult;
}
/*
 * @brief Helper method for converting weather units between farenheit, celsius
 *
 * @param temp the temperature to convert
 *
 * @return temperature in either celsius or farenheit.
 *
 * @authors Nolan Morris
 * */
QString getWeather::convert(QString temp) {
    QStringList pieces = temp.split(" ");
    temp = pieces.value(0);
    QString ret;

    if(celsius){ //if the temp is in celsius, convert to fahrenheit
        double result = (temp.toInt() * (9.0/5.0)) + 32.0;
        result = round(result);
        std::cout << result << std::endl;
        ret = QString::number(result);
        celsius = false;
        return ret + " F";
    }
    else{ //if the temp is in fahrenheit, convert to celsius
        double result = (temp.toDouble() - 32.0) * (5.0/9.0);
        result = round(result);
        std::cout << result << std::endl;
        ret = QString::number(result);
        celsius = true;
        return ret + " C";
    }
}

