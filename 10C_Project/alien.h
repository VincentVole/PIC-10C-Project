#ifndef ALIEN_H
#define ALIEN_H

#include <QObject>
#include <QGraphicsPixmapItem>

class alien : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    alien();
    void set_image(int cat);
public slots:
    void move();
signals:
    void down_hp();
    void up_score();
private:
    QPixmap* image;
    int velocity;
};

#endif // ALIEN_H
