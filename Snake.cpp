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

void Snake::Setup()
{
     gameOver = false;
     dir = STOP;
     position.x = area.width / 2;
     position.y = area.height / 2;
     fruitX = rand() % area.width; //fruit random position
     fruitY = rand() % area.height; // fruit random position
     score = 0;
}

void Snake::Logic()
{

    tailX.resize(maxTailLength, 0);
    tailY.resize(maxTailLength, 0);

    int prevX = tailX.front();
    int prevY = tailY.front();
    int prev2X, prev2Y;

    tailX.front() = position.x;
    tailY.front() = position.y;

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
            position.x--;
            break;
        case RIGHT:
            position.x++;
            break;
        case UP:
            position.y--;
            break;
        case DOWN:
            position.y++;
            break;
        default:
            break;
    }

    if (position.x >= area.width) position.x = 0;
    else if (position.x < 0) position.x = area.width - 1;
    if (position.y >= area.height) position.y = 0;
    else if (position.y < 0) position.y = area.height - 1;

    for (auto itX = tailX.begin(), itY = tailY.begin(); itX != std::next(tailX.begin(), nTail); ++itX, ++itY)
    {
        if (*itX == position.x && *itY == position.y)
        {
            gameOver = true;
            break;
        }
    }

    if (position.x == fruitX && position.y == fruitY)
    {
        score += 10;
        fruitX = rand() % area.width;
        fruitY = rand() % area.height;

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

void Snake::Draw()
{
    system("cls");

    for (int i = 0; i < area.width + 2; i++) {
        std::cout << "#";
    }
    std::cout << "\n";

    for (int i = 0; i < area.height; i++) {
        for (int j = 0; j < area.width; j++) {
            if (j == 0)
                std::cout << "#";
            if (i == position.y && j == position.x)
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

void Snake::Name()
{
    COORD pos = {12,4};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    area.SetTextColor(10);
    std::cout << "Podaj swoje imie: ";
    area.SetTextColor(7);
    std::cin >> name;
    area.CleanScreenCompletely();
}

void Snake::EndGameScore()

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



