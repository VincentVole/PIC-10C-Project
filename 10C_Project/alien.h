#ifndef ALIEN_H
#define ALIEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

class alien : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    alien();
    void set_image(int cat);
public slots:
    void move();
    void mute();
signals:
    void down_hp();
    void up_score();
private:
    QPixmap* image;
    QMediaPlayer* sfx;
    int velocity;
    bool cleared;
};

#endif // ALIEN_H
