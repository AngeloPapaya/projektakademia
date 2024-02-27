#include "Area.h"
#include "Snake.h"
#pragma once
class Menu
{

public:
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

    void gotoxy (short x, short y);
    void PrintMenu();
    void PrintEndGameText();
    void InitializeGameObjects();
    void DrawMenu();
    void KeyRightClicked(Menu::Choice choice, Area& area, Menu& menu,Snake& snake);
    void HandlePlayOption(Area& area, Menu& menu, Snake& snake);
    void HandleOptions(Area& area);
    void HandleEndGame(Area& area, Menu& menu);
    void HandleArrowKeys(Menu &menu, Area& area, Snake& snake);
    void HandleMenuLoop(Menu& menu, Area& area, Snake& snake);
    void ResetMenu(Menu& menu);
    void DisplayMenu(Menu& menu);
    void HandleMenu(Menu& menu, Area& area, Snake& snake);

};
