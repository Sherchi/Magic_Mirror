//
// Created by nolan on 2021-11-27.
//

/* @brief This class handles the initialization of the clk::Clock class.
 *
 * This class is used to initialize and configure all settings for the clock class so that it can be used in the main
 * window class to show the current time to the second.
 *
 * @authors Nolan Morris, Yiefi Zhang.
 *
 * */
#include "ClockWidget.h"

/*
 * @brief Constructor for the class
 *
 * This constructor initializes and configures the settings for the clock class and configures all the GUI elements.
 * Also sets up a timer to update the time every second.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Yifei Zhang.
 * */
ClockWidget::ClockWidget() {
    vbox = new QVBoxLayout;
    clock = new clk::Clock();
    timeLabel = new QLabel("");

    this->setLayout(vbox);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);

    showTime(); //draws the inital clock so that we can skip waiting for the timer
}

/*
 * @brief This function is responsible for updating the time label
 *
 * This function will pull from the clock object every second, the correct date and time to display to the user
 *
 * @param No parameters
 *
 * @return No return.
 *
 * @authors Nolan Morris, Yifei Zhang.
 * */
void ClockWidget::showTime() {
    clock->update();
    timeLabel->setText(clock->getStrTime());

    auto font = new QFont();
    font->setPointSize(20);
    timeLabel->setFont(*font);

    vbox->addWidget(timeLabel);
}

/* @brief Destructor for the class.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Yifei Zhang.
 * */
ClockWidget::~ClockWidget() noexcept {
    delete timeLabel;
    delete clock;
    delete vbox;
}