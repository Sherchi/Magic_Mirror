//
// Created by nolan on 2021-11-03.
//
#include "MainWindow.h"

int storiesIndex = 0;

MainWindow::MainWindow(int screenWidth, int screenHeight, QWidget *parent) : QMainWindow(parent){
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;

    gridLayout = new QGridLayout;
    newsApi = new APIRequest;
    newsLabel = new QLabel("");
    storiesIndex = 0;
    scene = new QGraphicsScene(0, 0, screenWidth, screenHeight); //initalizes the scene size to an arbitrary size for testing purposes
    view = new QGraphicsView;

    view->setScene(scene);
    setCentralWidget(view);
}

void MainWindow::start(){
    updater();
}

void MainWindow::configure(){

    configureWeather();
//    configureNews();
    configureClock();
    configureCalendar();
    configureCamera();

    //this needs to go after configureCamera() otherwise the camera feed goes over the overlay
    QWidget *overlay = new QWidget;
    overlay->setLayout(gridLayout); //passes the layout to a generic QWidget
    overlay->setFixedSize(this->screenWidth, this->screenHeight); //this works
    overlay->setAttribute(Qt::WA_TranslucentBackground); //makes the background translucent so that the camera can be seen underneath
    QGraphicsProxyWidget *proxyWidget = scene->addWidget(overlay); //adds that widget to the QGraphicsScene

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updater()));
    timer->start(10000);
}

void MainWindow::updater() {
    updateWeather();
    updateNews();
    updateCalendar();
    std::cout << "All modules updated" << std::endl;
}

void MainWindow::configureWeather() {
    auto *hbox = new QHBoxLayout;

    weather = new getWeather; //creating and accessing weather module
    weather->fetchWeather("http://api.openweathermap.org/data/2.5/weather?q=London,uk&APPID=7ffedcbb88ebcf7876bc827343f9f05f");

    QString imageName = parseWeather(weather->getWeatherDescription());
    QString temperature = QString::number(weather->getTemperature());

    auto *image = new QPixmap;
    image->load("/home/nolan/CLionProjects/Magic Mirror/Magic_Mirror/Bootstrapper/Images/" + imageName + ".png"); //loads the image from the URL
    auto *imageLabel = new QLabel;
    imageLabel->setPixmap(image->scaled(250, 250, Qt::KeepAspectRatio)); //scales the image so that it doesn't take up the whole window

    auto temp = new QLabel((temperature + " C"));
    auto font = new QFont();
    font->setPointSize(72);
    temp->setFont(*font);


    hbox->addWidget(imageLabel);
    hbox->addWidget(temp);
    hbox->addStretch(); //changes the spacing between elements in this layout
    hbox->setSpacing(10);

    gridLayout->addLayout(hbox, 0, 0);
}

void MainWindow::updateWeather() {

}

//TODO: Move this function to the weather class and have it return this. This doesn't need to be here
QString MainWindow::parseWeather(QString description) { //responsible for handling the weather descriptions
    QString imageName;
    //returns the name of an image that can be used to show the weather
    if((QString::compare(description, "clear", Qt::CaseInsensitive) == 0)){
        if(QTime::currentTime() > QTime(18,00,00,00)){
            imageName = "Night";
            return imageName;
        }
        else{
            imageName = "Sunny";
            return imageName;
        }
    }
    else if((QString::compare(description, "drizzle", Qt::CaseInsensitive) == 0)){
        imageName = "Drizzle";
        return imageName;
    }
    else if((QString::compare(description, "clouds", Qt::CaseInsensitive) == 0)){
        imageName = "Cloudy";
        return imageName;
    }
    else if((QString::compare(description, "rain", Qt::CaseInsensitive) == 0)){
        imageName = "Raining";
        return imageName;
    }
    else if((QString::compare(description, "thunderstorm", Qt::CaseInsensitive) == 0)){
        imageName = "Thunderstorm";
        return imageName;
    }
    else if((QString::compare(description, "snow", Qt::CaseInsensitive) == 0)){
        imageName = "Snowing";
        return imageName;
    }
    else { //anything else here should just be classified as foggy since that can be used for all of the possible atmosphere conditions
        imageName = "Foggy";
        return imageName;
    }
}

void MainWindow::configureNews(){ //we can use the news object and have a thing where we return an accumulation of headlines
    newsApi->get("https://gnews.io/api/v4/top-headlines?&lang=en&country=ca&max=10&token=9aadf377ffbec1aa1d09e593b43262c5");

    QJsonArray storiesArray = newsApi->getJsonArr();

    for(int i = 0; i < 10; i++){
        articleData article(storiesArray[i].toObject());
        headlines.append(article);
    }

    QTimer *timer = new QTimer(this); //creates a timer so that the news stories will scoll after a set amount of time
    connect(timer, SIGNAL(timeout()), this, SLOT(scrollNews()));
    timer->start(5000);

    scrollNews(); //draws the first story so that we can skip waiting for the timer
}

void MainWindow::scrollNews(){ //handles the scrolling of the news headlines
    newsLabel->setText(headlines[storiesIndex].getTitle());

    auto font = new QFont();
    font->setPointSize(14);
    newsLabel->setFont(*font);

    gridLayout->addWidget(newsLabel, 1, 1);
    storiesIndex++;
    if(storiesIndex == headlines.size()){
        storiesIndex = 0;
    }
}

void MainWindow::updateNews(){

}

void MainWindow::configureCamera() {
    camera = new Camera(screenWidth, screenHeight);
    //we can use row 0, column 1 in the grid layout for testing purposes for now
    scene->addItem(camera->getVideoItem());
}

void MainWindow::configureClock() { //configures the digital clock
    clock = new clk::Clock();
    timeLabel = new QLabel("");

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);

    showTime(); //draws the inital clock so that we can skip waiting for the timer
}

void MainWindow::showTime(){ //responsible for drawing the time to the screen
    clock->update();
    timeLabel->setText(clock->getStrTime());

    auto font = new QFont();
    font->setPointSize(20);
    timeLabel->setFont(*font);

    gridLayout->addWidget(timeLabel, 0, 2);
}

void MainWindow::configureCalendar(){ //responsible for drawing the calendar to the screen
    auto calendar = new QCalendarWidget();
    calendar->setMinimumDate(QDate(2000, 1, 1));
    calendar->setMaximumDate(QDate(2050, 1, 1));

    calendar->setMaximumHeight(500);
    calendar->setMaximumWidth(500);

    calendar->setStyleSheet("background-color:grey");

    gridLayout->addWidget(calendar, 1, 2);
}

void MainWindow::updateCalendar() {

}

QGridLayout* MainWindow::getLayout() {
    return gridLayout;
}

MainWindow::~MainWindow(){
    delete newsLabel;
    delete newsApi;
    delete weather;
    delete clock;
    delete timeLabel;
    camera->stop();
    delete camera;
    delete gridLayout;
}
