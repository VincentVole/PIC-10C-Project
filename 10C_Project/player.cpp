#include "player.h"

#include <QString>
#include <QPixmap>
#include <QTimer>
#include <QObject>
#include <QKeyEvent>
player::player()
{
    //sets some default values
    stage2 = false;
    velocity = 0;
    height = 175;

    //sets image of player to basket man
    QString fileName(":/images/Images/Basket Man.png");
    player_image = new QPixmap(fileName);
    *player_image = player_image->scaledToHeight(height);
    width = player_image->width();
    setPixmap(*player_image);

    //creates timer to move player
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(12);
}

player::~player(){

}

//moves player left or right
void player::move(){
    if((x() + velocity) > -55 && (x() + velocity) < (855 - width)){
        setX(x() + velocity);
    }
}

//gives player velocity in either direction depending on which key pressed
void player::keyPressEvent(QKeyEvent * event){\
    if(event->key()== Qt::Key_Left){
        velocity += -3;
    }
    else if(event->key()== Qt::Key_Right){
        velocity += 3;
    }
    else if(event->key()== Qt::Key_Space){//fires bullet when space is pressed during stage2
        if(stage2){
            emit bullet_fired((x() + player_image->width()/2), y());
        }
    }
}

//takes away player velocity depending on which key was previously pressed
void player::keyReleaseEvent(QKeyEvent * event){
    if(event->key()== Qt::Key_Left){
        velocity += 3;
    }
    else if(event->key()== Qt::Key_Right){
        velocity += -3;
    }

}

