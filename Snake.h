#include "Area.h"
#pragma once
class Snake
{
public:

bool gameOver;
int x=0, y=0, fruitX=0, fruitY=0, score=0;
int tailX[100], tailY[100];
int nTail=0;

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
