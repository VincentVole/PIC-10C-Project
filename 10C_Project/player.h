#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
#include <QKeyEvent>
#include <QString>
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

signals:
    void score_changed(QString score);
    void lives_changed(QString lives);

private:
    QPixmap* player_image;
    int score;
    int lives;
    int velocity;
    QString str_score;
    QString str_lives;
};

#endif // PLAYER_H
