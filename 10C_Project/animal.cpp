#include "animal.h"
#include "player.h"

#include <QString>
#include <QPixmap>
#include <QTimer>
#include <QList>
#include <QGraphicsItem>
#include <QTime>
#include <ctime>
//#include <cstdlib>
//#include <stdlib.h>

animal::animal()
{
    last_animal = false;
    velocity = 2;
    image = NULL;
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(12);
}
void animal::move(){
    if(y() + velocity < 625 - image->height()){
        setY(y() + velocity);
    }
    else{
        emit down_hp();
        delete this;
        return;
    }
    QList<QGraphicsItem*> collisions = collidingItems();
    for (int i=0, n=collisions.size(); i<n; ++i){
        if(typeid(*(collisions[i]))==typeid(player)){
            emit up_score();
            delete this;
            return;
        }
    }
}

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
