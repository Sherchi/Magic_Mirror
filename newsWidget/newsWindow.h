//
// Created by darwin on 2021-11-05.
//

#ifndef NEWSPROJECT_NEWSWINDOW_H
#define NEWSPROJECT_NEWSWINDOW_H

/*
 * include statements
 */
#include <QtWidgets>
#include <QMainWindow>
#include <QString>
#include "APIRequest.h"
#include <stdio.h>

namespace Ui{
    class newsWindow;
}

class NewsWindow : public QMainWindow{
Q_OBJECT public:
    explicit NewsWindow (QWidget *parent = nullptr);

private slots:
    void onBtnClick();


private:
    QPushButton *btnReq;
    QLabel  *lblOutput;

};


#endif //NEWSPROJECT_NEWSWINDOW_H
