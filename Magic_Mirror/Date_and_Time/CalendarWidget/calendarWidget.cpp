//
// calendarWidget.cpp
//
// Author: Yifei Zhang
//
// Last update on: 2021/11/07
//

#include <QDate>
#include <string>
#include <iostream>
#include "calendarWidget.h"

using namespace std;
using namespace calendar;
using namespace event;

int calendarWidget::currentId = 1;

// Constructor. 600:300 is probably the best for this calendar widget since QCalendarWidget has fixed size
calendarWidget::calendarWidget(QWidget *parent) : QWidget(parent)
{
	createCalendarBox();
	createInformationBox();

<<<<<<< HEAD
    addEvent = new AddEvent();
=======
>>>>>>> a017f19a296b9f840446b1f4066b6a43d4fec8f3
	QGridLayout *layout = new QGridLayout;
	layout->addWidget(calendarGroupBox, 0, 0);
	layout->addWidget(informationGroupBox, 0, 1);
	setLayout(layout);

	resize(650, 300);

	setWindowTitle(tr("Calendar Widget"));
}

// Create the QGroupBox that contains the calendar and a way to change the date, the Calendar is also clickable.
void calendarWidget::createCalendarBox()
{
	eventMap = new QMap<QDate, QVector<Event>>();
	calendarGroupBox = new QGroupBox(tr("Calendar"));

	calendar = new QCalendarWidget;
	calendar->setMinimumDate(QDate(1900, 1, 1));
	calendar->setMaximumDate(QDate(3000, 1, 1));
	calendar->setGridVisible(true);

	dateSelection = new QDateEdit();
	dateSelection->setDisplayFormat("yyyy MMM dd");
	dateSelection->setDateRange(calendar->minimumDate(), calendar->maximumDate());
	dateSelection->setDate(QDate::currentDate());

	currentDateLabel = new QLabel(tr("&Current Date: "));
	currentDateLabel->setBuddy(dateSelection);

	calendarLayout = new QGridLayout;
	calendarLayout->addWidget(currentDateLabel, 0, 0, Qt::AlignLeft);
	calendarLayout->addWidget(dateSelection, 0, 1, Qt::AlignLeft);
	calendarLayout->addWidget(calendar, 1, 0, 10, 10,Qt::AlignCenter);
	calendarGroupBox->setLayout(calendarLayout);

	connect(dateSelection, &QDateEdit::dateChanged, calendar, &QCalendarWidget::setSelectedDate);
	connect(calendar, &QCalendarWidget::selectionChanged, this, &calendarWidget::dateChanged);
}

// Create the QGroupBox that contains the information of the day selected, event display will be implemented later
void calendarWidget::createInformationBox()
{
	informationGroupBox = new QGroupBox(calendar->selectedDate().toString("On ddd, MMM dd yyyy"));

	currentDateInformation = new QTextEdit("Nothing for today");
	currentDateInformation->setReadOnly(true);

<<<<<<< HEAD
    auto *insertEvent = new QPushButton("InsertEvent");

	informationLayout = new QGridLayout;
	informationLayout->addWidget(currentDateInformation, 0, 0, Qt::AlignCenter);
    informationLayout->addWidget(insertEvent, 1, 0, Qt::AlignCenter);
	informationGroupBox->setLayout(informationLayout);
	
	connect(this, &calendarWidget::eventUpdated, this, &calendarWidget::dateChanged);
    connect(insertEvent, SIGNAL(clicked(bool)), this, SLOT(boxClicked()));

}

void calendarWidget::boxClicked() {
    std::cout << "box clicked" << std::endl;
    addEvent->show();
    connect(addEvent, SIGNAL(eventCreated()), this, SLOT(handleEventCreated()));
}

void calendarWidget::handleEventCreated() { //calls the new event method when an event created signal is released
//    insertEvent(*addEvent->getNewEvent());
    std::cout << "Event Created Signal heard and processed" << std::endl;
=======
	informationLayout = new QGridLayout;
	informationLayout->addWidget(currentDateInformation, 0, 0, Qt::AlignCenter);
	informationGroupBox->setLayout(informationLayout);
	
	connect(this, &calendarWidget::eventUpdated, this, &calendarWidget::dateChanged);
>>>>>>> a017f19a296b9f840446b1f4066b6a43d4fec8f3
}

bool calendarWidget::insertEvent(Event &e)
{
	if(eventMap->contains(e.getDate())){
		if(!eventMap->value(e.getDate()).contains(e)){
			QVector<Event> l = eventMap->take(e.getDate());
			e.setId(currentId);
			l.append(e);
			eventMap->insert(e.getDate(), l);
			currentId++;
			emit eventUpdated();
			return true;
		}	
		else return false;
	}
	else{
		QVector<Event> *l = new QVector<Event>();
		e.setId(currentId);
		l->append(e);
		eventMap->insert(e.getDate(), *l);
		currentId++;
		emit eventUpdated();
		return true;
	}
}

bool calendarWidget::deleteEvent(Event &e)
{
	if(eventMap->contains(e.getDate())){
		if(eventMap->value(e.getDate()).contains(e)){
			QVector<Event> l = eventMap->take(e.getDate());
			l.removeOne(e);
			eventMap->insert(e.getDate(), l);
			emit eventUpdated();
			return true;
		}
	}
	return false;	
}	

// Called when the date menu has changed
void calendarWidget::dateChanged()
{
	dateSelection->setDate(calendar->selectedDate());
	informationGroupBox->setTitle(calendar->selectedDate().toString("On ddd, MMM dd yyyy"));

	if(!eventMap->value(calendar->selectedDate()).isEmpty()){
		const QVector<Event> &l = eventMap->value(calendar->selectedDate());
		currentDateInformation->clear();
		for(int i = 0; i < l.length(); i++){
		const Event &e = l.at(i);
			QString s = QString("Event ") + QString::number(i+1) + "\n";
			s += QString("Event type: ") + e.getType() + "\n";
			s += QString("Event time: ") + e.getDate().toString(QString("yyyy/MM/dd  ")) + e.getTime().toString(QString("HH:mm:ss t\n"));
			s += QString("Event message: \n") + e.getMessage();
			s += QString("\n\n");
			currentDateInformation->append(s);
		}
	}
	else{
		currentDateInformation->setPlainText(QString("Nothing for today"));
	}
}
