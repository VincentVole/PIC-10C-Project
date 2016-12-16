#ifndef LIVES_H
#define LIVES_H

#include <QObject>
#include <QGraphicsTextItem>


class lives : public QGraphicsTextItem, public QObject
{
    Q_OBJECT
public:
    lives();
public slots:
    void chg_text(QString new_lives);
};

#endif // LIVES_H
