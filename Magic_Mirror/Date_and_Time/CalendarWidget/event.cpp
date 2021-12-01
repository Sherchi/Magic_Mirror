/**
 * event.cpp
 *
 * Author: Yifei Zhang
 *
 * Last update on: 2021/11/30
 */

#include "event.h"

using namespace event;

/**
 * @brief Defaule constructor
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 */
Event::Event()
{
	eventId = 0;
	message = new QString();
	type = new QString();
	time = new QTime();
	date = new QDate();
	notified = false;
}

/**
 * @brief Constructor that specifies data
 *
 * @param m The event message
 * @param type The event type
 * @param t The event time
 * @param d The event date
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 */
Event::Event(QString &m, QString &type, QTime &t, QDate &d)
{
	eventId = 0;
	message = new QString(m);
	this->type = new QString(type);
	time = new QTime(t.hour(), t.minute(), t.second(), t.msec());
	date = new QDate(d.year(), d.month(), d.day());
	notified = false;
}

/**
 * @brief Copy constructor
 *
 * @param e The event to copy from
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 */
Event::Event(const Event &e)
{
	message = new QString(e.getMessage());
	type = new QString(e.getType());
	QTime t = e.getTime();
	QDate d = e.getDate();
	time = new QTime(t.hour(), t.minute(), t.second(), t.msec());
	date = new QDate(d.year(), d.month(), d.day());
	eventId = e.getId();
	notified = e.hasNotified();
}

/**
 * @brief Copy constructor
 *
 * @param e The event to copy from
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 */
void Event::operator = (const Event &e)
{
	message = new QString(e.getMessage());
	type = new QString(e.getType());
	QTime t = e.getTime();
	QDate d = e.getDate();
	time = new QTime(t.hour(), t.minute(), t.second(), t.msec());
	date = new QDate(d.year(), d.month(), d.day());
	eventId = e.getId();
	notified = e.hasNotified();
}

/**
 * @brief == operator
 *
 * @param e The event to compare from
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 */
bool Event::operator == (const Event &other) const
{
	return eventId == other.getId() && other.getTime().hour() == time->hour() && other.getTime().minute() == time->minute() && other.getTime().second() == time->second()
			&& other.getDate().year() == date->year() && other.getDate().month() == date->month() && other.getDate().day() == date->day();
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
Event::~Event(){};

/**
 * @brief Getter for message
 *
 * @param No parameters.
 *
 * @return The event message
 *
 * @authors Yifei Zhang.
 */
QString Event::getMessage() const
{
	QString *s = message;
	return *s;
}

/**
 * @brief Getter for type
 *
 * @param No parameters.
 *
 * @return The event type
 *
 * @authors Yifei Zhang.
 */
QString Event::getType() const
{
	QString *t = type;
	return *t;
}

/**
 * @brief Getter for time
 *
 * @param No parameters.
 *
 * @return The event time
 *
 * @authors Yifei Zhang.
 */
QTime Event::getTime() const
{
	QTime *t = new QTime(time->hour(), time->minute(), time->second(), time->msec());
	return *t;
}

/**
 * @brief Getter for date
 *
 * @param No parameters.
 *
 * @return The event date
 *
 * @authors Yifei Zhang.
 */
QDate Event::getDate() const
{
	QDate *d = new QDate(date->year(), date->month(), date->day());
	return *d;
}

/**
 * @brief Getter for id
 *
 * @param No parameters.
 *
 * @return The event id
 *
 * @authors Yifei Zhang.
 */
int Event::getId() const
{
	return eventId;
}

/**
 * @brief Setter for message
 *
 * @param m The message to set for event
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 */
void Event::setMessage(QString &m)
{
	message = &m;
}

/**
 * @brief Setter for type
 *
 * @param t The type to set for event
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 */
void Event::setType(QString &t)
{
	type = &t;
}

/**
 * @brief Setter for time
 *
 * @param t The time to set for event
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 */
void Event::setTime(QTime &t)
{
	delete time;
	time = new QTime(t.hour(), t.minute(), t.second(), t.msec());
}

/**
 * @brief Setter for date
 *
 * @param d The date to set for event
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 */
void Event::setDate(QDate &d){
	delete date;
	date = new QDate(d.year(), d.month(), d.day());
}

/**
 * @brief Setter for notified
 *
 * @param b The notified status to set for event
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 */
void Event::setNotified(bool b)
{
	notified = b;
}

/**
 * @brief Setter for id
 *
 * @param i The time to set for event
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 */
void Event::setId(int &i)
{
	eventId = i;
}

/**
 * @brief Getter for notified
 *
 * @param No parameters.
 *
 * @return The event's notified status
 *
 * @authors Yifei Zhang.
 */
bool Event::hasNotified() const
{
	return notified;
}

/**
 * @brief Checks if the time of event has passed
 *
 * @param No parameters.
 *
 * @return true if the event time has passed, false otherwise
 *
 * @authors Yifei Zhang.
 */
bool Event::hasPassed()
{
	return *date >= QDate::currentDate() && *time >= QTime::currentTime();
}

