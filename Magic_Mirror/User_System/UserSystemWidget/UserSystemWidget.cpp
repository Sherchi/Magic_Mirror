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
    timer = new QTimer(this);
    userSystem = &UserSystem::instance();
    vbox = new QVBoxLayout;
    adminAccountInfo = new AdminAccountInfo(userSystem);
    userAccountInfo = new UserAccountInfo(userSystem);
    loginPopup = new LoginPopup(userSystem);

    auto *accountImage = new QPixmap();
    QString path = QString::fromStdString(std::filesystem::current_path()) + "/Bootstrapper/Images/Account.png";
    accountImage->load(path);
    auto *accountLabel = new ClickableLabel();
    accountLabel->setPixmap(accountImage->scaled(50, 50, Qt::KeepAspectRatio));

    connect(accountLabel, SIGNAL(clicked()), this, SLOT(handleUserSystemClick()));

    senderLabel = new QLabel("");
    subjectLabel = new QLabel("");

    vbox->addWidget(accountLabel);
    vbox->addWidget(senderLabel, Qt::AlignLeft);
    vbox->addWidget(subjectLabel, Qt::AlignLeft);
    vbox->setSpacing(10);
    this->setLayout(vbox);
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
    if(userSystem->getActiveUser()->isActivated()){
        if(userSystem->getActiveUser()->isAdmin()) {
            adminAccountInfo->setUsername(QString::fromStdString(userSystem->getActiveUser()->getUsername()));
            adminAccountInfo->show();
        }
        else{
            userAccountInfo->setUsername(QString::fromStdString(userSystem->getActiveUser()->getUsername()));
            userAccountInfo->show();
        }

        if(!userSystem->getActiveUser()->hasInbox()) { //if there is no inbox configured, configure it
            userSystem->getActiveUser()->configureInbox("imap.gmail.com", userSystem->getActiveUser()->getUsername(), userSystem->getActiveUser()->getPassword());
            std::cout << "config successful" <<std::endl;
        }

        userSystem->getActiveUser()->getInbox()->updateInbox();

        if(!userSystem->getActiveUser()->getInbox()->getEmails().empty()){ //if the email list is not empty display the emails

            emails = userSystem->getActiveUser()->getInbox()->getEmails();
            index = 0;

            connect(timer, SIGNAL(timeout()), this, SLOT(scrollEmails()));
            timer->start(10000);
            scrollEmails();
        }
        else{ //if there is no valid email then display nothing
            timer->stop();
            senderLabel->setText("");
            subjectLabel->setText("");
        }
    }
    else {
        loginPopup->show();
    }
}

/*
 * @brief A function that scrolls and updates the emails being displayed on screen.
 *
 * @param No parameters
 *
 * @return No return.
 *
 * @authors Nolan Morris.
 * */
void UserSystemWidget::scrollEmails() {
    senderLabel->setText(QString::fromStdString(emails[index]->getSender()));
    subjectLabel->setText(QString::fromStdString(emails[index]->getSubject()));

    index++;
    if(index == emails.size()){
        index = 0;
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
    delete vbox;
    delete adminAccountInfo;
    delete userAccountInfo;
    delete loginPopup;
    delete userSystem;
}
