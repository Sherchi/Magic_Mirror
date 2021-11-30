//
// Created by nolan on 2021-11-27.
//

/*
 * @brief This class handles the initialization of APIRequest class.
 *
 * This class is used to initialize and configure all the settings in order to use the APIRequest class. This will pull
 * the headlines, the pictures, descriptions and the links to articles.
 *
 * @authors Nolan Morris, Darwin Shiyi Liao.
 * */
#include "NewsWidget.h"

/* @brief Constructor for the class.
 *
 * The constructor initializes and configures all the settings for the APIRequest class and configures the GUI elements.
 * It will store all the data in a vector so that it can be used.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Darwin Shyi Liao.
 * */
NewsWidget::NewsWidget() {
    storiesIndex = 0;
    vbox = new QVBoxLayout;
    hbox = new QHBoxLayout;
    storyImage = new QLabel;
    newsLabel = new ClickableLabel;
    storyDescription = new QTextEdit;
    storyDescription->setReadOnly(true);

    vbox->setSpacing(10);
    hbox->setSpacing(10);

    this->setLayout(hbox);
    vbox->addWidget(newsLabel);
    vbox->addWidget(storyDescription);

    hbox->addWidget(storyImage);
    hbox->addLayout(vbox);

    newsApi = new APIRequest;

    newsApi->get("https://gnews.io/api/v4/top-headlines?&lang=en&country=ca&max=10&token=9aadf377ffbec1aa1d09e593b43262c5");

    for(int i = 0; i < 10; i++){
        sleep(1);
        if(newsApi->isDone() == 1){
            break;
        }
    }

    QJsonArray storiesArray = newsApi->getJsonArr();

    for(int i = 0; i < 10; i++){
        articleData article(storiesArray[i].toObject());
        headlines.append(article);
    }

    connect(newsLabel, SIGNAL(clicked()), this, SLOT(headlineClicked()));

    QTimer *timer = new QTimer(this); //creates a timer so that the news stories will scoll after a set amount of time
    connect(timer, SIGNAL(timeout()), this, SLOT(scrollNews()));
    timer->start(15000);

    scrollNews(); //draws the first story so that we can skip waiting for the timer
}

/*
 * @brief This function changes the news story that is being shown to the user
 *
 * This function is responsible for updating the story that is being displayed to the user after a certain amount of
 * time. It will cycle the array that contains the stories information forever so that the user has a chance to see a
 * story again if they miss it the first time.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Darwin Shiyi Liao
 * */

void NewsWidget::scrollNews() {
    newsImage = headlines[storiesIndex].getPixmap();
    storyImage->setPixmap(newsImage->scaled(200, 200, Qt::KeepAspectRatio));

    newsLabel->setText(headlines[storiesIndex].getTitle());

    auto font = new QFont(); //configures the font for the headline
    font->setPointSize(14);
    newsLabel->setFont(*font);

    storyDescription->setFontPointSize(14);
    storyDescription->setText(headlines[storiesIndex].getDesc());
    storyDescription->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
    storyDescription->setStyleSheet("background-color : rgba(0,0,0,0%); color : black");

    storiesIndex++;
    if(storiesIndex == headlines.size()){
        storiesIndex = 0;
    }
}

/*
 * @brief Opens the news article in the browser when the user clicks on the story with the APIRequest class.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Darwin Shiyi Liao.
 * */
void NewsWidget::headlineClicked() {
    std::cout << "Headline clicked" << std::endl;
    QUrl url = headlines[storiesIndex].getURL();
    QDesktopServices::openUrl(url);
}

/*
 * @brief Destructor for the class.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Darwin Shiyi Liao.
 * */
NewsWidget::~NewsWidget() noexcept {
    delete newsApi;
    delete hbox;
    delete vbox;
    delete storyDescription;
    delete newsImage;
    delete storyImage;
    delete newsLabel;
}