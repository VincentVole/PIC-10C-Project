#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "alien.h"
#include "animal.h"
#include "player.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    int instructions();
    ~MainWindow();

private slots:
    void on_startButton_clicked();

    void on_instructionButton_clicked();

    void on_backButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
