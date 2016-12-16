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
    void set_image(int cat);
public slots:
    void move();
signals:
    void up_score();
    void down_hp();
private:
    QPixmap* image;
    int velocity;
};

#endif // ANIMAL_H
