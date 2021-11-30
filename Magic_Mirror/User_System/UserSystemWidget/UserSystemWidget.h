//
// Created by nolan on 2021-11-28.
//

#ifndef MAGIC_MIRROR_USERSYSTEMWIDGET_H
#define MAGIC_MIRROR_USERSYSTEMWIDGET_H

#include "../UserSystem.h"
#include "../AdminAccountInfoWidget/AdminAccountInfo.h"
#include "../UserAccountInfoWidget/UserAccountInfo.h"
#include "../LoginPopupWidget/LoginPopup.h"
#include "../../Utils/ClickableLabel.h"
#include "../../MailClient/Email.h"

#include "filesystem"
#include <vector>
#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimer>

class UserSystemWidget : public QWidget{
    Q_OBJECT

public:
    UserSystemWidget();
    ~UserSystemWidget();

private slots:
    void handleUserSystemClick();
    void scrollEmails();

private:
    QTimer *timer;
    int index;
    std::vector<Email*> emails;
    QVBoxLayout *vbox;
    AdminAccountInfo *adminAccountInfo;
    UserAccountInfo *userAccountInfo;
    LoginPopup *loginPopup;
    UserSystem *userSystem;
    QLabel *senderLabel;
    QLabel *subjectLabel;
};


#endif //MAGIC_MIRROR_USERSYSTEMWIDGET_H
