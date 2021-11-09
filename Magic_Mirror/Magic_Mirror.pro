QT	+= core widgets gui multimedia
TARGET	= Magic_Mirror
TEMPLATE	= app
SOURCES	+= ./Bootstrapper/main.cpp ./Bootstrapper/MainWindow.cpp ./News/APIRequest.cpp ./News/articleData.cpp ./Weather/getWeather.cpp
HEADERS	+= ./Bootstrapper/MainWindow.h ./News/APIRequest.h ./News/articleData.h ./Weather/getWeather.h


