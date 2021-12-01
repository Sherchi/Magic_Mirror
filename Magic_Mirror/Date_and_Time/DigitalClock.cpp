/**
 * calendarWidget.cpp
 *
 * Author: Yifei Zhang
 *
 * Last update on: 2021/11/30
 */
#include "DigitalClock.h"

#include <QTime>
#include <QTimer>

/**
 * @brief Default constructor
 *
 * @param parent The parent widget
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 */
DigitalClock::DigitalClock(QWidget *parent) : QLCDNumber(parent){
	setSegmentStyle(Filled);
	setDigitCount(8);

	QTimer *timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &DigitalClock::showTime);
	timer->start(1000);

	showTime();

	setWindowTitle(tr("Digital Clock"));
	resize(300, 120);
}

/**
 * @brief Display the current time.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Yifei Zhang.
 * /
void DigitalClock::showTime(){
	QTime time = QTime::currentTime();

	QString text = time.toString("hh:mm:ss");
	if((time.second() % 2) == 0){	// Makes the colon flashes every second.
		text[2] = ' ';
		text[5] = ' ';
	}
	display(text);
}
