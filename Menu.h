#include "Area.h"
#pragma once
class Menu
{

public:
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
    void KeyRightClicked(Menu::Choice choice, Area& area);
    void HandlePlayOption(Area& area);
    void HandleOptions(Area& area);
    void HandleEndGame(Area& area);


};
