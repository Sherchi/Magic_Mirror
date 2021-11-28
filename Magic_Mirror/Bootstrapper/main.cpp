#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QScreen>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    auto *app = new QApplication(argc, argv);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    auto *mainWindow = new MainWindow(width, height);

    mainWindow->configure();
    mainWindow->setWindowState(Qt::WindowMaximized);
    mainWindow->show();

    mainWindow->showFullScreen(); //shows the window in complete full screen mode without the top or sidebars or anything

    int ret = app->exec();

    delete app;
    delete mainWindow;

    return ret;
}

