//
// Created by nolan on 2021-11-28.
//

/*
 * @brief Displayed basic account information.
 *
 * This class will display basic account information and functions for basic user accounts such as the username of the
 * currently logged-in user and implements the logout button for the user.
 *
 * @authors Nolan Morris, Peter Nicolaas Meijer.
 * */
#include "UserAccountInfo.h"

/*
 * @brief Constructor for the class.
 *
 * The constructor initializes the settings, the GUI elements and the userSystem class. It also connects the button for
 * implementing the logout function.
 *
 * @param userSystem Pointer to a userSystem object to implement the logout functionality.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Peter Nicolaas Meijer.
 * */
UserAccountInfo::UserAccountInfo(UserSystem *userSystem) {
    this->userSystem = userSystem;

    username = new QLabel();
    logoutButton = new QPushButton("Logout");
    vbox = new QVBoxLayout();
    this->setLayout(vbox);

    vbox->addWidget(username);
    vbox->addWidget(logoutButton);

    connect(logoutButton, SIGNAL(released()), this, SLOT(logout()));
}

/*
 * @brief Updates the username label with the username of the current account.
 *
 * @param username A QString that is pulled from the userSystem of the current logged in account.
 *
 * @return No returns.
 *
 * @authors Nolan Morris, Peter Nicolaas Meijer
 * */
void UserAccountInfo::setUsername(QString username) {
    this->username->setText(username);
}

/*
 * @brief Logs the current user out of the system.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Peter Nicolaas Meijer
 * */
void UserAccountInfo::logout() {
    userSystem->logout();
    std::cout << "Logged out" << std::endl;
    this->close();
}

/*
 * @brief Destructor for the class.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Peter Nicolaas Meijer
 * */
UserAccountInfo::~UserAccountInfo() noexcept {
    delete userSystem;
    delete vbox;
    delete username;
    delete logoutButton;
}