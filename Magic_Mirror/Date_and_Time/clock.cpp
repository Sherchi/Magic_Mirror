/**
 * calendarWidget.cpp
 *
 * Author: Yifei Zhang
 *
 * Last update on: 2021/11/30
 */

#include <QByteArray>
#include <QDate>
#include <QTime>
#include "clock.h"

using namespace clk;
using namespace std;

/**
 * @brief Default constructor
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 */
Clock::Clock(){
	dateTime = QDateTime::currentDateTime();
	timeZone = QTimeZone::systemTimeZone();
}

/**
 * @brief Constructor that specifies timezone from iana timezone database
 *
 * @param id String id of the time zone
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 */
Clock::Clock(string id){
	timeZone = QTimeZone(QByteArray::fromStdString(id));
	dateTime = QDateTime::currentDateTime();
	dateTime = dateTime.toTimeZone(timeZone);
}

/**
 * @brief Destructor
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 */
Clock::~Clock(){

};

/**
 * @brief Get time in integer format
 *
 * @param No parameters.
 *
 * @return an int pointer that points to the first element in an integer array of size 6. Which contains {year, month, date, hour, minute, second}
 *
 * @authors Yifei Zhang.
 */
int* Clock::getTime(){
	Clock::update();
	QDate date = dateTime.date();
	QTime time = dateTime.time();
	static int list[6] = {date.year(), date.month(), date.day(), time.hour(), time.minute(), time.second()};
	return list;
}

/**
 * @brief Get time in string format
 *
 * @param No parameters.
 *
 * @return Returns a QString representations of the current time, format is changeable.
 *
 * @authors Yifei Zhang.
 */
QString Clock::getStrTime(){
	Clock::update();
	return dateTime.toString(QString::fromStdString("t: hh:mm:ss yyyy/MM/dd ddd"));
}

/**
 * @brief Switch the clock's timezone, the parameter is the timezone id found on iana timezone database.Return false if user's system doesn't have the specified timezone.
 *
 * @param id String id of the time zone
 *
 * @return true if successful, false otherwise
 *
 * @authors Yifei Zhang.
 */
bool Clock::switchTimeZone(string id){
	if(QTimeZone::isTimeZoneIdAvailable(QByteArray::fromStdString(id))){
		timeZone = QTimeZone(QByteArray::fromStdString(id));
		return true;
	}
	return false;
}

/**
 * @brief Update the time with respect to set time zone. Call this every second to get the accurate time.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 */
void Clock::update(){
	dateTime = QDateTime::currentDateTime();
	dateTime = dateTime.toTimeZone(timeZone);
}

/**
 * @brief Creates a digital clock widget and return it.
 *
 * @param No parameters.
 *
 * @return The digital clock widget
 *
 * @authors Yifei Zhang.
 */
QWidget* Clock::digitalClock(){
	DigitalClock *digital = new DigitalClock();
	return digital;
}

/**
 * @brief Creates an analog clock widget and return it.
 *
 * @param No parameters.
 *
 * @return The analog clock widget
 *
 * @authors Yifei Zhang.
 */
QWidget* Clock::analogClock(){
	AnalogClock *analog = new AnalogClock();
	return analog;
}
