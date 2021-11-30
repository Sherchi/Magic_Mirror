//
// calendarWidget.h
//
// Author: Yifei Zhang
//
// Last update on: 2021/11/07
//
#pragma once

<<<<<<< HEAD
#include "../AddEventWidget/AddEvent.h"

=======
>>>>>>> a017f19a296b9f840446b1f4066b6a43d4fec8f3
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
<<<<<<< HEAD
        void boxClicked();
        void handleEventCreated();
=======
>>>>>>> a017f19a296b9f840446b1f4066b6a43d4fec8f3
		
		signals:
		void eventUpdated();

		private:
<<<<<<< HEAD
        AddEvent *addEvent;
=======
>>>>>>> a017f19a296b9f840446b1f4066b6a43d4fec8f3
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
