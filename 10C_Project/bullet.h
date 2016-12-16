#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>


class bullet : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    bullet(int x, int y);

public slots:
    void move();

private:
    int velocity;
};

#endif // BULLET_H
