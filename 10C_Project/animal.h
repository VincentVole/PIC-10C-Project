#ifndef ANIMAL_H
#define ANIMAL_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QMediaPlayer>

class animal : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    animal();
    void set_image(int cat);
public slots:
    void move();
    void next_stage();
    void mute();
signals:
    void up_score();
    void down_hp();
private:
    QPixmap* image;
    int velocity;
    bool last_animal;
    bool dog;
    bool cleared;
    QMediaPlayer* sfx;
};

#endif // ANIMAL_H
