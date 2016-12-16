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
#include "animal.h"
#include "alien.h"


QGraphicsScene* scene;
player* p1;
score* the_score;
lives* hp;
QTimer* timer;
QMediaPlayer* bgm;
QGraphicsRectItem* cover;
bool stage2;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //hides a bunch of stuff
    ui->instructionText->hide();
    ui->backButton->hide();
    ui->game->hide();
    ui->stage2_instructions->hide();
    ui->nextButton->hide();
    ui->game_over_text->hide();

    //sets the seed for random numbers for the rest of the program
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    stage2 = false;

    //creates new scene, sets the background image, and shows it on the graphicsview
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);
    ui->game->setBackgroundBrush(QBrush(QImage(":/images/Images/City Background.jpg")));
    ui->game->setScene(scene);
    ui->game->show();

    //hides previously visible buttons
    ui->instructionButton->hide();
    ui->startButton->hide();

    //adds player to the scene
    p1 = new player();
    p1->setPos(this->width()/2 - p1->width/2, this->height() - p1->height);
    p1->setFlag(QGraphicsItem::ItemIsFocusable);
    p1->setFocus();
    scene->addItem(p1);

    //adds score object to scene
    the_score = new score();
    scene->addItem(the_score);
    QObject::connect(the_score, SIGNAL(next_stage()), this, SLOT(next_stage()));//when you hit a certain score you go to the next stage

    //adds lives object to scene
    hp = new lives();
    hp->setY(hp->y() + 40);
    scene->addItem(hp);
    QObject::connect(hp, SIGNAL(hp_zero()), this, SLOT(game_over()));//when you run out of lives it's gameover

    spawn_speed = 1250;
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(spawn()));
    timer->start(spawn_speed);

    //sets the background music for the first stage of the game
    bgm = new QMediaPlayer();
    bgm->setMedia(QUrl("qrc:/sound/Sound/05 Come and Find Me.mp3"));
    bgm->setVolume(40);
    bgm->play();

    //connects spacebar presses of player to actual creation and firing of bullet objects
    QObject::connect(p1, SIGNAL(bullet_fired(int,int)), this, SLOT(bullet_fired(int,int)));
}

//hides other elements and shows instructions for the first stage
void MainWindow::on_instructionButton_clicked()
{
    ui->instructionText->show();
    ui->backButton->show();
    ui->instructionButton->hide();
    ui->startButton->hide();
}

//returns you to the main menu
void MainWindow::on_backButton_clicked()
{
    ui->instructionText->hide();
    ui->backButton->hide();
    ui->instructionButton->show();
    ui->startButton->show();
}

//spawns either animals or aliens
void MainWindow::spawn(){
    if(!stage2){//only animals are spawned during stage1. Whether it is a cat or dog is randomly chosen.
        animal* rand_animal = new animal();
        rand_animal->setX((qrand() % 670) - 12);
        rand_animal->set_image(qrand() % 2);
        scene->addItem(rand_animal);
        QObject::connect(rand_animal, SIGNAL(up_score()), the_score, SLOT(up_score()));
        QObject::connect(rand_animal, SIGNAL(down_hp()), hp, SLOT(down_hp()));
        QObject::connect(the_score, SIGNAL(next_stage()), rand_animal, SLOT(next_stage()));
    }
    else{//stage2 spawns both animals and aliens
        int friend_or_foe = qrand() % 2;//whether an animal or alien is spawned is randomly chosen
        if(friend_or_foe){//cat/dog is randomly chosen
            animal* rand_animal = new animal();
            rand_animal->setX((qrand() % 670) - 12);
            rand_animal->set_image(qrand() % 2);
            scene->addItem(rand_animal);
            QObject::connect(rand_animal, SIGNAL(up_score()), the_score, SLOT(up_score()));
            QObject::connect(rand_animal, SIGNAL(down_hp()), hp, SLOT(down_hp()));
            QObject::connect(the_score, SIGNAL(next_stage()), rand_animal, SLOT(next_stage()));
        }
        else{//cat alien/dog alien is randomly chosen
            alien* rand_alien = new alien();
            rand_alien->setX((qrand() % 670) - 12);
            rand_alien->set_image(qrand() % 2);
            scene->addItem(rand_alien);
            QObject::connect(rand_alien, SIGNAL(up_score()), the_score, SLOT(up_score()));
            QObject::connect(rand_alien, SIGNAL(down_hp()), hp, SLOT(down_hp()));
        }
    }
}

//stops the music, clears the animals, & covers the scene in white to display instructions for stage2 once point goal is met
void MainWindow::next_stage(){
    stage2 = true;
    p1->stage2 = true;
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

//deletes the game graphics view and displays gameover message once lives == 0
void MainWindow::game_over(){
    delete ui->game;
    ui->game_over_text->show();
    bgm->stop();
}

//moves from stage2 instructions back to the game
void MainWindow::on_nextButton_clicked()
{
    ui->stage2_instructions->hide();
    ui->nextButton->hide();
    scene->removeItem(cover);
    delete cover;
    bgm->play();
    timer->start();
}

//passes coordinate info from player to bullet creation
void MainWindow::bullet_fired(int x, int y){
    bullet* some_bullet = new bullet(x, y);
    scene->addItem(some_bullet);
}
