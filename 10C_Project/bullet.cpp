#include "bullet.h"

#include <QBrush>
#include <QTimer>
#include <QList>
#include <QGraphicsItem>
#include "animal.h"

bullet::bullet(int x, int y)
{
    //the bullet is just a colored rectangle
    setRect(x-5,y,10,30);
    setBrush(* new QBrush(Qt::blue));

    velocity = -5;

    //creates timer to move bullet
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(12);
}

//moves the bullet
void bullet::move(){
    setY(y() + velocity);
    if(y() < -450){//destroys bullet if it goes off screen. Destruction due to collision is handled by alien and animal classes
        delete this;
        return;
    }
}
