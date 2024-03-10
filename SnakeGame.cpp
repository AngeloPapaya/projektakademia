#include "SnakeGame.h"
#include "Menu.h"
#include "Area.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>


void SnakeGame::StartGame()
{
    SnakeGame snakeGame;
    Menu menu;
    Area area;
    Snake snake;

        while(menu.MainLoop) //main loop of the program
        {
            menu.ResetMenu();
            menu.DisplayMenu(area);
            menu.HandleMenu(menu, area, snake);
        }
}
























