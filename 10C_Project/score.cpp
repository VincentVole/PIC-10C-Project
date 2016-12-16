#include "score.h"

#include <QFont>

score::score()
{
    setPlainText("Score: 0");
    setFont(QFont("times", 20));
    setDefaultTextColor(Qt::white);
}

void score::chg_text(QString new_score){
    setPlainText(new_score);
}
