//
// Created by nolan on 2021-11-29.
//

#ifndef MAGIC_MIRROR_ADDEVENT_H
#define MAGIC_MIRROR_ADDEVENT_H

#include "../CalendarWidget/event.h"

#include <QWidget>
#include <QTime>
#include <QDate>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>

class AddEvent : public QWidget{
    Q_OBJECT

public:
    AddEvent();
    ~AddEvent();
    event::Event* getNewEvent();

private slots:
    void handleButton();

signals:
    void eventCreated();

private:
    QString message;
    QString type;
    QTime *time;
    QDate *date;
    QLineEdit *messageBox;
    QLineEdit *typeBox;
    QLineEdit *timeBox;
    QLineEdit *dateBox;
    QPushButton *create;
    event::Event *newEvent;
};


#endif //MAGIC_MIRROR_ADDEVENT_H
