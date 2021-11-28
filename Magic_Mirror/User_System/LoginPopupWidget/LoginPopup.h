//
// Created by nolan on 2021-11-27.
//

#ifndef MAGIC_MIRROR_LOGINPOPUP_H
#define MAGIC_MIRROR_LOGINPOPUP_H

#include "../UserSystem.h"
#include "../User.h"

#include <iostream>
#include <QWidget>
#include <QString>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

class LoginPopup : public QWidget{
    Q_OBJECT

public:
    LoginPopup(UserSystem *userSystem);
    ~LoginPopup();

private slots :
    void login();

private:
    UserSystem *userSystem;
    QLineEdit *usernameBox;
    QLineEdit *passwordBox;
    QPushButton *loginButton;
    QVBoxLayout *layout;

};


#endif //MAGIC_MIRROR_LOGINPOPUP_H
