#ifndef SCORE_H
#define SCORE_H

#include <QObject>
#include <QGraphicsTextItem>
#include <QString>


class score : public QGraphicsTextItem, public QObject
{
    Q_OBJECT
public:
    score();
public slots:
    void up_score();
private:
    QString str_score;
    int num_score;
};

#endif // SCORE_H
