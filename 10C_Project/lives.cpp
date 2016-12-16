#include "lives.h"

#include <QFont>

lives::lives()
{
    setPlainText("Lives: 3");
    setFont(QFont("times", 20));
    setDefaultTextColor(Qt::white);
}

void lives::chg_text(QString new_lives){
    setPlainText(new_lives);
}

