#ifndef LIVES_H
#define LIVES_H

#include <QObject>
#include <QGraphicsTextItem>
#include <QString>


class lives : public QGraphicsTextItem, public QObject
{
    Q_OBJECT
public:
    lives();
public slots:
    void down_hp();
signals:
    void hp_zero();
private:
    int num_lives;
    QString str_lives;
};

#endif // LIVES_H
