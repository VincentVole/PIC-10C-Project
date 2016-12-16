#include "score.h"

#include <QFont>

score::score()
{
    setPlainText("Score: 0");
    setFont(QFont("times", 20));
    setDefaultTextColor(Qt::white);
    num_score = 0;
}

void score::up_score(){
    num_score++;
    str_score = "Score: " + QString::number(num_score);
    setPlainText(str_score);
}
