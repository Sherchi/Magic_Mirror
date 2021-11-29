//
// event.h
//
// Author: Yifei Zhang
//
// Last update on: 2021/11/08
//
#pragma once

#include <QString>
#include <QTime>
#include <QDate>

namespace event
{
	class Event
	{
		public:
			explicit Event();
			explicit Event(QString &m, QString &type, QTime &t, QDate &d);
			explicit Event(const Event &e);
			void operator = (const Event &e);
			bool operator == (const Event &other) const;
			~Event();
			QString getMessage() const;
			QString getType() const;
			QTime getTime() const;
			QDate getDate() const;
			int getId() const;
			void setMessage(QString &m);
			void setType(QString &t);
			void setTime(QTime &t);
			void setDate(QDate &d);
			void setNotified(bool b);
			void setId(int &i);
			bool hasNotified() const;
			bool hasPassed();
		private:
			QString *message, *type;
			QTime *time;
			QDate *date;
			int eventId = 0;
			bool notified;
	};
}


