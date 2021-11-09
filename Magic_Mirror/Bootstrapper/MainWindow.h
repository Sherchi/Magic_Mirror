//
// Created by nolan on 2021-11-03.
//

#ifndef MAGIC_MIRROR_MAINWINDOW_H
#define MAGIC_MIRROR_MAINWINDOW_H

#include "../News/APIRequest.h"
#include "../News/articleData.h"
#include "../Weather/getWeather.h"

#include <QGridLayout>
#include <QHBoxLayout>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QString>
#include <QLabel>
#include <QFont>
#include <QVector>
#include <QTimer>
#include <QCalendarWidget>
#include <QDate>
#include <QJsonArray>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class MainWindow : public QMainWindow{
Q_OBJECT

public : explicit MainWindow(QWidget *parent = nullptr);

public :
    ~MainWindow();
    void configure();
    QGridLayout* getLayout();
    void start();

private slots :
    void updater();
    void configureWeather();
    void updateWeather();
    QString parseWeather(QString);
    void configureNews();
    void scrollNews();
    void updateNews();
    void configureClock();
    void showTime();
    void configureCalendar();
    void updateCalendar();

private :
    QVector<articleData> headlines;
    int storiesIndex;
    APIRequest *newsApi;
    getWeather *weather;
    QGridLayout *gridLayout;
};

#endif //MAGIC_MIRROR_MAINWINDOW_H
