//
// Created by nolan on 2021-11-27.
//

#ifndef MAGIC_MIRROR_CALENDARWIDGET_H
#define MAGIC_MIRROR_CALENDARWIDGET_H

#include <QWidget>
#include <QCalendarWidget>
#include <QVBoxLayout>

class CalendarWidget : public QWidget{
    Q_OBJECT

public:
    CalendarWidget();
    ~CalendarWidget();

private:
    QCalendarWidget *calendarWidget;
    QVBoxLayout *vbox;
};


#endif //MAGIC_MIRROR_CALENDARWIDGET_H
