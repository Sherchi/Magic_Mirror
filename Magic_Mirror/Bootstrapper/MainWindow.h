//
// Created by nolan on 2021-11-03.
//

#ifndef MAGIC_MIRROR_MAINWINDOW_H
#define MAGIC_MIRROR_MAINWINDOW_H

#include "../News/APIRequest.h"
#include "../News/articleData.h"
#include "../Weather/getWeather.h"
#include "../Webcam/Camera.h"
#include "../Date_and_Time/clock.h"

#include <iostream>
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
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsProxyWidget>

namespace Ui{
    class MainWindow;
}

class MainWindow : public QMainWindow{
Q_OBJECT

public : explicit MainWindow(int screenWidth, int screenHeight, QWidget *parent = 0);

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
    void configureCamera();

private :
    int screenWidth;
    int screenHeight;
    QVector<articleData> headlines;
    int storiesIndex;
    QLabel *newsLabel;
    APIRequest *newsApi;
    getWeather *weather;
    clk::Clock *clock;
    QLabel *timeLabel;
    Camera *camera;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGridLayout *gridLayout;
};

#endif //MAGIC_MIRROR_MAINWINDOW_H
