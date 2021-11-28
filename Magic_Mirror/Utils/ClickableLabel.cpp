//
// Created by nolan on 2021-11-27.
//

/*
 * @brief This class extends the QLabel class and implements the ability to emit a clicked signal. This allows for the
 * implementation of clickable labels that can handle events when clicked.
 *
 * @authors Nolan Morris.
 * */
#include "ClickableLabel.h"

/*
 * @brief Constructor for the class.
 *
 * @param No parameters.
 *
 * @return No returns.
 *
 * @authors Nolan Morris.
 * */
ClickableLabel::ClickableLabel(QWidget *parent, Qt::WindowFlags f) {

}

/*
 * @brief Listens for a mousePressEvent so that it can emit a clicked() signal that can be used to execute events when
 * the label is clicked
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris.
 * */
void ClickableLabel::mousePressEvent(QMouseEvent *click) {
    emit clicked();
}

/*
 * @brief Destructor for the class
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris.
 * */
ClickableLabel::~ClickableLabel() noexcept {

}