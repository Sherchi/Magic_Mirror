//
// Created by darwin on 2021-11-05.
//

#include "QApplication"
#include "QWidget"
#include "QString"
#include "newsWindow.h"
#include "stdio.h"

NewsWindow::NewsWindow(QWidget *parent): QMainWindow(parent){
    this->resize(370,400);

    btnReq = new QPushButton("REQUEST",this);
    btnReq->setGeometry(QRect(243, 32, 89, 25));
    connect(btnReq, &QPushButton::released, this, &NewsWindow::onBtnClick);


}

void NewsWindow::onBtnClick(){


};