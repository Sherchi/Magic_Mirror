//
// calendarWidget.h
//
// Author: Yifei Zhang
//
// Last update on: 2021/11/07
//
#pragma once

#include "../AddEventWidget/AddEvent.h"

#include <QCalendarWidget>
#include <QGroupBox>
#include <QCheckBox>
#include <QGridLayout>
#include <QDateEdit>
#include <QLabel>
#include <QTextEdit>
#include <QMap>
#include <QVector>
#include "event.h"

namespace calendar
{
	class calendarWidget : public QWidget
	{
		Q_OBJECT
		public:
		calendarWidget(QWidget *parent = nullptr);
		bool insertEvent(event::Event &e);
		bool deleteEvent(event::Event &e);

		private slots:
		void dateChanged();
        void boxClicked();
        void handleEventCreated();
		
		signals:
		void eventUpdated();

		private:
        AddEvent *addEvent;
		static int currentId;
		QCalendarWidget *calendar;
		QGroupBox *calendarGroupBox, *informationGroupBox;
		QDateEdit *dateSelection;
		QGridLayout *calendarLayout, *informationLayout;
		QLabel *currentDateLabel;
		QTextEdit *currentDateInformation;
		QMap<QDate, QVector<event::Event>> *eventMap;
		void createCalendarBox();
		void createInformationBox();		
	};
}
