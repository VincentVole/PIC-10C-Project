#ifndef ANIMAL_H
#define ANIMAL_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class animal : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    animal();
private:
    QPixmap* image;
};

#endif // ANIMAL_H
