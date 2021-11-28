//
// Created by nolan on 2021-11-27.
//

#ifndef MAGIC_MIRROR_ADMINACCOUNTINFO_H
#define MAGIC_MIRROR_ADMINACCOUNTINFO_H

#include "../UserSystem.h"
#include "../CreateUserWidget/CreateUser.h"

#include <iostream>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class AdminAccountInfo : public QWidget{
    Q_OBJECT

public:
    AdminAccountInfo(UserSystem *userSystem);
    void setUsername(QString);
    ~AdminAccountInfo();

private slots:
    void logout();
    void createUser();

private:
    CreateUser *create;
    UserSystem *userSystem;
    QLabel *username;
    QPushButton *createUserButton;
    QPushButton *logoutButton;
    QVBoxLayout *vbox;

};


#endif //MAGIC_MIRROR_ADMINACCOUNTINFO_H
