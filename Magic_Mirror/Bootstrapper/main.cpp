#include <iostream>
#include <QApplication>
#include <QWidget>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    auto *mainWindow = new MainWindow;
    auto *window = new QWidget;

    mainWindow->configure();

    window->setStyleSheet("background-color:white;");
    window->setLayout(mainWindow->getLayout());
    window->setWindowState(Qt::WindowMaximized);
    window->show();

//    window->showFullScreen(); //shows the window in complete full screen mode without the top or sidebars or anything

    int ret = app.exec();

    delete mainWindow;
    delete window;

    return ret;
}

