#include <QApplication>
#include <iostream>
#include "calendarWidget.h"
#include "event.h"

using namespace std;
using namespace calendar;
using namespace event;

int main(int argc, char *argv[])
{
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
	QApplication app(argc, argv);
	calendarWidget c;
	c.show();

	QString m, ty;
	QTime t;
	QDate d;
	Event e;

	for(int i = 0; i < 10; i++){
		m = QString("Workout");
		ty = QString("Notification");
		t = QTime::currentTime();
		d = QDate::currentDate();
		e = Event(m, ty, t, d);
		/*cout << */c.insertEvent(e);// << endl;
	}
	m = QString("Nothing");
	ty = QString("None");
	t = QTime::currentTime();
	d = QDate::currentDate();
	e = Event(m, ty, t, d);
	c.insertEvent(e);

	/*
	m = QString("NULL");
	ty = QString("NULL");
	t = QTime::currentTime();
	d = QDate::currentDate();
	e = Event(m, ty, t, d);
	c.insertEvent(e);
	*/

	for(int i = 1; i < 4; i ++){
		m = QString("Workout");
		ty = QString("Notification");
		t = QTime::currentTime();
		d = QDate::currentDate();
		e = Event(m, ty, t, d);
		e.setId(i);
		cout << c.deleteEvent(e) << endl;
	}
	

	return app.exec();
}
