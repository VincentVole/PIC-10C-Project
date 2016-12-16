#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QMediaPlayer>


class bullet : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    bullet(int x, int y);

public slots:
    void move();

private:
    QMediaPlayer* sfx;
    int velocity;
};

#endif // BULLET_H
