//
// Created by nolan on 2021-11-28.
//

#ifndef MAGIC_MIRROR_USERACCOUNTINFO_H
#define MAGIC_MIRROR_USERACCOUNTINFO_H

#include "../UserSystem.h"

#include <iostream>
#include <QWidget>
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class UserAccountInfo : public QWidget{
    Q_OBJECT

public:
    UserAccountInfo(UserSystem *userSystem);
    ~UserAccountInfo();
    void setUsername(QString);

private slots:
    void logout();

private:
    UserSystem *userSystem;
    QLabel *username;
    QPushButton *logoutButton;
    QVBoxLayout *vbox;

};


#endif //MAGIC_MIRROR_USERACCOUNTINFO_H
