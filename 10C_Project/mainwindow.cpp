#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QObject>
#include <QFont>
#include <QString>
#include "player.h"
#include "score.h"
#include "lives.h"

QGraphicsScene* scene;
player* p1;
score* the_score;
lives* hp;
animal* cat;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->instructionText->hide();
    ui->backButton->hide();
    ui->game->hide();
    /*
    QPixmap bkgnd("C:/Users/ureshineko/Desktop/10C Projects/PIC-10C-Project/10C_Project/Images/City Background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    */
}

int MainWindow::instructions(){
    return 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);
    ui->game->setBackgroundBrush(QBrush(QImage("C:/Users/ureshineko/Desktop/10C Projects/PIC-10C-Project/10C_Project/Images/City Background.jpg")));
    ui->game->setScene(scene);
    ui->game->show();
    ui->instructionButton->hide();
    ui->startButton->hide();
    p1 = new player();
    p1->setPos(this->width()/2 - p1->width/2, this->height() - p1->height);
    p1->setFlag(QGraphicsItem::ItemIsFocusable);
    p1->setFocus();
    scene->addItem(p1);
    the_score = new score();
    scene->addItem(the_score);
    QObject::connect(p1, SIGNAL(score_changed(QString)), the_score, SLOT(chg_text(QString)));
    hp = new lives();
    hp->setY(hp->y() + 40);
    scene->addItem(hp);
    QObject::connect(p1, SIGNAL(lives_changed(QString)), hp, SLOT(chg_text(QString)));
    cat = new animal();


}

void MainWindow::on_instructionButton_clicked()
{
    ui->instructionText->show();
    ui->backButton->show();
    ui->instructionButton->hide();
    ui->startButton->hide();
}

void MainWindow::on_backButton_clicked()
{
    ui->instructionText->hide();
    ui->backButton->hide();
    ui->instructionButton->show();
    ui->startButton->show();
}
