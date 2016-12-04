#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd("C:/Users/ureshineko/Desktop/10C Projects/PIC-10C-Project/10C_Project/Images/City Background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

int MainWindow::instructions(){
    return 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}
