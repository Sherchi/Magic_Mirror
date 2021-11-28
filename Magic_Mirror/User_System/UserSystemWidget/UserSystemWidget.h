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

#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QHBoxLayout>

class UserSystemWidget : public QWidget{
    Q_OBJECT

public:
    UserSystemWidget();
    ~UserSystemWidget();

private slots:
    void handleUserSystemClick();

private:
    QHBoxLayout *hbox;
    AdminAccountInfo *adminAccountInfo;
    UserAccountInfo *userAccountInfo;
    LoginPopup *loginPopup;
    UserSystem *userSystem;
};


#endif //MAGIC_MIRROR_USERSYSTEMWIDGET_H
