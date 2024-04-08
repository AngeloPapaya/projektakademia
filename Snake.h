#include "Area.h"
//#include <vector>
#include <list>
#include <string>
#pragma once

struct Position
{
    int x,y;
};
class Snake : public Position
{
public:

std::string name;
std::list<int> tailX;
std::list<int> tailY;
bool gameOver;
int fruitX, fruitY, score;
int maxTailLength = 4;

int nTail=0;

enum Directon
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN,
};

    Directon dir;
    void Input();
    void Setup (Area& area) ;
    void Logic (Area& area) ;
    void Draw (Area& area) ;
    void Name (Area& area) ;
    void EndGameScore (Area& area) ;



};

