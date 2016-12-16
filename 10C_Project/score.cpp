#include "score.h"

#include <QFont>

score::score()
{
    setPlainText("Score: 0");
    setFont(QFont("times", 20));
    setDefaultTextColor(Qt::white);
    num_score = 0;
    stage2_pts = 2;
}

void score::up_score(){
    num_score++;
    if(num_score == stage2_pts){
        emit next_stage();
    }
    str_score = "Score: " + QString::number(num_score);
    setPlainText(str_score);
}
