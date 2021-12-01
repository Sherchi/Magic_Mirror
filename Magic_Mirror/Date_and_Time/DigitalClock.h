/**
 * calendarWidget.cpp
 *
 * Author: Yifei Zhang
 *
 * Last update on: 2021/11/30
 */
#pragma once

#include <QLCDNumber>

class DigitalClock : public QLCDNumber{
	Q_OBJECT

	public:
		DigitalClock(QWidget *parent = nullptr);

	private slots:
		void showTime();
};
