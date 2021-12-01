/**
 * calendarWidget.h
 *
 * Author: Yifei Zhang
 *
 * Last update on: 2021/11/30
 */
#pragma once

#include "../AddEventWidget/AddEvent.h"
#include <QCalendarWidget>
#include <QGroupBox>
#include <QCheckBox>
#include <QComboBox>
#include <QGridLayout>
#include <QDateEdit>
#include <QLabel>
#include <QTextEdit>
#include <QMap>
#include <QVector>
#include <string>
#include "event.h"

namespace calendar
{
	class calendarWidget : public QWidget
	{
		Q_OBJECT
		public:
		calendarWidget(QWidget *parent = nullptr, std::string path = "");
		bool insertEvent(event::Event &e);
		bool deleteEvent(event::Event &e);

		private slots:
		void dateChanged();
	        	void insertClicked();
		void deleteClicked();
	        	void handleEventCreated();
		
		signals:
		void eventUpdated();

		private:
		bool hasRead = false;
	        	AddEvent *addEvent;
		std::string eventFilePath;
		static int currentId;
		QComboBox *eventList;
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
