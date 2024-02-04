#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "MyClass.h"



    void SnakeGame::gotoxy (short x, short y)
    {
        COORD pos = {x,y};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    }

    void SnakeGame::Menu()
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 10);
        gotoxy(15,0);
        std::cout << "~~~~~~~~~~~~~";
        gotoxy(15,1);
        std::cout << "~~~ SNAKE ~~~";
         gotoxy(15,2);
        std::cout << "~~~~~~~~~~~~~";
        gotoxy(12,4);
        Sleep(500);
        SetConsoleTextAttribute(hConsole, 23);
        std::cout << " 1. Zagraj! " <<"\n";
        gotoxy(12,5);
        Sleep(500);
        SetConsoleTextAttribute(hConsole, 23);
        std::cout << " 2. Opcje " <<"\n";
        gotoxy(12,6);
        Sleep(500);
        SetConsoleTextAttribute(hConsole, 23);
        std::cout << " 3. Wyjdz z gry! ";
        SetConsoleTextAttribute(hConsole, 4);

    }

    void SnakeGame::KoniecGry()
    {
        system( "cls" );
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 11);
        gotoxy(24,2);
        std::cout << "~~ Do zobaczenia nastepnym razem! ~~";
        SetConsoleTextAttribute(hConsole, 15);
    }

