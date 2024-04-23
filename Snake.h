//#include <vector>
#include <list>
#include <string>
#pragma once

struct Position
{
    int x,y;
};
class Snake
{
public:

std::string name;
std::list<int> tailX;
std::list<int> tailY;
bool gameOver;
int fruitX, fruitY, score;
int maxTailLength = 2;

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
    Position position;
    Area area;
    public:
    void Input();
    void Setup() ;
    void Logic() ;
    void Draw() ;
    void Name () ;
    void EndGameScore() ;



};

