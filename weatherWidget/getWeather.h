#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>

namespace Ui {
    class MainWindow;
}

class getWeather : public QObject
{
Q_OBJECT public:
    explicit getWeather(QWidget *parent = nullptr);
public:
    void fetchWeather(QString url);
    double getTemperature();
    QString getWeatherDescription();
private slots:
    void parseWeather();
private:
    double tempResult;
    QString weatherResult;
};
#endif // MAINWINDOW_H
