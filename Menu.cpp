#include "SnakeGame.h"
#include "Menu.h"
#include "Area.h"
#include "Snake.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>


void Menu::gotoxy (short x, short y)
{
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void Menu::PrintMenu()
{
    system( "cls" );
    //Area area;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    area.SetTextColor(10);
    gotoxy(15,0);
    std::cout << "~~~~~~~~~~~~~";
    gotoxy(15,1);
    std::cout << "~~~ SNAKE ~~~";
     gotoxy(15,2);
    std::cout << "~~~~~~~~~~~~~";
    gotoxy(12,4);
    Sleep(500);
    area.SetTextColor(23);
    std::cout << " 1. Zagraj! " <<"\n";
    gotoxy(12,5);
    Sleep(500);
    area.SetTextColor(23);
    std::cout << " 2. Opcje " <<"\n";
    gotoxy(12,6);
    Sleep(500);
    area.SetTextColor(23);
    std::cout << " 3. Wyjdz z gry! ";
    area.SetTextColor(4);
}

void Menu::PrintEndGameText()
{
    //Area area;
    system( "cls" );
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    area.SetTextColor(11);
    gotoxy(24,2);
    std::cout << "~~ Do zobaczenia nastepnym razem! ~~";
    area.SetTextColor(7);
}

void Menu::ActionKey(Menu::Choice choice,Snake& snake)
{
    switch (choice)
    {
        case Menu::Choice::Play:
            Menu::HandlePlayOption();
            break;
        case Menu::Choice::Options:
            Menu::HandleOptions();
            break;
        case Menu::Choice::EndGame:
            Menu::HandleEndGame();
            break;
    }
}

void Menu::HandlePlayOption()
{

    area.CleanScreenCompletely();
    area = area;
    Name();
    SetAreaSize();
    area = area;
    Setup();

do
{
    snake.area = area;
    snake.Draw();
    snake.Input();
    snake.area = area;
    snake.Logic();
    Sleep(100); //sleep(10);
} while (!snake.gameOver);

    area.CleanScreenCompletely();
    //PrintEndGameText(area);
    snake.area = area;
    snake.EndGameScore();
    MenuLoop = false;
    MainLoop = false;
}

void Menu::HandleOptions()
{
    area.CleanScreenCompletely();
}

void Menu::HandleEndGame()
{
    area.CleanScreenCompletely();
    PrintEndGameText();
    MenuLoop = false;
    MainLoop = false;
}

void Menu::HandleArrowKeys(Snake& snake)
{
    int key = getch();
    Menu::Keys firstKeyPress = static_cast<Menu::Keys>(key);

    switch( firstKeyPress )
    {
                case Menu::Keys::Keyboard:
                    switch( static_cast<Menu::Keys>(getch()) )
                    {
                        case Menu::Keys::Up:              //arrows up, options (currently only 3)
                            if ( static_cast<int>(Menu::Choice::Play) < choice )
                            choice--;
                            else choice = static_cast<int>(Menu::Choice::EndGame);
                            break;

                        case Menu::Keys::Down:                    //arrows down, options (currently only 3)
                            if ( choice < static_cast<int> (Menu::Choice::EndGame) )
                            choice++;
                            else choice = static_cast<int>(Menu::Choice::Play);
                            break;


                        case Menu::Keys::Right: //arrow right, if pressed go to option
                            ActionKey(static_cast<Menu::Choice>(choice), snake);
                            break;

                        case Menu::Keys::Left: //left arrow cancel, and going back to menu
                        {
                                choice = 0;
                                area.CleanScreenCompletely();
                                PrintMenu();
                                break;
                        }
                    }
        gotoxy( 9, previousChoice  + 4 ); //cleaning arrow
        std::cout << " ";
        break;
    }
}

void Menu::HandleMenuLoop(Snake& snake)
{

     while (MenuLoop)   //arrows (up, down)
       {
            gotoxy( 9, choice  + 4 );          //arrows drawing
            std::cout << static_cast < char >( 16 );
            previousChoice = choice;
            HandleArrowKeys( snake);

        }
}

void Menu::ResetMenu()
{

    choice = 0;
    previousChoice = choice;
    MenuLoop = true;
}

void Menu::DisplayMenu()
{
    system("cls");
    PrintMenu();
}

void Menu::HandleMenu(Snake& snake)
{
    HandleMenuLoop(snake);
}



