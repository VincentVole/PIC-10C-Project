#ifndef SCORE_H
#define SCORE_H

#include <QObject>
#include <QGraphicsTextItem>


class score : public QGraphicsTextItem, public QObject
{
    Q_OBJECT
public:
    score();
public slots:
    void chg_text(QString new_score);
};

#endif // SCORE_H
