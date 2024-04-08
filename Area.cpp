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


void Area::SetAreaSize()
{
        do
        {
        SetTextColor(7);
        std::cout << "Podaj szerokosc obszaru Snake'a (maksymalnie 60): ";
        std::cin >> width;
            if (width < 10 || width > 60)
            {
                std::cout << "Niepoprawna szerokosc obszaru, prosze podaj wymiary od 10 do 60" << "\n";
            }
        } while (width < 10 || width > 60);

        do
        {
        std::cout << "Podaj dlugosc obszaru Snake'a (maksymalnie 40): ";
        std::cin >> height;
            if (height < 10 || height > 40)
            {
                std::cout << "Niepoprawna dlugosc obszaru, prosze podaj wymiary od 10 do 40" << "\n";
            }
        } while (height < 10 || height > 40);

}

