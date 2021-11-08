//
// calendarWidget.cpp
//
// Author: Yifei Zhang
//
// Last update on: 2021/11/07
//

#include <QDate>
#include "calendarWidget.h"

using namespace calendar;

// Constructor. 600:300 is probably the best for this calendar widget since QCalendarWidget has fixed size
calendarWidget::calendarWidget(QWidget *parent) : QWidget(parent)
{
	createCalendarBox();
	createInformationBox();

	QGridLayout *layout = new QGridLayout;
	layout->addWidget(calendarGroupBox, 0, 0);
	layout->addWidget(informationGroupBox, 0, 1);
	setLayout(layout);

	resize(600, 300);

	setWindowTitle(tr("Calendar Widget"));
}

// Create the QGroupBox that contains the calendar and a way to change the date, the Calendar is also clickable.
void calendarWidget::createCalendarBox()
{
	calendarGroupBox = new QGroupBox(tr("Calendar"));

	calendar = new QCalendarWidget;
	calendar->setMinimumDate(QDate(1900, 1, 1));
	calendar->setMaximumDate(QDate(3000, 1, 1));
	calendar->setGridVisible(true);

	dateSelection = new QDateEdit();
	dateSelection->setDisplayFormat("yyyy MMM dd");
	dateSelection->setDateRange(calendar->minimumDate(), calendar->maximumDate());
	dateSelection->setDate(QDate::currentDate());

	currentDateLabel = new QLabel(tr("&Current Date: "));
	currentDateLabel->setBuddy(dateSelection);

	calendarLayout = new QGridLayout;
	calendarLayout->addWidget(currentDateLabel, 0, 0, Qt::AlignLeft);
	calendarLayout->addWidget(dateSelection, 0, 1, Qt::AlignLeft);
	calendarLayout->addWidget(calendar, 1, 0, 10, 10,Qt::AlignCenter);
	calendarGroupBox->setLayout(calendarLayout);

	connect(dateSelection, &QDateEdit::dateChanged, calendar, &QCalendarWidget::setSelectedDate);
	connect(calendar, &QCalendarWidget::selectionChanged, this, &calendarWidget::dateChanged);
}

// Create the QGroupBox that contains the information of the day selected, event display will be implemented later
void calendarWidget::createInformationBox()
{
	informationGroupBox = new QGroupBox(calendar->selectedDate().toString("On ddd, MMM dd yyyy"));

	currentDateInformation = new QTextEdit("Nothing for today");
	currentDateInformation->setReadOnly(true);

	informationLayout = new QGridLayout;
	informationLayout->addWidget(currentDateInformation, 0, 0, Qt::AlignCenter);
	informationGroupBox->setLayout(informationLayout);
}

// Called when the date menu has changed
void calendarWidget::dateChanged()
{
	dateSelection->setDate(calendar->selectedDate());
	informationGroupBox->setTitle(calendar->selectedDate().toString("On ddd, MMM dd yyyy"));
}
