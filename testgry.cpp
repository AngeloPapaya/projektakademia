#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

class SnakeGame
{
    public:
    void gotoxy (short x, short y)
{
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
    void GoDown();
    void GoUp();
    void GoLeft();
    void GoRight();
    void Menu()
    {
        gotoxy(15,0);

        std::cout << "~~ SNAKE ~~" << "\n";
        Sleep(600);
        gotoxy(12,1);
        std::cout << "~~ 1. Zagraj! ~~" << "\n";Sleep(600);
        gotoxy(12,2);
        std::cout << "~~ 2. Wyjdz! ~~";
        getch();

    }

};



int main()


{


SnakeGame tak;
tak.Menu();




return 0;






}


