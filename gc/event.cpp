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
	message = new QString();
	type = new QString();
	time = new QTime();
	notified = false;
}

Event::Event(QString m, QString type, QTime t)
{
	message = m;
	this.type = type;
	time = t;
	notified = false;
}

Event::Event(const Event &e)
{
	message = e->getMessage();
	type = e->getType();
	time = e->getTime();
	notified = e->hasNotified();
}

void Event::operator = (const Event &e)
{
	message = e->getMessage();
	type = e->getType();
	time = e->getTime();
	notified = e->hasNotified();
}

Event::~Event(){};

QString Event::getMessage()
{
	return message;
}

QString Event::getType()
{
	return type;
}

QTime Event::getTime()
{
	return time
}

void Event::setMessage(QString m)
{
	message = m;
}

void Event::setType(QString t)
{
	type = t;
}

void Event::setTime(QTime t)
{
	time = QTime(t.hour(), t.minute(), t.second(), t.msec());
}

void Event::setNotified(bool b)
{
	notified = b;
}

bool Event::hasNotified()
{
	return notified;
}

bool hasPassed()
{
	return time >= QTime::currentTime();
}

