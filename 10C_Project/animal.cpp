#include "animal.h"
#include "player.h"

#include <QString>
#include <QPixmap>
#include <QTimer>
#include <QList>
#include <QGraphicsItem>
#include <QTime>
#include <ctime>
#include "bullet.h"

animal::animal()
{
    //sets some default values
    last_animal = false;
    velocity = 2;
    image = NULL;

    //creates timer to move animal object
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(12);
}
void animal::move(){
    if(y() + velocity < 625 - image->height()){//will move animal down unless it will go off screen
        setY(y() + velocity);
    }
    else{//if it will be off screen, delete it and decrease number of lives by 1
        emit down_hp();
        delete this;
        return;
    }
    QList<QGraphicsItem*> collisions = collidingItems();
    for (int i=0, n=collisions.size(); i<n; ++i){
        if(typeid(*(collisions[i]))==typeid(player)){//delete if collides with player and increase score by 1
            emit up_score();
            delete this;
            return;
        }
        if(typeid(*(collisions[i]))==typeid(bullet)){//delete if collides with bullet, decrease number of lives by 1, and delete the colliding bullet
            emit down_hp();
            delete collisions[i];
            delete this;
            return;
        }
    }
}

//takes in a random number of either 1 or 0. if 1 the animal is a cat. if 0 the animal is a dog
void animal::set_image(int cat){
    if(cat == 1 ){
        QString fileName(":/images/Images/Cat Head.png");
        image = new QPixmap(fileName);
        *image = image->scaledToHeight(150);
        setY(-1 * image->height());
        setPixmap(*image);
    }
    else{
        QString fileName(":/images/Images/Dog Head.png");
        image = new QPixmap(fileName);
        *image = image->scaledToHeight(150);
        setY(-1 * image->height());
        setPixmap(*image);
    }
}

//deletes remaining animals once score goal for stage1 is hit if the object isn't already being deleted for player collision
void animal::next_stage(){
    QList<QGraphicsItem*> collisions = collidingItems();
    for (int i=0, n=collisions.size(); i<n; ++i){
        if(typeid(*(collisions[i]))==typeid(player)){
            last_animal = true;
        }
    }
    if(last_animal == false){
        delete this;
        return;
    }
}
