//
// Created by nolan on 2021-11-27.
//

/*
 * @brief Displays basic admin account information
 *
 * This class will implement some basic information and functions for administrator accounts such as username of the
 * current logged-in admin, implements the create accounts action and the logout action.
 *
 * @authors Nolan Morris, Peter Nicolaas Meijer.
 * */
#include "AdminAccountInfo.h"

/*
 * @brief Constructor for the class
 *
 * The constructor initializes the settings, the GUI elements and the UserSystem class. It also connects the buttons
 * for creating use accounts and for logging out of the system.
 *
 * @parm userSystem A pointer to a userSystem that handles the account operations.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Perter Nicolaas Meijer.
 * */
AdminAccountInfo::AdminAccountInfo(UserSystem *userSystem) {
    this->userSystem = userSystem;
    create = new CreateUser(this->userSystem);

    username = new QLabel();
    logoutButton = new QPushButton("Logout");
    createUserButton = new QPushButton("Create User");

    auto *hbox = new QHBoxLayout;
    hbox->addWidget(createUserButton);
    hbox->addWidget(logoutButton);
    hbox->setSpacing(10);

    vbox = new QVBoxLayout;

    vbox->addWidget(username);
    vbox->addLayout(hbox);

    this->setLayout(vbox);

    connect(logoutButton, SIGNAL(released()), this, SLOT(logout()));
    connect(createUserButton, SIGNAL(released()), this, SLOT(createUser()));
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
void AdminAccountInfo::setUsername(QString username) {
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
void AdminAccountInfo::logout() {
    userSystem->logout();
    std::cout << "Logged out" << std::endl;
    this->close();
}

/*
 * @brief Creates a new user that can log in and use the system.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Peter Nicolaas Meijer
 * */
void AdminAccountInfo::createUser() {
    create->show();
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
AdminAccountInfo::~AdminAccountInfo() noexcept {
    delete userSystem;
    delete username;
    delete createUserButton;
    delete logoutButton;
    delete vbox;
}