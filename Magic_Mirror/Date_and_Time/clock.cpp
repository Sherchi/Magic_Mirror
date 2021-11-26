//
// clock.cpp
//
// Author: Yifei Zhang
//
// Last update on: 2021/11/07
//

#include <QByteArray>
#include <QDate>
#include <QTime>
#include "clock.h"

using namespace clk;
using namespace std;

// Default constructor
Clock::Clock(){
	dateTime = QDateTime::currentDateTime();
	timeZone = QTimeZone::systemTimeZone();
}

// Copy constructor
Clock::Clock(string id){
	timeZone = QTimeZone(QByteArray::fromStdString(id));
	dateTime = QDateTime::currentDateTime();
	dateTime = dateTime.toTimeZone(timeZone);
}

// Destructor
Clock::~Clock(){

};

// Returns an int pointer that points to the first element in an integer array of size 6. Which contains {year, month, date, hour, minute, second}
int* Clock::getTime(){
	Clock::update();
	QDate date = dateTime.date();
	QTime time = dateTime.time();
	static int list[6] = {date.year(), date.month(), date.day(), time.hour(), time.minute(), time.second()};
	return list;
}

// Returns a QString representations of the current time, format is changeable.
QString Clock::getStrTime(){
	Clock::update();
	return dateTime.toString(QString::fromStdString("t: hh:mm:ss yyyy/MM/dd ddd"));
}

// Switch the clock's timezone, the parameter is the timezone id found on iana timezone database.Return false if user's system doesn't have the specified timezone.
bool Clock::switchTimeZone(string id){
	if(QTimeZone::isTimeZoneIdAvailable(QByteArray::fromStdString(id))){
		timeZone = QTimeZone(QByteArray::fromStdString(id));
		return true;
	}
	return false;
}

// Update the time with respect to set time zone. Call this every second to get the accurate time.
void Clock::update(){
	dateTime = QDateTime::currentDateTime();
	dateTime = dateTime.toTimeZone(timeZone);
}


