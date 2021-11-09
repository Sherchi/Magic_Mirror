#include "getWeather.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    getWeather weatherGetter;
    weatherGetter.fetchWeather("http://api.openweathermap.org/data/2.5/weather?q=London,uk&APPID=7ffedcbb88ebcf7876bc827343f9f05f");
    return app.exec();


}






