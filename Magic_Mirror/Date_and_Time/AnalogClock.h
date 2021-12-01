/**
 * calendarWidget.cpp
 *
 * Author: Yifei Zhang
 *
 * Last update on: 2021/11/30
 */
#pragma once

#include <QWidget>

class AnalogClock : public QWidget
{
	Q_OBJECT
		
	public:
		AnalogClock(QWidget *parent = nullptr);

	protected:
		void paintEvent(QPaintEvent *event) override;
};
