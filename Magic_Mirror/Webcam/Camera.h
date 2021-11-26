//
// Created by nolan on 2021-11-20.
//

#ifndef MAGIC_MIRROR_CAMERA_H
#define MAGIC_MIRROR_CAMERA_H

#include <QWidget>
#include <QCamera>
#include <QCameraViewfinder>
#include <QGraphicsScene>
#include <QGraphicsVideoItem>
#include <QGraphicsView>
#include <QGraphicsLayoutItem>

class Camera : public QWidget{
    Q_OBJECT

public:
    Camera(int screenWidth, int screenHeight, QWidget *parent = nullptr);
    ~Camera();
    QGraphicsVideoItem* getVideoItem();
    void start();
    void stop();

private slots:

private:
    QCamera *camera;
    QGraphicsView *graphicsView;
    QGraphicsVideoItem *cameraFeed;
};


#endif //MAGIC_MIRROR_CAMERA_H
