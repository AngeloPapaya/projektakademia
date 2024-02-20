#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "SnakeGame.h"
#include "Menu.h"
#include "Area.h"

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


void Area::DrawArea(int width, int height) {
        CleanScreenCompletely(); // Clean screen before drawing
        SetTextColor(7);

        // Drawing upper edge of the area
        for (int i = 0; i < width + 2; ++i)
            std::cout << "#";
        std::cout << std::endl;

        // Draw walls and area inside
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width + 2; ++j) {
                if (j == 0 || j == width + 1)
                    std::cout << "#"; // Walls of area
                else
                    std::cout << " "; // Area inside
            }
            std::cout << std::endl;
        }

        // Bottom edge of the area
        for (int i = 0; i < width + 2; ++i)
            std::cout << "#";
        std::cout << std::endl;
    }


void Area::ChooseArea()
{
    int width, height;

    do {
        SetTextColor(7);

        std::cout << "Podaj szerokosc obszaru Snake'a (maksymalnie 20): ";
        std::cin >> width;

        std::cout << "Podaj dlugosc obszaru Snake'a (maksymalnie 40): ";
        std::cin >> height;

        if (width <= 0 || height <= 0 || width > 20 || height > 40)
        {
            std::cout << "Niepoprawne wymiary obszaru. Podaj szerokosc i dlugosc od 1 do 15.\n";
        }
        else
        {
            DrawArea(width, height);
        }
    } while (width <= 0 || height <= 0 || width > 20 || height > 40);
}
