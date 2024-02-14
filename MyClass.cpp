#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "MyClass.h"

    void SnakeGame::gotoxy (short x, short y)
    {
        COORD pos = {x,y};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    }

    void SnakeGame::PrintMenu()
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 10);
        gotoxy(15,0);
        std::cout << "~~~~~~~~~~~~~";
        gotoxy(15,1);
        std::cout << "~~~ SNAKE ~~~";
         gotoxy(15,2);
        std::cout << "~~~~~~~~~~~~~";
        gotoxy(12,4);
        Sleep(500);
        SetConsoleTextAttribute(hConsole, 23);
        std::cout << " 1. Zagraj! " <<"\n";
        gotoxy(12,5);
        Sleep(500);
        SetConsoleTextAttribute(hConsole, 23);
        std::cout << " 2. Opcje " <<"\n";
        gotoxy(12,6);
        Sleep(500);
        SetConsoleTextAttribute(hConsole, 23);
        std::cout << " 3. Wyjdz z gry! ";
        SetConsoleTextAttribute(hConsole, 4);
    }

    void SnakeGame::PrintEndGameText()
    {
        system( "cls" );
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 11);
        gotoxy(24,2);
        std::cout << "~~ Do zobaczenia nastepnym razem! ~~";
        SetConsoleTextAttribute(hConsole, 15);
    }

    void SnakeGame::StartGame()
    {
        SnakeGame snakeGame;
        int wybor;
        int poprzedniWybor;
        bool MenuLoop;
        bool MainLoop = true;

        while(MainLoop) //glowna petla programu
        {
            wybor = 0;
            poprzedniWybor = wybor;
            MenuLoop = true;

                    //rysowanie menu
            system( "cls" );
            snakeGame.PrintMenu();


            while (MenuLoop)   //strzalki (gora, dol)
            {
                snakeGame.gotoxy( 9, wybor  + 4 );          //rysowanie strzalkani
                std::cout << static_cast < char >( 16 );
                poprzedniWybor = wybor;         //obslugga klawiatury
                switch( getch() )
                {
                case 224:           // STRZALKI
                    switch( static_cast<SnakeGame::Keys>(getch()) )
                    {
                    case SnakeGame::Keys::Up:              //strzalka w góre, ilosc opcji w menu (aktualnie dwie)
                        if ( 0 < wybor )
                        wybor--;
                        else wybor = 2;
                        break;

                    case SnakeGame::Keys::Down:                    //strzalka w dól, ilosc opcji w menu (aktualnie dwie)
                        if ( wybor < 2 )
                        wybor++;
                        else wybor = 0;
                        break;

                    case SnakeGame::Keys::Right: //strzalka w prawo //je¿eli wciœniêto strzalkê w prawo, sprawdz wybrana opcje i wykonaj odpowiednia akcje
                    {


                            Choice choice = static_cast<SnakeGame::Choice>(wybor);

                            if ( choice == SnakeGame::Choice::Play )
                            {
                                 //tutaj bedzie kod snake'a
                            }
                            if ( choice == SnakeGame::Choice::Options ) //menu opcji
                            {
                                system( "cls" );
                                break;
                            }
                            if ( choice == SnakeGame::Choice::EndGame )
                            {
                                system( "cls" );
                                snakeGame.PrintEndGameText();
                                MenuLoop = false;
                                MainLoop = false;
                                break;
                            }
                    }
                    case SnakeGame::Keys::Left: //strzalka w lewo cofa do menu
                        {
                            wybor = 0;
                            system( "cls" );
                            snakeGame.PrintMenu();
                            break;
                        }
                    }
                snakeGame.gotoxy( 9, poprzedniWybor  + 4 ); //czyszczenie strzalki wyboru
                std::cout << " ";

                }
            }


        }
    }

