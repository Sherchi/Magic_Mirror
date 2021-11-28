//
// Created by nolan on 2021-11-27.
//

/*
 * @brief Displays the login page.
 *
 * This class will configure the GUI elements for the login page for the user system class.
 *
 * @authors Nolan Morris, Peter Nicolaas Meijer.
 * */
#include "LoginPopup.h"

/*
 * @brief Constructor for the class.
 *
 * This class initializes the settings, the GUI elements and the userSystem class. Contains the text fields for the
 * username and password text fields and the login button to input the information.
 *
 * @param userSystem a pointer to a userSystem object to handle the account operations.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Peter Nicolaas Meijer.
 * */
LoginPopup::LoginPopup(UserSystem *userSystem) {

    //we can use activeUser.isActivated() to see if there is anyone logged in

    this->userSystem = userSystem;
    usernameBox = new QLineEdit;
    passwordBox = new QLineEdit;
    loginButton = new QPushButton("login");

    layout = new QVBoxLayout;

    usernameBox->setPlaceholderText("Username");
    passwordBox->setPlaceholderText("Password");
    passwordBox->setEchoMode(QLineEdit::Password);

    layout->addWidget(usernameBox);
    layout->addWidget(passwordBox);
    layout->addWidget(loginButton);
    layout->setAlignment(loginButton, Qt::AlignRight);

    this->setLayout(layout);

    connect(loginButton, SIGNAL(released()), this, SLOT(login()));

}

/*
 * @brief This class handles taking in the login information from the user and sending it to the userSystem for
 * verification.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Peter Nicolaas Meijer.
 * */
void LoginPopup::login(){
    int ret = userSystem->login(usernameBox->text().toStdString(), passwordBox->text().toStdString());

    if (ret == 0) {
        std::cout << "Login successful" << std::endl;
        this->close();
    } else if (ret > -3) {
        std::cout << "Invalid Information" << std::endl;
    } else {
        std::cout << "Another user is already logged in" << std::endl;
    }
    usernameBox->setText("");
    passwordBox->setText("");

}

/*
 * @brief Destructor for the class.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Peter Nicolaas Meijer.
 * */
LoginPopup::~LoginPopup() noexcept {
    delete userSystem;
    delete usernameBox;
    delete passwordBox;
    delete loginButton;
}