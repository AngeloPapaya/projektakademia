#include "SnakeGame.h"
#include "Menu.h"
#include "Area.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>


void SnakeGame::StartGame()
    {
        SnakeGame snakeGame;
        Menu menu;
        Area area;
        int choice;
        int previousChoice;
        bool MenuLoop;
        bool MainLoop = true;

        while(MainLoop) //main loop of the program
        {
            choice = 0;
            previousChoice = choice;
            MenuLoop = true;

                    //drawing menu
            system( "cls" );
            menu.PrintMenu();


            while (MenuLoop)   //arrows (up, down)
            {
                menu.gotoxy( 9, choice  + 4 );          //arrows drawing
                std::cout << static_cast < char >( 16 );
                previousChoice = choice;         //keyboard service
                switch( getch() )
                {
                case 224:           // ARROWS
                    switch( static_cast<Menu::Keys>(getch()) )
                    {
                    case Menu::Keys::Up:              //arrows up, options (currently only 3)
                        if ( Menu::firstOption < choice )
                        choice--;
                        else choice = Menu::lastOption;
                        break;

                    case Menu::Keys::Down:                    //arrows down, options (currently only 3)
                        if ( choice < Menu::lastOption )
                        choice++;
                        else choice = Menu::firstOption;
                        break;


                    case Menu::Keys::Right: //arrow right, if pressed go to option


                    menu.KeyRightClicked(static_cast<Menu::Choice>(choice), area);
                    break;

//                            Menu::Choice choice1 = static_cast<Menu::Choice>(choice);
//
//                            if ( choice1 == Menu::Choice::Play )
//                            {
//                                area.CleanScreenCompletely();
//                                area.ChooseArea();
//                                MainLoop = false;
//                                break;
////                                CleanScreenCompletely();
//                                 //tutaj bedzie kod snake'a
//                            }
//                            if ( choice1 == Menu::Choice::Options ) //Options menu
//                            {
//                                area.CleanScreenCompletely();
//                                break;
//                            }
//                            if ( choice1 == Menu::Choice::EndGame )
//                            {
//                                area.CleanScreenCompletely();
//                                menu.PrintEndGameText();
//                                MenuLoop = false;
//                                MainLoop = false;
//                                break;
//                            }
//                    }
                    case Menu::Keys::Left: //left arrow cancel, and going back to menu
                        {
                            choice = 0;
                            area.CleanScreenCompletely();
                            menu.PrintMenu();
                            break;
                        }
                    }
                menu.gotoxy( 9, previousChoice  + 4 ); //cleaning arrow
                std::cout << " ";
                break;

                }
            }


        }
    }























