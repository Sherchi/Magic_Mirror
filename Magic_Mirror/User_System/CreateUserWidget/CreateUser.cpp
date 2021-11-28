//
// Created by nolan on 2021-11-28.
//

/*
 * @brief Provides the GUi that admins can use to add new users to the system. It allows them to set username and
 * password along with giving them admin permissions.
 *
 * @authors Nolan Morris, Peter Nicolaas Meijer.
 * */
#include "CreateUser.h"

/*
 * @brief Constructor for the class.
 *
 * This class initializes all the GUI elements, the settings for those elements and the userSystem to handle creating
 * the users. It also connects the checkbox to a function to change the admin boolean variable and connects the button
 * to the function that handles the login process.
 *
 * @param userSystem A pointer to a userSystem object for handling the process of creating actual users.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Peter Nicolaas Meijer.
 * */
CreateUser::CreateUser(UserSystem *userSystem) {
    isAdmin = false;
    this->userSystem = userSystem;
    usernameField = new QLineEdit();
    passwordFeild = new QLineEdit();
    adminCheckBox = new QCheckBox("Admin");
    input = new QPushButton("Login");
    vbox = new QVBoxLayout();
    auto *hbox = new QHBoxLayout();

    this->setLayout(vbox);

    usernameField->setPlaceholderText("Username");
    passwordFeild->setPlaceholderText("Password");
    passwordFeild->setEchoMode(QLineEdit::Password);

    hbox->setSpacing(10);
    hbox->addWidget(adminCheckBox);
    hbox->addWidget(input);

    vbox->addWidget(usernameField);
    vbox->addWidget(passwordFeild);
    vbox->addLayout(hbox);

    connect(adminCheckBox, SIGNAL(stateChanged(int)), this, SLOT(handleCheckBox()));
    connect(input, SIGNAL(released()), this, SLOT(create()));
}

/*
 * @brief Function for passing all relevant information to the userSystem for the creation of a new user.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Peter Nicolaas Meijer
 * */
void CreateUser::create() {
    if(usernameField->text().size() != 0 && passwordFeild->text().size() != 0){ //ensures that there is text in the fields to create a user
        userSystem->createUser(usernameField->text().toStdString(), passwordFeild->text().toStdString(), isAdmin);
    }
    this->close();
}

/*
 * @brief Function for changing the admin boolean variable for if the admin wants to give the new user admin
 * permissions.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Peter Nicolaas Meijer.
 * */
void CreateUser::handleCheckBox() {
    if(isAdmin){
        isAdmin = false;
    }
    else{
        isAdmin = true;
    }
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
CreateUser::~CreateUser() noexcept {
    delete userSystem;
    delete usernameField;
    delete passwordFeild;
    delete adminCheckBox;
    delete input;
    delete vbox;
}