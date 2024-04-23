#include "SnakeGame.h"
#include "Menu.h"
#include "Area.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>


void SnakeGame::StartGame()
{
        while(menu.MainLoop) //main loop of the program
        {
            menu.ResetMenu();
            menu.DisplayMenu();
            menu.HandleMenu(menu, area, snake);
        }
}
























