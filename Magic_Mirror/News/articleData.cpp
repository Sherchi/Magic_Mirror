//
// Created by darwin on 2021-11-06.
//

#include <iostream>
#include "articleData.h"
#include "imgDownloader.h"

/**
 * @brief Default Constructor
 * @param none
 * @return none
 * @author Darwin Liao
 */
articleData::articleData() = default;


/**
 * @brief Constructor for the articleData Object.
 * @paragraph Takes in the QJsonObject of the news article and assigns
 *            the information to their respective variables.
 *
 *            Also Creates an ImgDownloader to download the
 *            Image from the URL.
 *
 * @param QJsonObject Data
 * @return none
 * @author Darwin Liao
 */
articleData::articleData(QJsonObject data) {
    rawData = data;
    title = data.value("title").toString();
    desc = data.value("description").toString();
    content = data.value("content").toString();
    url = data.value("url").toString();
    img = data.value("image").toString();
    imgDownloader downloader;
    downloader.download(img);
    imgPM = downloader.getPixmap();

}

/**
 * @Brief Deconstructor
 * @paragraph Doesn't really do anything but sit here and look cool
 *            Was made in the case that it is needed later, but no
 *            issues arised/was not needed.
 * @return None
 * @author Darwin Liao
 */
articleData::~articleData() {
    ;
}

/**
 * @brief returns the content of the article
 * @return QString
 * @Author Darwin Liao
 */
QString articleData::getContent() {
    return content;
}

/**
 * @brief returns the short Description of the article
 * @return QString
 * @Author Darwin Liao
 */QString articleData::getDesc() {
    return desc;

}

/**
 * @brief returns the image URL of the article
 * @return QString
 * @Author Darwin Liao
 */QString articleData::getImageURL(){
    return img;
}

/**
 * @brief returns the image pixMap that was
 *        retrived from the downloader of the article
 * @return QPixmap
 * @Author Darwin Liao
 */
QPixmap* articleData::getPixmap() {
    return &imgPM;
}

/**
 * @brief returns the Title of the article
 * @return QString
 * @Author Darwin Liao
 */
QString articleData::getTitle(){
    return title;
}

/**
 * @brief returns the URL of the article
 * @return QString
 * @Author Darwin Liao
 */QString articleData::getURL() {
    return url;
}


