#include "Area.h"
#include "Snake.h"
#include <iostream>
#pragma once

class Menu
{
public:
        std::string name;
        bool MenuLoop = true;
        bool MainLoop = true;
        int choice;
        int previousChoice;

    enum class Choice
    {
        Play = 0,
        Options,
        EndGame,
    };

    enum class Keys
    {
        Up = 72,
        Down = 80,
        Right = 77,
        Left = 75,
        Keyboard = 224,

    };
    Area area;
    Snake snake;
    static void gotoxy (short x, short y);
    void PrintMenu();
    void PrintEndGameText();
    void ActionKey(Menu::Choice choice,Snake& snake);
    void HandlePlayOption();
    void HandleOptions();
    void HandleEndGame();
    void HandleArrowKeys(Snake& snake);
    void HandleMenuLoop(Snake& snake);
    void ResetMenu();
    void DisplayMenu();
    void HandleMenu(Snake& snake);

};
