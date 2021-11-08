//
// clock.h
//
// Author: Yifei Zhang
//
// Last update on: 2021/11/07
//
#pragma once

#include<QWidget>
#include<QDateTime>
#include<QTimeZone>
#include<QString>
#include<string>

namespace clk
{
	class Clock
	{	
		private:	
			QDateTime dateTime;
			QTimeZone timeZone;
		public:
			explicit Clock();
			explicit Clock(std::string id);
			~Clock();
			int* getTime();
			QString getStrTime();
			bool switchTimeZone(std::string id);
			void update();
			//QWidget digitalClock();
			//QWidget analogClock();
	};
}


