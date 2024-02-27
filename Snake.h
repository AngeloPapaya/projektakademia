#include "Area.h"
#pragma once
class Snake
{
public:

bool gameOver;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;

enum eDirecton
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

    eDirecton dir;
    void Input();
    void Setup(Area& area);
    void Logic(Area& area);
    void Draw(Area& area);


};
