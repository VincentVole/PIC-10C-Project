#include "animal.h"

animal::animal()
{
    QString fileName("C:/Users/ureshineko/Desktop/10C Projects/PIC-10C-Project/10C_Project/Images/Cat Head.png");
    player_image = new QPixmap(fileName);
}
