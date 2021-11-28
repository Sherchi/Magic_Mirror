//
// Created by nolan on 2021-11-27.
//

#ifndef MAGIC_MIRROR_CLOCKWIDGET_H
#define MAGIC_MIRROR_CLOCKWIDGET_H

#include "../clock.h"

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QVBoxLayout>

class ClockWidget : public QWidget{
    Q_OBJECT

public:
    ClockWidget();
    ~ClockWidget();

private slots:
    void showTime();

private:
    QLabel *timeLabel;
    clk::Clock *clock;
    QVBoxLayout *vbox;

};


#endif //MAGIC_MIRROR_CLOCKWIDGET_H
