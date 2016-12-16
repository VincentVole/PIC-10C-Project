#include "alien.h"

#include <QTimer>
#include <QUrl>
#include "bullet.h"

alien::alien()
{
    //sets some default values
    image = NULL;
    velocity = 2;
    cleared = false;

    //media player for alien sound effects
    sfx = new QMediaPlayer();

    //creates timer to move alien
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(12);
}

void alien::move(){
    if(y() + velocity < 625 - image->height()){//moves alien down until it gets to the bottom of the screen
        setY(y() + velocity);
    }

    else{//deletes once it hits the bottom and decrements health total
        emit down_hp();
        sfx->setMedia(QUrl("qrc:/sound/Sound/splat.mp3"));
        if(cleared){
            sfx->setVolume(0);
        }
        else{
            sfx->setVolume(50);
        }
        sfx->play();
        delete this;
        return;
    }
    //deletes self and increments score if collides with bullet, as well as deletes colliding bullet
    QList<QGraphicsItem*> collisions = collidingItems();
    for (int i=0, n=collisions.size(); i<n; ++i){
        if(typeid(*(collisions[i]))==typeid(bullet)){
            emit up_score();
            sfx->setMedia(QUrl("qrc:/sound/Sound/splat.mp3"));
            if(cleared){
                sfx->setVolume(0);
            }
            else{
                sfx->setVolume(50);
            }
            sfx->play();
            delete collisions[i];
            delete this;
            return;
        }
    }
}

//passed random int of 1 or 0. if 1 the alien is a cat alien, if 0 the alien is a dog alien
void alien::set_image(int cat){
    if(cat == 1 ){
        QString fileName(":/images/Images/Alien Cat Head.png");
        image = new QPixmap(fileName);
        *image = image->scaledToHeight(150);
        setY(-1 * image->height());
        setPixmap(*image);
    }
    else{
        QString fileName(":/images/Images/Alien Dog Head.png");
        image = new QPixmap(fileName);
        *image = image->scaledToHeight(150);
        setY(-1 * image->height());
        setPixmap(*image);
    }
}

void alien::mute(){
    cleared = true;
}
