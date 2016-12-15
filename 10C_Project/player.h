#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
#include <QKeyEvent>
#include "mainwindow.h"

class player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    player();
    ~player();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
    int height;
    int width;

public slots:
    void move();

private:
    QPixmap* player_image;
    int velocity;
};

#endif // PLAYER_H
