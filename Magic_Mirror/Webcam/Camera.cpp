//
// Created by nolan on 2021-11-20.
//

/*
 * @brief This class configures the QCamera class and creates a QGrpahicsViewFinder so that the camera can be added to
 * the background of the MainWindow.
 *
 * @authors Nolan Morris.
 * */
#include <iostream>
#include "Camera.h"

/*
 * @brief Constructor for the class. Initializes the camera and all the necessary elements to add the camera to the
 * background of the graphics scene.
 *
 * @param screenWidth Width of the currently attached display.
 *
 * @param screenHeight Height of the currently attached display.
 *
 * @param parent Null pointer to a parent QWidget.
 *
 * @return No returns.
 *
 * @authors Nolan Morris.
 * */
Camera::Camera(int screenWidth, int screenHeight, QWidget *parent){
    camera = new QCamera(this);

    cameraFeed = new QGraphicsVideoItem;
    camera->setViewfinder(cameraFeed);
    cameraFeed->setSize(QSizeF(screenWidth, screenHeight));
    cameraFeed->mapToScene(0,0);
    cameraFeed->setPos(0,0);

    start();
}

/*
 * @brief Returns the graphicsView so that it can be added to the graphics scene in the MainWindow class.
 *
 * @param No parameters.
 *
 * @return QGraphicsView Returns the configured graphics view to be added to the scene.
 *
 * @authors Nolan Morris.
 * */
QGraphicsVideoItem* Camera::getVideoItem() { //returns the viewfinder pointer to add to a layout or graphics scene
    return cameraFeed;
}

/*
 * @brief Starts the attached camera and broadcasts the input to the screen.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authos Nolan Morris.
 * */
void Camera::start(){
    camera->start();
    std::cout << "Camera started" << std::endl;
}

/*
 * @brief Stops the camera from broadcasting. Used before deleting the object in MainWindow.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris.
 * */
void Camera::stop(){
    camera->stop();
}

/*
 * @brief Destructor for the class.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris.
 * */
Camera::~Camera(){
    delete camera;
    delete cameraFeed;
    delete graphicsView;
}