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
    void fetchWeather(QString url);
    double getTemperature();
    QString getWeatherDescription();
    QString convert(QString);

private slots:
    void parseWeather();

private:
    bool celsius;
    double tempResult;
    QString weatherResult;
};
#endif // MAINWINDOW_H
