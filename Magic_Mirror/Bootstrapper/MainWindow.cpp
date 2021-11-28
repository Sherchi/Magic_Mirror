/*
 * @brief This class brings all of the widgets together into a single window.
 *
 * This class uses all of the other widgets and draws them to the screen over the camera feed.
 *
 * @authors Nolan Morris.
 *
*/
#include "MainWindow.h"

/*
 * @brief Constructor of the class
 *
 * This constructor initializes all of the widgets needed for the overlay and the camera feed.
 * It also initializes other variables such as the dimensions of the screen for dynamic sizing determined at run time
 * and the stories index used to scroll the news stories at the bottom of the overlay.
 *
 * @param screenWidth Screen Width pulled from the Qapplication.
 * @param screenHeight Screen Height pulled from the Qapplication.
 * @param parent A null parent widget.
 *
 * @return No return.
 *
 * @authors Nolan Morris.
 *
 */
MainWindow::MainWindow(int screenWidth, int screenHeight, QWidget *parent) : QMainWindow(parent){

    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    gridLayout = new QGridLayout;

    scene = new QGraphicsScene(); //initalizes the scene size to an arbitrary size for testing purposes
    scene->setSceneRect(0, 0, screenWidth, screenHeight);
    view = new QGraphicsView;

    view->setScene(scene);
    setCentralWidget(view);
}

/*
 * @brief Calls all individual configuration methods and starts the updater class
 *
 * This function will call all of the configure functions for each of the widgets. It will also configure the graphics sceene
 * to allow for the widgets to be placed overtop of the camera feed. Finally it is also responsible for calling the
 * update() function which is responsible for reconfiguring and updating the widgets after a set amount of time in order
 * to ensure the information being displayed is up to date.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris.
 *
 * */
void MainWindow::configure(){
    configureWeather();
    configureNews();
    configureClock();
    configureCalendar();
    configureUserSystem();
    configureCamera();

    //this needs to go after configureCamera() otherwise the camera feed goes over the overlay
    QWidget *overlay = new QWidget;
    overlay->setLayout(gridLayout); //passes the layout to a generic QWidget
    overlay->setFixedSize(this->screenWidth, this->screenHeight); //this works
    overlay->setAttribute(Qt::WA_TranslucentBackground); //makes the background translucent so that the camera can be seen underneath
    QGraphicsProxyWidget *proxyWidget = scene->addWidget(overlay); //adds that widget to the QGraphicsScene

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updater()));
    timer->start(1800000); //updates every half hour
}

/*
 * @brief Updates each of the widgets after a set amount of time.
 *
 * This function is responsible for reconfiguring the widgets that need to updated after a set amount of time to ensure
 * the information being displayed is up to date.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris.
 *
 * */
void MainWindow::updater() { //reconfigures both the weather and the news widgets in order to update them
    configureWeather();
    configureNews();
    std::cout << "All modules updated" << std::endl;
}

/*
 * @brief This function is responsible for configuring the weather widget.
 *
 * This function will configure a WeatherWidget to display weather information to the user. It will show both the
 * current weather conditions and the current temperature.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Nathan Dinatale.
 *
 * */
void MainWindow::configureWeather() {
    weather = new WeatherWidget;
    gridLayout->addWidget(weather, 0, 0);
}

/*
 * @brief This function is responsible for configuring the news widget.
 *
 * This function will configure a NewsWidget to display the news information to the user. It will show a brief
 * description of the article, the headline, and the image associated with the article.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Darwin Shiyi Liao.
 * */
//TODO clickability of the news articles
void MainWindow::configureNews(){ //we can use the news object and have a thing where we return an accumulation of headlines
    newsWidget = new NewsWidget;
    gridLayout->addWidget(newsWidget, 2, 1, Qt::AlignBottom);
}

/*
 * @brief This function is responsible for configuring the camera feed
 *
 * This function will use a Camera object to get a camera feed from the users webcam and display it with the correct
 * screen sizes so that the camera is the entire background of the widget.
 *
 * @param No parametrs.
 *
 * @return No return.
 *
 * @authors Nolan Morris.
 * */
void MainWindow::configureCamera() {
    camera = new Camera(screenWidth, screenHeight);
    //we can use row 0, column 1 in the grid layout for testing purposes for now
    scene->addItem(camera->getVideoItem());
}

/*
 * @brief This function is responsible for configuring the clock
 *
 * This funciton will use a ClockWidget object to display the current date and time to the user. It will also update
 * every second.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Yifei Zhang.
 * */
void MainWindow::configureClock() { //configures the digital clock
    clockWidget = new ClockWidget();
    gridLayout->addWidget(clockWidget, 1, 2, Qt::AlignRight);
}

/*
 * @brief This function is responsible for displaying the calendar to the user
 *
 * This function will configure the calendarWidget to display the calendar to the user that they can use to see the
 * current date.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Yifei Zhang.
 * */
void MainWindow::configureCalendar(){ //responsible for drawing the calendar to the screen
    calendarWidget = new CalendarWidget();
    gridLayout->addWidget(calendarWidget, 2, 2, Qt::AlignRight);
}

/*
 * @brief This function is responsible for displaying the account icon to the user
 *
 * This function will configure the userSystemWidget to display the account icon that the user can use to login to their
 * account.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Peter Nicholaas Meijer.
 * */
//TODO Change the files paths in the userSystem class to relative paths before using qmake
void MainWindow::configureUserSystem() {
    //use 0, 2 for the position of the image
    userSystemWidget = new UserSystemWidget;
    gridLayout->addWidget(userSystemWidget, 0, 2, Qt::AlignRight);
}

/*
 * @brief Destructor for the class
 *
 * This will release the memory for any global variables that are used in this class.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris.
 * */
MainWindow::~MainWindow(){
    delete newsWidget;
    delete clockWidget;
    delete calendarWidget;
    delete weather;
    camera->stop();
    delete camera;
    delete gridLayout;
}
