//
// event.cpp
//
// Author: Yifei Zhang
//
// Last update on: 2021/11/08
//

#include "event.h"

using namespace event;

Event::Event()
{
	eventId = 0;
	message = new QString();
	type = new QString();
	time = new QTime();
	date = new QDate();
	notified = false;
}

Event::Event(QString &m, QString &type, QTime &t, QDate &d)
{
	eventId = 0;
	message = new QString(m);
	this->type = new QString(type);
	time = new QTime(t.hour(), t.minute(), t.second(), t.msec());
	date = new QDate(d.year(), d.month(), d.day());
	notified = false;
}

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

bool Event::operator == (const Event &other) const
{
	return eventId == other.getId();
}

Event::~Event(){};

QString Event::getMessage() const
{
	QString *s = message;
	return *s;
}

QString Event::getType() const
{
	QString *t = type;
	return *t;
}

QTime Event::getTime() const
{
	QTime *t = new QTime(time->hour(), time->minute(), time->second(), time->msec());
	return *t;
}

QDate Event::getDate() const
{
	QDate *d = new QDate(date->year(), date->month(), date->day());
	return *d;
}

int Event::getId() const
{
	return eventId;
}

void Event::setMessage(QString &m)
{
	message = &m;
}

void Event::setType(QString &t)
{
	type = &t;
}

void Event::setTime(QTime &t)
{
	delete time;
	time = new QTime(t.hour(), t.minute(), t.second(), t.msec());
}

void Event::setDate(QDate &d){
    delete date;
    date = new QDate(d.year(), d.month(), d.day());
}

void Event::setNotified(bool b)
{
	notified = b;
}

void Event::setId(int &i)
{
	eventId = i;
}

bool Event::hasNotified() const
{
	return notified;
}

bool Event::hasPassed()
{
	return *date >= QDate::currentDate() && *time >= QTime::currentTime();
}

