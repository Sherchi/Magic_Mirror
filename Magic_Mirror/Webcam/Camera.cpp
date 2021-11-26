//
// Created by nolan on 2021-11-20.
//

#include <iostream>
#include "Camera.h"

Camera::Camera(int screenWidth, int screenHeight, QWidget *parent){
    camera = new QCamera(this);

    cameraFeed = new QGraphicsVideoItem;
    camera->setViewfinder(cameraFeed);
    cameraFeed->setSize(QSizeF(screenWidth, screenHeight));
    cameraFeed->mapToScene(0,0);
    cameraFeed->setPos(0,0);

    start();
}

QGraphicsVideoItem* Camera::getVideoItem() { //returns the viewfinder pointer to add to a layout or graphics scene
    return cameraFeed;
}

void Camera::start(){
    camera->start();
    std::cout << "Camera started" << std::endl;
}

void Camera::stop(){
    camera->stop();
}

Camera::~Camera(){
    delete camera;
    delete cameraFeed;
    delete graphicsView;
}