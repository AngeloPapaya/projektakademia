#include "SnakeGame.h"
#include "Menu.h"
#include "Area.h"
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

void Menu::KeyRightClicked(Menu::Choice choice, Area& area, Menu& menu)
{
    switch (choice)
    {
        case Menu::Choice::Play:
            Menu::HandlePlayOption(area);
            break;
        case Menu::Choice::Options:
            Menu::HandleOptions(area);
            break;
        case Menu::Choice::EndGame:
            Menu::HandleEndGame(area, menu);
            break;
    }
}

void Menu::HandlePlayOption(Area& area)
{
    area.CleanScreenCompletely();
    area.ChooseArea();
    bool MainLoop = false;
    // Tutaj mo¿e byæ dodatkowy kod dotycz¹cy gry Snake
}

void Menu::HandleOptions(Area& area)
{

    area.CleanScreenCompletely();
    // Dodaj obs³ugê menu opcji, jeœli jest potrzebna
}

void Menu::HandleEndGame(Area& area, Menu& menu)
{
    area.CleanScreenCompletely();
    menu.PrintEndGameText();
    bool MenuLoop = false;
    bool MainLoop = false;
}


