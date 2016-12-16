#include "lives.h"

#include <QFont>

lives::lives()
{
    setPlainText("Lives: 3");
    setFont(QFont("times", 20));
    setDefaultTextColor(Qt::white);
    num_lives = 3;
}

void lives::down_hp(){
    num_lives--;
    if(num_lives == 0){
        emit hp_zero();
        return;
    }
    str_lives = "Lives: " + QString::number(num_lives);
    setPlainText(str_lives);
}
