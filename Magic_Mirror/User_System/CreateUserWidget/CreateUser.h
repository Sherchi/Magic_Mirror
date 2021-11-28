//
// Created by nolan on 2021-11-28.
//

#ifndef MAGIC_MIRROR_CREATEUSER_H
#define MAGIC_MIRROR_CREATEUSER_H

#include "../UserSystem.h"

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class CreateUser : public QWidget{
    Q_OBJECT

public:
    CreateUser(UserSystem *userSystem);
    ~CreateUser();

private slots:
    void create();
    void handleCheckBox();

private:
    bool isAdmin;
    QVBoxLayout *vbox;
    UserSystem *userSystem;
    QLineEdit *usernameField;
    QLineEdit *passwordFeild;
    QCheckBox *adminCheckBox;
    QPushButton *input;
};


#endif //MAGIC_MIRROR_CREATEUSER_H
