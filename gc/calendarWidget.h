//
// calendarWidget.h
//
// Author: Yifei Zhang
//
// Last update on: 2021/11/07
//
#pragma once

#include <QCalendarWidget>
#include <QGroupBox>
#include <QCheckBox>
#include <QGridLayout>
#include <QDateEdit>
#include <QLabel>
#include <QTextEdit>

namespace calendar
{
	class calendarWidget : public QWidget
	{
		Q_OBJECT
		public:
		calendarWidget(QWidget *parent = nullptr);

		private slots:
		void dateChanged();

		private:
		QCalendarWidget *calendar;
		QGroupBox *calendarGroupBox, *informationGroupBox;
		QDateEdit *dateSelection;
		QGridLayout *calendarLayout, *informationLayout;
		QLabel *currentDateLabel;
		QTextEdit *currentDateInformation;
		void createCalendarBox();
		void createInformationBox();
	};
}
