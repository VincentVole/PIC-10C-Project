#ifndef ALIEN_H
#define ALIEN_H

#include <QObject>
#include <QGraphicsPixmapItem>

class alien : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    alien();
};

#endif // ALIEN_H
