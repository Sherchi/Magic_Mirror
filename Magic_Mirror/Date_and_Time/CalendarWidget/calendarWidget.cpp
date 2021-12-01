/**
 * calendarWidget.cpp
 *
 * Author: Yifei Zhang
 *
 * Last update on: 2021/11/30
 */

#include <QDate>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "calendarWidget.h"

using namespace std;
using namespace calendar;
using namespace event;

int calendarWidget::currentId = 1;

/**
 * @brief Constructor. 600:300 is probably the best for this calendar widget since QCalendarWidget has fixed size
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 */
calendarWidget::calendarWidget(QWidget *parent, string path) : QWidget(parent)
{
	eventFilePath = path;
	eventList = new QComboBox();
	addEvent = new AddEvent();

	createCalendarBox();
	createInformationBox();

	QGridLayout *layout = new QGridLayout;
	layout->addWidget(calendarGroupBox, 0, 0);
	layout->addWidget(informationGroupBox, 0, 1);
	setLayout(layout);

	resize(650, 300);

	setWindowTitle(tr("Calendar Widget"));

	/// Saves the user events in a file path specified by eventFilePath
	if(!hasRead){
		ifstream infile;
		infile.open(eventFilePath);
		string line;
		while(getline(infile, line)){
			Event e;
			e = Event();
			QDate d;
			QTime t;

			int id = stoi(line);
			e.setId(id);
			currentId = id + 1;

			getline(infile, line);
			stringstream ss(line);
			string num1, num2, num3;

			ss >> num1;
			ss >> num2;
			ss >> num3;
	
			d = QDate(stoi(num1), stoi(num2), stoi(num3));
			e.setDate(d);
	
			ss >> num1;
			ss >> num2;
			ss >> num3;

			t = QTime(stoi(num1), stoi(num2), stoi(num3));
			e.setTime(t);

			QString s;
			getline(infile, line);
			s = QString::fromStdString(line);
			e.setType(s);

			getline(infile, line);
			s = QString::fromStdString(line);
			e.setMessage(s);
			
			insertEvent(e);
		}
		hasRead = true;
	}
}

/**
 * @brief Create the QGroupBox that contains the calendar and a way to change the date, the Calendar is also clickable.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 */
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

/**
 * @brief Create the QGroupBox that contains the information of the day selected
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 */
void calendarWidget::createInformationBox()
{
	informationGroupBox = new QGroupBox(calendar->selectedDate().toString("On ddd, MMM dd yyyy"));

	currentDateInformation = new QTextEdit("Nothing for today");
	currentDateInformation->setReadOnly(true);

	auto *insertEventButton = new QPushButton("InsertEvent");
	auto *deleteEventButton = new QPushButton("DeleteButton");

	if(!eventMap->value(calendar->selectedDate()).isEmpty()){
		const QVector<Event> &l = eventMap->value(calendar->selectedDate());
		for(int i = 0; i < l.length(); i++){
			eventList->addItem(QString("Event ") + QString::number(i+1));
		}
	}
	else{
		eventList->addItem(QString("None"));
	}

	informationLayout = new QGridLayout;
	informationLayout->addWidget(currentDateInformation, 0, 0, Qt::AlignCenter);
	informationLayout->addWidget(insertEventButton, 1, 0, Qt::AlignCenter);
	informationLayout->addWidget(eventList, 2, 0, Qt::AlignLeft);
	informationLayout->addWidget(deleteEventButton, 2, 0, Qt::AlignRight);
	informationGroupBox->setLayout(informationLayout);
	
	connect(this, &calendarWidget::eventUpdated, this, &calendarWidget::dateChanged);
	connect(insertEventButton, SIGNAL(clicked(bool)), this, SLOT(insertClicked()));
	connect(deleteEventButton, SIGNAL(clicked(bool)), this, SLOT(deleteClicked()));
}

/**
 * @brief Called when insert event button is clicked.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 */
void calendarWidget::insertClicked() {
	std::cout << "box clicked" << std::endl;
	addEvent->show();
	connect(addEvent, SIGNAL(eventCreated()), this, SLOT(handleEventCreated()));
}

/**
 * @brief Called when delete event button is clicked.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 */
void calendarWidget::deleteClicked() {
	const QVector<Event> &l = eventMap->value(calendar->selectedDate());
	const Event &e = l.at(eventList->currentIndex());
	QString message = e.getMessage(), type = e.getType();
	QDate d = e.getDate();
	QTime t = e.getTime();
	Event de;
	de = Event(message, type, t, d);
	int id = e.getId();
	de.setId(id);
	eventMap->insert(calendar->selectedDate(), l);
	deleteEvent(de);
}

/**
 * @brief Calls the new event method when an event created signal is released
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 */
void calendarWidget::handleEventCreated() { 
	insertEvent(*addEvent->getNewEvent());
   	std::cout << "Event Created Signal heard and processed" << std::endl;

	//informationLayout->addWidget(currentDateInformation, 0, 0, Qt::AlignCenter);
	
	connect(this, &calendarWidget::eventUpdated, this, &calendarWidget::dateChanged);
}

/**
 * @brief A private method to insert given Event object in the QMap member of this class.
 *
 * @param e The Event object to be inserted
 *
 * @return true if successful, false otherwise
 *
 * @authors Yifei Zhang.
 */
bool calendarWidget::insertEvent(Event &e)
{
	/// Checks if the id already exists.
	ifstream infile;
	infile.open(eventFilePath);
	int id;
	string line;
	bool exist = false;
	while(getline(infile, line)){
		id = stoi(line);
		if(e.getId() == id) exist = true;
		getline(infile, line);
		getline(infile, line);
		getline(infile, line);
	}

	/// Inserting
	QDateTime dt = QDateTime(e.getDate(), e.getTime());
	if(dt >= QDateTime::currentDateTime()){			/// Checks if the time has not passed.
		if(e.getMessage() == "" || e.getType() == ""){	/// Checks for empty content
			return false;
		}

		else if(eventMap->contains(e.getDate())){	/// If QMap already has a QVector in this date.
			if(!eventMap->value(e.getDate()).contains(e)){	/// If the Event object does not exist
				QVector<Event> l = eventMap->take(e.getDate());
				if(e.getId() == 0){
					e.setId(currentId);
				}

				l.append(e);

				eventMap->insert(e.getDate(), l);
				currentId++;
				emit eventUpdated();
				
				if(!exist){		/// Write out event record every time an insertion is made.
					ofstream outfile(eventFilePath, ios::app);
					outfile << e.getId() << endl;
					outfile << e.getDate().toString(QString("yyyy MM dd ")).toStdString() << e.getTime().toString(QString("HH mm ss")).toStdString() << endl;
					outfile << e.getType().toStdString() << endl;
					outfile << e.getMessage().toStdString() << endl;
					outfile.close();
				}
				return true;
			}	
			else return false;
		}
		else{		/// If QMap doesn't have a QVector for this date yet.
			QVector<Event> *l = new QVector<Event>();
			if(e.getId() == 0){
				e.setId(currentId);
			}
			l->append(e);
			eventMap->insert(e.getDate(), *l);
			currentId++;
			
			emit eventUpdated();

			if(!exist){
				ofstream outfile(eventFilePath, ios::app);
				outfile << e.getId() << endl;
				outfile << e.getDate().toString(QString("yyyy MM dd ")).toStdString() << e.getTime().toString(QString("HH mm ss")).toStdString() << endl;
				outfile << e.getType().toStdString() << endl;
				outfile << e.getMessage().toStdString() << endl;
				outfile.close();
			}
			return true;
		}
	}
	else return false;
}

/**
 * @brief A private method to Delete given Event object in the QMap member of this class.
 *
 * @param e The Event object to be deleted
 *
 * @return true if successful, false otherwise
 *
 * @authors Yifei Zhang.
 */
bool calendarWidget::deleteEvent(Event &e)
{
	/// Also removes the event data stored locally;
	ifstream infile;
	ofstream temp;
	infile.open(eventFilePath);
	temp.open(eventFilePath + "_tmp");
	int id;
	string line;
	while(getline(infile, line)){
		id = stoi(line);
		if(e.getId() == id) {
			getline(infile, line);
			getline(infile, line);
			getline(infile, line);
			continue;
		}
		temp << line << endl;
		getline(infile, line);
		temp << line << endl;
		getline(infile, line);
		temp << line << endl;
		getline(infile, line);
		temp << line << endl;
	}

	infile.close();
	temp.close();
	
	const char *p = eventFilePath.c_str();
	remove(p);
	string tmpPath = eventFilePath + "_tmp";
	rename(tmpPath.c_str(), p);

	/// Removes the Event object in QMap
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

/**
 * @brief Called when the date menu has changed
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 */
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
			s += QString("Event ID: ") + QString::number(e.getId()) + "\n";
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

	eventList->clear();
	if(!eventMap->value(calendar->selectedDate()).isEmpty()){
		const QVector<Event> &l = eventMap->value(calendar->selectedDate());
		for(int i = 0; i < l.length(); i++){
			eventList->addItem(QString("Event ") + QString::number(i+1));
		}
	}
	else{
		eventList->addItem(QString("None"));
	}

}
