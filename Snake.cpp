#include "SnakeGame.h"
#include "Menu.h"
#include "Area.h"
#include "Snake.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
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
    tailX.resize(100, 0); // Inicjalizacja wektora tailX o rozmiarze 100 zerami
    tailY.resize(100, 0);
     int prevX = tailX[0];
     int prevY = tailY[0];
     int prev2X, prev2Y;
     tailX[0] = x;
     tailY[0] = y;
        for (int i = 1; i < nTail; i++)
        {
          prev2X = tailX[i];
          prev2Y = tailY[i];
          tailX[i] = prevX;
          tailY[i] = prevY;
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
// if (x >= area.width || x < 0 || y >= area.height || y < 0) snake outside wall -> ends game
//  {
//     gameOver = true;}
//  }

 if (x >= area.width) x = 0;
    else if (x < 0) x = area.width - 1;
 if (y >= area.height) y = 0;
    else if (y < 0) y = area.height - 1;

 for (int i = 0; i < nTail; i++)
    if (tailX[i] == x && tailY[i] == y)
    gameOver = true;

 if (x == fruitX && y == fruitY)
 {
      score += 10;
      fruitX = rand() % area.width;
      fruitY = rand() % area.height;
      nTail++;
 }
}



void Snake::Draw(Area& area)
{
    system("cls"); //system("clear");
        for (int i = 0; i < area.width+2; i++)
            std::cout << "#";
            std::cout << "\n";

 for (int i = 0; i < area.height; i++)
 {
  for (int j = 0; j < area.width; j++)
  {
   if (j == 0)
    std::cout << "#";
   if (i == y && j == x)
    std::cout << "O";
   else if (i == fruitY && j == fruitX)
    std::cout << "F";
   else
   {
    bool print = false;
    for (int k = 0; k < nTail; k++)
    {
     if (tailX[k] == j && tailY[k] == i)
     {
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

 for (int i = 0; i < area.width+2; i++)
    std::cout << "#";
    std::cout << "\n";
    std::cout << name << " punkty: ";
    area.SetTextColor(6);
    std::cout << score << "\n";
    area.SetTextColor(7);
    //std::cout << "X " << x << " " << "Y " << y << "\n";
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



