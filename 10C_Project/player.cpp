#include "player.h"

#include <QString>
#include <QPixmap>
#include <QTimer>
#include <QObject>
#include <QKeyEvent>
player::player()
{
    velocity = 0;
    height = 175;
    QString fileName("C:/Users/ureshineko/Desktop/10C Projects/PIC-10C-Project/10C_Project/Images/Basket Man.png");
    player_image = new QPixmap(fileName);
    *player_image = player_image->scaledToHeight(height);
    width = player_image->width();
    setPixmap(*player_image);

    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(12);
}

player::~player(){

}

void player::move(){
    if((x() + velocity) > -55 && (x() + velocity) < (855 - width)){
        setX(x() + velocity);
    }
}

void player::keyPressEvent(QKeyEvent * event){\
    if(event->key()== Qt::Key_Left){
        velocity += -3;
    }
    else if(event->key()== Qt::Key_Right){
        velocity += 3;
    }
}
void player::keyReleaseEvent(QKeyEvent * event){
    if(event->key()== Qt::Key_Left){
        velocity += 3;
    }
    else if(event->key()== Qt::Key_Right){
        velocity += -3;
    }
}

