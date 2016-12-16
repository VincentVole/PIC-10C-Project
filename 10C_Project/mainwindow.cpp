#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QObject>
#include <QFont>
#include <QString>
#include <QTimer>
#include <QTime>
#include <QMediaPlayer>
#include <QUrl>
#include <QGraphicsRectItem>
#include <QBrush>
#include "player.h"
#include "score.h"
#include "lives.h"
#include "bullet.h"

QGraphicsScene* scene;
player* p1;
score* the_score;
lives* hp;
QTimer* timer;
QMediaPlayer* bgm;
QGraphicsRectItem* cover;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->instructionText->hide();
    ui->backButton->hide();
    ui->game->hide();
    ui->stage2_instructions->hide();
    ui->nextButton->hide();
    ui->game_over_text->hide();
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
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
    ui->game->setBackgroundBrush(QBrush(QImage(":/images/Images/City Background.jpg")));
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
    hp = new lives();
    hp->setY(hp->y() + 40);
    scene->addItem(hp);
    scene->addItem(the_score);

    spawn_speed = 1250;
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(spawn_animal()));
    timer->start(spawn_speed);
    QObject::connect(hp, SIGNAL(hp_zero()), this, SLOT(game_over()));

    QObject::connect(the_score, SIGNAL(next_stage()), this, SLOT(next_stage()));

    bgm = new QMediaPlayer();
    bgm->setMedia(QUrl("qrc:/sound/Sound/05 Come and Find Me.mp3"));
    bgm->setVolume(40);
    bgm->play();
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

void MainWindow::spawn_animal(){
    animal* rand_animal = new animal();
    rand_animal->setX((qrand() % 670) - 12);
    rand_animal->set_image(qrand() % 2);
    scene->addItem(rand_animal);
    QObject::connect(rand_animal, SIGNAL(up_score()), the_score, SLOT(up_score()));
    QObject::connect(rand_animal, SIGNAL(down_hp()), hp, SLOT(down_hp()));
    QObject::connect(the_score, SIGNAL(next_stage()), rand_animal, SLOT(next_stage()));
}

void MainWindow::next_stage(){
    timer->stop();
    bgm->stop();
    bgm->setMedia(QUrl("qrc:/sound/Sound/06 Searching.mp3"));
    cover = new QGraphicsRectItem();
    cover->setRect(-20,-20,840,640);
    cover->setBrush(* new QBrush(Qt::white));
    scene->addItem(cover);
    ui->stage2_instructions->show();
    ui->nextButton->show();
}

void MainWindow::game_over(){
    delete ui->game;
    ui->game_over_text->show();
}

void MainWindow::on_nextButton_clicked()
{
    ui->stage2_instructions->hide();
    ui->nextButton->hide();
    scene->removeItem(cover);
    delete cover;
    bgm->play();
    timer->start();
}

void MainWindow::bullet_fired(int x, int y){

}
