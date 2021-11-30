//
// Created by nolan on 2021-11-27.
//

#ifndef MAGIC_MIRROR_NEWSWIDGET_H
#define MAGIC_MIRROR_NEWSWIDGET_H

#include "../../Utils/ClickableLabel.h"
#include "../APIRequest.h"
#include "../articleData.h"

#include <unistd.h>
#include <iostream>
#include <QWidget>
#include <QJsonArray>
#include <QTimer>
#include <QPixmap>
#include <QLabel>
#include <QTextEdit>
#include <QVector>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDesktopServices>


class NewsWidget : public QWidget{
    Q_OBJECT

public:
    NewsWidget();
    ~NewsWidget();

private slots:
    void scrollNews();
    void headlineClicked();

private:
    APIRequest *newsApi;
    int storiesIndex;
    QHBoxLayout *hbox;
    QVBoxLayout *vbox;
    QVector<articleData> headlines;
    QTextEdit *storyDescription;
    QPixmap *newsImage;
    QLabel *storyImage;
    ClickableLabel *newsLabel;
};


#endif //MAGIC_MIRROR_NEWSWIDGET_H
