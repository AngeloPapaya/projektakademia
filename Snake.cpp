#include "SnakeGame.h"
#include "Menu.h"
#include "Area.h"
#include "Snake.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <algorithm>
#include <windows.h>


void Snake::Input()
{
 if (_kbhit())
 {
  switch (_getch())
  {
  case 'a':
   dir = LEFT;
   break;
  case 'd':
   dir = RIGHT;
   break;
  case 'w':
   dir = UP;
   break;
  case 's':
   dir = DOWN;
   break;
  case 'x':
   gameOver = true;
   break;
  }
 }
}

void Snake::Setup(Area& area)
{
     gameOver = false;
     dir = STOP;
     x = area.width / 2;
     y = area.height / 2;
     fruitX = rand() % area.width; //fruit random position
     fruitY = rand() % area.height; // fruit random position
     score = 0;
}

void Snake::Logic(Area& area)
{
    //std::list<int> tailX;
    //std::list<int> tailY;

    tailX.resize(maxTailLength, 0); // Inicjalizacja listy tailX o rozmiarze 100 zerami
    tailY.resize(maxTailLength, 0);

    int prevX = tailX.front();
    int prevY = tailY.front();
    int prev2X, prev2Y;

    tailX.front() = x;
    tailY.front() = y;

    for (auto it = std::next(tailX.begin()); it != tailX.end(); ++it) {
        prev2X = *it;
        prev2Y = *std::next(tailY.begin(), std::distance(tailX.begin(), it));
        *it = prevX;
        *std::next(tailY.begin(), std::distance(tailX.begin(), it)) = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }

    if (x >= area.width) x = 0;
    else if (x < 0) x = area.width - 1;
    if (y >= area.height) y = 0;
    else if (y < 0) y = area.height - 1;

    for (auto itX = tailX.begin(), itY = tailY.begin(); itX != std::next(tailX.begin(), nTail); ++itX, ++itY)
    {
        if (*itX == x && *itY == y)
        {
            gameOver = true;
            break;
        }
    }

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % area.width;
        fruitY = rand() % area.height;

        // Dodajemy nowy segment wê¿a
        tailX.push_back(prevX);
        tailY.push_back(prevY);

        if (nTail < maxTailLength)
        {
            nTail++;
        }
        else
        {
            gameOver = true;
        }
    }
}

void Snake::Draw(Area& area)
{
    system("cls"); // Dla systemu Windows

    for (int i = 0; i < area.width + 2; i++) {
        std::cout << "#";
    }
    std::cout << "\n";

    for (int i = 0; i < area.height; i++) {
        for (int j = 0; j < area.width; j++) {
            if (j == 0)
                std::cout << "#";
            if (i == y && j == x)
                std::cout << "O";
            else if (i == fruitY && j == fruitX)
                std::cout << "F";
            else {
                bool print = false;
                for (auto itX = tailX.begin(), itY = tailY.begin(); itX != std::next(tailX.begin(), nTail); ++itX, ++itY) {
                    if (*itX == j && *itY == i) {
                        std::cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    std::cout << " ";
            }
            if (j == area.width - 1)
                std::cout << "#";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < area.width + 2; i++)
        std::cout << "#";
    std::cout << "\n";

    std::cout << "Maksymalna dlugosc weza to: ";
    area.SetTextColor(6);
    std::cout << maxTailLength << "\n";
    area.SetTextColor(7);
    std::cout << name << " punkty: ";
    area.SetTextColor(6);
    std::cout << score << "\n";
    area.SetTextColor(7);

    std::cout << "Nacisnij ";
    area.SetTextColor(6);
    std::cout << "x";
    area.SetTextColor(7);
    std::cout << ", aby zakonczyc gre.";
}

void Snake::Name(Area& area)
{
    COORD pos = {12,4};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    area.SetTextColor(10);
    std::cout << "Podaj swoje imie: ";
    area.SetTextColor(7);
    std::cin >> name;
    area.CleanScreenCompletely();
}

void Snake::EndGameScore(Area& area)

{
    Menu::gotoxy(24,2);
    area.SetTextColor(13);
    std::cout << "Twoje punkty to: ";
    area.SetTextColor(14);
    std::cout << score << "\n";
    area.SetTextColor(13);
    Menu::gotoxy(22,3);
    std::cout << "Powodzenia nastepnym razem!" << "\n";
    area.SetTextColor(7);



}



