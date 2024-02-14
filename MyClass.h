#pragma once

class SnakeGame
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

    void gotoxy (short x, short y);
    void PrintMenu();
    void PrintEndGameText();
    void StartGame();

};
