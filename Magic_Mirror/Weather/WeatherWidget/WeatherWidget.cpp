//
// Created by nolan on 2021-11-27.
//

/*
 * @brief This class implements all the necessary elements to draw the weather information to the screen.
 *
 * @authors Nolan Morris, Nathan Dinatale.
 * */
#include "WeatherWidget.h"

/*
 * @brief Constructor for the class. Initializes all the GUI elements and the getWeather class. It also handles changing
 * the units of the current temperature on click.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Nathan Dinatale.
 * */
WeatherWidget::WeatherWidget() {
    mainVbox = new QVBoxLayout;
    mainVbox->setSpacing(0);
    mainVbox->setMargin(0);
    hbox = new QHBoxLayout;
    this->setLayout(mainVbox);

    weather = new getWeather; //creating and accessing weather module
    weather->fetchWeather("7ffedcbb88ebcf7876bc827343f9f05f", "London, ca");
    weather->fetchForecast("7ffedcbb88ebcf7876bc827343f9f05f", "London, ca");

    QString imageName = parseWeather(weather->getWeatherDescription());
    QString temperature = QString::number(weather->getTemperature());

    image = new QPixmap;
    image->load(QString::fromStdString(std::filesystem::current_path()) + "/Bootstrapper/Images/" + imageName + ".png"); //loads the image from the URL

    imageLabel = new QLabel;
    imageLabel->setPixmap(image->scaled(250, 250, Qt::KeepAspectRatio)); //scales the image so that it doesn't take up the whole window

    temp = new ClickableLabel;
    temp->setText((temperature + " C"));

    auto font = new QFont();
    font->setPointSize(72);
    temp->setFont(*font);

    connect(temp, SIGNAL(clicked()), this, SLOT(changeUnits()));

    hbox->addWidget(imageLabel);
    hbox->addWidget(temp);
    hbox->addStretch(); //changes the spacing between elements in this layout
    hbox->setSpacing(10);

    mainVbox->addLayout(hbox);

    auto *futureForecastHbox = new QHBoxLayout;

    futureForecastHbox->setSpacing(5);
    futureForecastHbox->setAlignment(Qt::AlignLeft);

    QVector<QString> descriptions = weather->getForecastDescriptions();
    QVector<double> minTemps = weather->getForecastTempMins();
    QVector<double> maxTemps = weather->getForecastTempMaxes();

    for(int i = 0; i < descriptions.size(); i++){
        auto *vbox = new QVBoxLayout;
        auto *minTemp = new QLabel();
        auto *maxTemp = new QLabel();
        auto *weatherPixmap = new QPixmap;
        auto *pixmapLabel = new QLabel;

        QString descriptionImage = parseWeather(descriptions[i]);

        weatherPixmap->load(QString::fromStdString(std::filesystem::current_path()) + "/Bootstrapper/Images/" + descriptionImage + ".png");
        pixmapLabel->setPixmap(weatherPixmap->scaled(75, 75, Qt::KeepAspectRatio));

        minTemp->setText(QString::number(minTemps[i]) + " C");
        maxTemp->setText(QString::number(maxTemps[i]) + " C");

        vbox->addWidget(pixmapLabel, Qt::AlignLeft);
        vbox->addWidget(maxTemp, Qt::AlignLeft);
        vbox->addWidget(minTemp, Qt::AlignLeft);
        vbox->setAlignment(Qt::AlignLeft);

        futureForecastHbox->addLayout(vbox);
    }

    mainVbox->addLayout(futureForecastHbox);
}

/*
 * @brief updates the temperature label with the change in units.
 *
 * @param No parameters.
 *
 * @return No return.
 *
 * @authors Nolan Morris, Nathan Dinatale.
 * */
void WeatherWidget::changeUnits() {
    temp->setText(weather->convert(temp->text()));
}


/*
 * @brief parses the description of the weather from the API to one of the images in the file system that can be
 * displayed on screen.
 *
 * @param description Takes the description of the weather directly from  API.
 *
 * @return imageName Returns an image name associated with one of the file names in the Images folder.
 *
 * @authors Nolan Morris, Nathan Dinatale.
 * */
QString WeatherWidget::parseWeather(QString description) {
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

/*
 * @brief Destructor for the class.
 *
 * @params No parameters.
 *
 * @return No returns.
 *
 * @authors Nolan Morris, Nathan Dinatale.
 * */
WeatherWidget::~WeatherWidget() noexcept {

}