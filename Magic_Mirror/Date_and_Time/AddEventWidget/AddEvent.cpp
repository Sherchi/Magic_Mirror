//
// Created by nolan on 2021-11-29.
//

#include "AddEvent.h"

AddEvent::AddEvent() {
    newEvent = new event::Event();

    auto *vbox = new QVBoxLayout();
    auto *line1Layout = new QHBoxLayout();
    auto *line2Layout = new QHBoxLayout();

    messageBox = new QLineEdit();
    messageBox->setPlaceholderText("Message");
    typeBox = new QLineEdit();
    typeBox->setPlaceholderText("Type of Event");

    line1Layout->setSpacing(10);
    line1Layout->addWidget(messageBox);
    line2Layout->addWidget(typeBox);

    timeBox = new QLineEdit();
    timeBox->setPlaceholderText("hour:min:sec");
    dateBox = new QLineEdit();
    dateBox->setPlaceholderText("yyyy/mm/dd");

    line2Layout->setSpacing(10);
    line2Layout->addWidget(timeBox);
    line2Layout->addWidget(dateBox);

    create = new QPushButton("Add Event");

    vbox->addLayout(line1Layout);
    vbox->addLayout(line2Layout);
    vbox->addWidget(create, Qt::AlignRight);

    connect(create, SIGNAL(released()), this, SLOT(handleButton()));

    this->setLayout(vbox);
}

event::Event* AddEvent::getNewEvent() {
    return newEvent;
}

void AddEvent::handleButton() {
    QStringList timePieces = timeBox->text().split(":");
    if(timePieces.size() == 3) { //ensures the right format is followed
        int hours = timePieces[0].toInt();
        int mins = timePieces[1].toInt();
        int secs = timePieces[2].toInt();
        time = new QTime(hours, mins, secs);
    }else{ //clears the box of the invalid input
        timeBox->clear();
    }

    QStringList datePieces = dateBox->text().split("/");
    if(datePieces.size() == 3){
        int year = datePieces[0].toInt();
        int month = datePieces[1].toInt();
        int day = datePieces[2].toInt();
        date = new QDate(year, month, day);
    }else{
        dateBox->clear();
    }

    if(datePieces.size() == 3 && timePieces.size() == 3){
        message = messageBox->text();
        type = typeBox->text();
        newEvent->setMessage(message);
        newEvent->setType(type);
        newEvent->setTime(*time);
        newEvent->setDate(*date);

        emit eventCreated(); //emits an event created signal

        this->close();
    }

}

AddEvent::~AddEvent() noexcept {
    delete newEvent;
    delete time;
    delete date;
    delete messageBox;
    delete typeBox;
    delete timeBox;
    delete dateBox;
    delete create;
}