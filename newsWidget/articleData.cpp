//
// Created by darwin on 2021-11-06.
//

#include "articleData.h"

//Default Constructor
articleData::articleData() = default;


//Init the values from the Json Object given.
//Should have all those values.
articleData::articleData(QJsonObject data) {
    rawData = data;
    title = data.value("title").toString();
    desc = data.value("description").toString();
    content = data.value("content").toString();
    url = data.value("url").toString();
    img = data.value("image").toString();

}

//Returns Content
QString articleData::getContent() {
    return content;
}

//Returns Description
QString articleData::getDesc() {
    return desc;

}

//Returns PreviewImage URL
QString articleData::getImage() {
    return img;
}

//Returns Title
QString articleData::getTitle(){
    return title;
}

//Returns URL of Article
QString articleData::getURL() {
    return url;
}


