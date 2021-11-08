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

namespace event
{
	class Event
	{
		public:
			explicit Event();
			explicit Event(QString m, QString type, QTime t);
			explicit Event(const Event &e);
			void operator = (const Event &e);
			~Event();
			QString getMessage();
			QString getType();
			QTime getTime();
			void setMessage(QString m);
			void setType(QString t);
			void setTime(QTime t);
			void setNotified(bool b);
			bool hasNotified();
			bool hasPassed();
		private:
			QString *message, *type;
			QTime *time;
			bool notified;
	};
}


