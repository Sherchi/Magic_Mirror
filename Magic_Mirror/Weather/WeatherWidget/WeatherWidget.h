//
// Created by nolan on 2021-11-27.
//

#ifndef MAGIC_MIRROR_WEATHERWIDGET_H
#define MAGIC_MIRROR_WEATHERWIDGET_H

#include "../getWeather.h"
#include "../../Utils/ClickableLabel.h"

#include <QWidget>
#include <QString>
#include <QPixmap>
#include <QLabel>
#include <QHBoxLayout>

class WeatherWidget : public QWidget{
    Q_OBJECT

public :
    WeatherWidget();
    ~WeatherWidget();

private slots:
    QString parseWeather(QString);
    void changeUnits();

private:
    QHBoxLayout *hbox;
    getWeather *weather;
    QPixmap *image;
    QLabel *imageLabel;
    ClickableLabel *temp;
};


#endif //MAGIC_MIRROR_WEATHERWIDGET_H
