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
    Area area;
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
    Area area;
    system( "cls" );
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    area.SetTextColor(11);
    gotoxy(24,2);
    std::cout << "~~ Do zobaczenia nastepnym razem! ~~";
    area.SetTextColor(7);
}

void Menu::KeyRightClicked(Menu::Choice choice, Area& area, Menu& menu, Snake& snake)
{
    switch (choice)
    {
        case Menu::Choice::Play:
            Menu::HandlePlayOption(area, menu, snake);
            break;
        case Menu::Choice::Options:
            Menu::HandleOptions(area);
            break;
        case Menu::Choice::EndGame:
            Menu::HandleEndGame(area, menu);
            break;
    }
}

void Menu::HandlePlayOption(Area& area, Menu& menu, Snake& snake)
{
    //snake.Name(snake);
    area.CleanScreenCompletely();
    area.ChooseArea(area);

        snake.Setup(area);

             while (!snake.gameOver)
             {
              snake.Draw(area);
              snake.Input();
              snake.Logic(area);
              Sleep(100); //sleep(10);
             }
    MainLoop = false;
}

void Menu::HandleOptions(Area& area)
{
    area.CleanScreenCompletely();
}

void Menu::HandleEndGame(Area& area, Menu& menu)
{
    area.CleanScreenCompletely();
    menu.PrintEndGameText();
    MenuLoop = false;
    MainLoop = false;
}

void Menu::HandleArrowKeys(Menu &menu, Area& area, Snake& snake)
{
    switch( getch() )
    {
                case 224:
                    switch( static_cast<Menu::Keys>(getch()) )
                    {
                        case Menu::Keys::Up:              //arrows up, options (currently only 3)
                            if ( Menu::firstOption < menu.choice )
                            menu.choice--;
                            else menu.choice = Menu::lastOption;
                            break;

                        case Menu::Keys::Down:                    //arrows down, options (currently only 3)
                            if ( menu.choice < Menu::lastOption )
                            menu.choice++;
                            else menu.choice = Menu::firstOption;
                            break;


                        case Menu::Keys::Right: //arrow right, if pressed go to option
                            menu.KeyRightClicked(static_cast<Menu::Choice>(menu.choice), area, menu, snake);
                            break;

                        case Menu::Keys::Left: //left arrow cancel, and going back to menu
                        {
                                menu.choice = 0;
                                area.CleanScreenCompletely();
                                menu.PrintMenu();
                                break;
                        }
                    }
        menu.gotoxy( 9, menu.previousChoice  + 4 ); //cleaning arrow
        std::cout << " ";
        break;
    }
}

void Menu::HandleMenuLoop(Menu& menu, Area& area, Snake& snake)
{

     while (menu.MenuLoop)   //arrows (up, down)
       {
            menu.gotoxy( 9, menu.choice  + 4 );          //arrows drawing
            std::cout << static_cast < char >( 16 );
            menu.previousChoice = menu.choice;
            menu.HandleArrowKeys(menu, area, snake);

        }
}

void Menu::ResetMenu(Menu& menu)
{
    menu.choice = 0;
    menu.previousChoice = menu.choice;
    menu.MenuLoop = true;
}

void Menu::DisplayMenu(Menu& menu)
{
    system("cls");
    menu.PrintMenu();
}

void Menu::HandleMenu(Menu& menu, Area& area, Snake& snake)
{
    menu.HandleMenuLoop(menu, area, snake);
}


