//
// Created by nolan on 2021-11-28.
//

/*
 * @brief handles which page to display depending on if there is a user logged in and what kind of user is logged in
 *
 * @authors Nolan Morris, Peter Nicolaas Meijer.
 * */
#include "UserSystemWidget.h"

/*
 * @brief Constructor for the class.
 *
 * This class initializes the settings, the GUI elements and various pages that can be displayed depending on if there
 * is a user logged in and if that user is admin or not.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Peter Nicolaas Meijer.
 * */
UserSystemWidget::UserSystemWidget() {
    userSystem = new UserSystem;
    hbox = new QHBoxLayout;
    adminAccountInfo = new AdminAccountInfo(userSystem);
    userAccountInfo = new UserAccountInfo(userSystem);
    loginPopup = new LoginPopup(userSystem);

    auto *accountImage = new QPixmap();
    accountImage->load("/home/nolan/CLionProjects/Magic Mirror/Magic_Mirror/Bootstrapper/Images/Account.png");
    auto *accountLabel = new ClickableLabel();
    accountLabel->setPixmap(accountImage->scaled(50, 50, Qt::KeepAspectRatio));

    connect(accountLabel, SIGNAL(clicked()), this, SLOT(handleUserSystemClick()));

    hbox->addWidget(accountLabel);
    this->setLayout(hbox);
}

/*
 * @brief Handles any clicks on the icon and determines which window to show the user.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Peter Nicolaas Meijer.
 * */
void UserSystemWidget::handleUserSystemClick() {
    if(userSystem->getActiveUser().isActivated()){
        if(userSystem->getActiveUser().isAdmin()) {
            adminAccountInfo->setUsername(QString::fromStdString(userSystem->getActiveUser().getUsername()));
            adminAccountInfo->show();
        }
        else{
            userAccountInfo->setUsername(QString::fromStdString(userSystem->getActiveUser().getUsername()));
            userAccountInfo->show();
        }
    }
    else {
        loginPopup->show();
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
UserSystemWidget::~UserSystemWidget() noexcept {
    delete hbox;
    delete adminAccountInfo;
    delete userAccountInfo;
    delete loginPopup;
    delete userSystem;
}
