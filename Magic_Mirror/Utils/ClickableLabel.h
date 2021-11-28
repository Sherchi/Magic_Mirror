//
// Created by nolan on 2021-11-27.
//

#ifndef MAGIC_MIRROR_CLICKABLELABEL_H
#define MAGIC_MIRROR_CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>

class ClickableLabel : public QLabel{
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    ~ClickableLabel();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* click);

};


#endif //MAGIC_MIRROR_CLICKABLELABEL_H
