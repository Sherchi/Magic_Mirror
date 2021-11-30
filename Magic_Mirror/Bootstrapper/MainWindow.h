//
// Created by nolan on 2021-11-03.
//

#ifndef MAGIC_MIRROR_MAINWINDOW_H
#define MAGIC_MIRROR_MAINWINDOW_H

#include "../Webcam/Camera.h"
#include "../Date_and_Time/ClockWidget/ClockWidget.h"
#include "../Date_and_Time/CalendarWidget/calendarWidget.h"
#include "../News/NewsWidget/NewsWidget.h"
#include "../Weather/WeatherWidget/WeatherWidget.h"
#include "../User_System/UserSystemWidget/UserSystemWidget.h"

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
#include <QDate>
#include <QJsonArray>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
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

private slots :
    void updater();
    void configureWeather();
    void configureNews();
    void configureClock();
    void configureCalendar();
    void configureCamera();
    void configureUserSystem();

private :
    int screenWidth;
    int screenHeight;

    NewsWidget *newsWidget;

    UserSystemWidget *userSystemWidget;

    WeatherWidget *weather;

    ClockWidget *clockWidget;
    calendar::calendarWidget *calendarWidget;

    Camera *camera;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGridLayout *gridLayout;
};

#endif //MAGIC_MIRROR_MAINWINDOW_H
