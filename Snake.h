#include "Area.h"
#include <vector>
#include <string>
#pragma once
class Snake
{
public:

std::string name;
std::vector<int> tailX;
std::vector<int> tailY;
bool gameOver;
int x,y,fruitX, fruitY, score;

int nTail=0;

enum Directon
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

    Directon dir;
    void Input();
    void Setup(Area& area);
    void Logic(Area& area);
    void Draw(Area& area);
    void Name(Area& area);
    void EndGameScore(Area& area);



};

