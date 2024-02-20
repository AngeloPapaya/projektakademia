#pragma once

class Menu
{
public:

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

    enum class HowManyOptionsInMenu
    {
        FirstOpttionInMenu = 0,
        LastOptionInMenu = 3
    };
    void gotoxy (short x, short y);
    void PrintMenu();
    void PrintEndGameText();


};
