#include "SnakeGame.h"
#include "Menu.h"
#include "Area.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

void Area::SetTextColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Area::CleanScreenCompletely()
{
    system("cls");
}


void Area::SetBackgroundColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | (color << 4));
}


void Area::SetAreaSize(Area& area)
{

    do {
        SetTextColor(7);

        std::cout << "Podaj szerokosc obszaru Snake'a (maksymalnie 20): ";
        std::cin >> area.width;

        std::cout << "Podaj dlugosc obszaru Snake'a (maksymalnie 40): ";
        std::cin >> area.height;

        if (area.width <= 0 || area.height <= 0 || area.width > 20 || area.height > 40)
        {
            std::cout << "Niepoprawne wymiary obszaru. Podaj szerokosc od 1 do 20 i dlugosc od 1 do 40.\n";
        }

    } while (area.width <= 0 || area.height <= 0 || area.width > 20 || area.height > 40);
}

