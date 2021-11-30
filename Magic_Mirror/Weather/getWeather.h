#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <cmath>

#include <QObject>
#include <QMainWindow>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QEventLoop>

//namespace Ui {
//    class MainWindow;
//}

class getWeather : public QObject
{
Q_OBJECT public:
    explicit getWeather(QWidget *parent = nullptr);

public:
    void fetchWeather(QString url, QString city);
    void fetchForecast(QString url, QString city);
    double getTemperature();
    QString getWeatherDescription();
    QString convert(QString);
    QVector<double> getForecastTempMins();
    QVector<double> getForecastTempMaxes();
    QVector<QString> getForecastDescriptions();

private slots:
    void parseWeather();
    void parseForecast();

private:
    bool celsius;
    double tempResult;
    QString weatherResult;
    QVector<QString> forecastDescriptionResult;
    QVector<double> forecastTempMinResults;
    QVector<double> forecastTempMaxResults;
};
#endif // MAINWINDOW_H
