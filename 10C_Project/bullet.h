#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>


class bullet : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    bullet(int x, int y);
};

#endif // BULLET_H
