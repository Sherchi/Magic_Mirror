QT	+= core widgets gui multimedia multimediawidgets
TARGET	= Magic_Mirror
TEMPLATE	= app
SOURCES	+= ./Bootstrapper/main.cpp ./Bootstrapper/mainwindow.cpp ./News/APIRequest.cpp ./News/articleData.cpp ./Weather/getWeather.cpp ./Webcam/Camera.cpp
HEADERS	+= ./Bootstrapper/mainwindow.h ./News/APIRequest.h ./News/articleData.h ./Weather/getWeather.h ./Webcam/Camera.h

