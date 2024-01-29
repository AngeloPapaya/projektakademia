#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

class SnakeGame
{
    void gotoxy (short x, short y)
{
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
    void GoDown();
    void GoUp();
    void GoLeft();
    void GoRight();
};

void gotoxy (short x, short y)
{
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

int main()


{

char znak = getch();





}


