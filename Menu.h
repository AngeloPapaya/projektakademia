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


    const static int firstOption = 0;
    const static int lastOption = 2;

    enum class Choice
    {
        Play = 0,
        Options,
        EndGame
    };

    enum class Keys
    {
        Up = 72,
        Down = 80,
        Right = 77,
        Left = 75,
        Keyboard = 224

    };


    static void gotoxy (short x, short y);
    void PrintMenu(Area& area);
    void PrintEndGameText(Area& area);
    void ActionKey(Menu::Choice choice, Area& area, Menu& menu,Snake& snake);
    void HandlePlayOption(Area& area, Snake& snake);
    void HandleOptions(Area& area);
    void HandleEndGame(Area& area, Menu& menu);
    void HandleArrowKeys(Menu &menu, Area& area, Snake& snake);
    void HandleMenuLoop(Menu& menu,Area& area, Snake& snake);
    void ResetMenu();
    void DisplayMenu(Area& area);
    void HandleMenu(Menu& menu, Area& area, Snake& snake);



};

