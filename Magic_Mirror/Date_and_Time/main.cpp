#include <QApplication>

#include "clock.h"
#include "./CalendarWidget/calendarWidget.h"
#include <QDateTime>

using namespace clk;
using namespace calendar;
using namespace event;

int main(int argc, char *argv[]){
	QApplication app(argc, argv);
	calendarWidget *c = new calendarWidget(nullptr, "./Events.txt");
	//QWidget *clockptr = clock.digitalClock();
	c->show();

	//QDate date = QDate(2021, 11, 30);
	//QTime time = QTime(19, 10);
	//QString m = QString("Today message");
	//QString t = QString("Birthday");
	//Event e;
	//e = Event(m, t, time, date);

	//c->insertEvent(e);
	return app.exec();
}
