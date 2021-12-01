QT	+= core widgets gui
TARGET	= m
TEMPLATE = app
VPATH	+= ./CalendarWidget ./AddEventWidget
SOURCES	+= main.cpp AnalogClock.cpp DigitalClock.cpp clock.cpp calendarWidget.cpp event.cpp AddEvent.cpp
HEADERS	+= AnalogClock.h clock.h DigitalClock.h calendarWidget.h event.h AddEvent.h
