//
// Created by nolan on 2021-11-27.
//

/* @brief This class handles the initialization of the QCalendarWidget.
 *
 * This class is used to initialize the calendars can configure all the settings so that it can be used in the main
 * window class.
 *
 * @authors Nolan Morris, Yifei Zhang.
 *
 * */
#include "CalendarWidget.h"


/*
 * @brief Constructor for the class.
 *
 * This constructor initializes and configures all the calendar settings.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Yifei Zhang.
 *
 * */
CalendarWidget::CalendarWidget() {
    calendarWidget = new QCalendarWidget();
    vbox = new QVBoxLayout;

    calendarWidget->setMinimumDate(QDate(2000, 1, 1));
    calendarWidget->setMaximumDate(QDate(2050, 1, 1));

    calendarWidget->setMaximumHeight(500);
    calendarWidget->setMaximumWidth(500);

    calendarWidget->setStyleSheet("background-color:grey");

    vbox->addWidget(calendarWidget);
    this->setLayout(vbox);
}

/*
 * @brief Destructor for the class.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Yifei Zhang.
 * */
CalendarWidget::~CalendarWidget() noexcept {
    delete calendarWidget;
    delete vbox;
}