#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "MyClass.h"


int main()
{
    SnakeGame SnakeGame;
    int wybor;
    int poprzedniWybor;
    bool wykonujPetle;

    //pêtla g³ówna programu
    while(true)
    {
        wybor = 0;
        poprzedniWybor = wybor;
        wykonujPetle = true;

        //rysowanie menu
        system( "cls" );
//        snake.gotoxy(3,1);
//        std::cfout << "Opcja A";
//        snake.gotoxy( 3, 3 );
//        std::cout << "Opcja B";
//        snake.gotoxy( 3, 5 );
//        std::cout << "Exit";
            SnakeGame.Menu();

        //przesuwanie strza³ki
        while( wykonujPetle )
        {

            SnakeGame.gotoxy( 1, wybor  + 4 );          //rysowanie strza³ki wyboru
            std::cout << static_cast < char >( 16 );

            poprzedniWybor = wybor;         //obs³uga klawiatury
            switch( getch() )
            {
            case 224:           // STRZA£KI
                switch( getch() )
                {
                case 72:                //strza³ka w górê, ilosc opcji w menu (aktualnie dwie)
                    if( 0 < wybor )
                    wybor--;
                    else wybor = 2;
                    break;

                case 80:                    //strza³ka w dó³, ilosc opcji w menu (aktualnie dwie)
                    if( wybor < 2 )
                    wybor++;
                    else wybor = 0;
                    break;

                case 77: //strzalka w prawo
                    //je¿eli wciœniêto strza³kê w prawo, sprawdŸ wybran¹ opcjê i wykonaj odpowiedni¹ akcjê
                    if ( wybor == 2)
                        {
                            wykonujPetle = false;
                            SnakeGame.KoniecGry();
                        }



//                    switch( wybor )
//                    {
//                    case 0:
////                        if ( wybor == 1)
////                        {
////                            system( "cls" );
////                            std::cout << "DZIEKUJEMT ZA GRE";
////                        }
//                        break;
//
//                    case 1:
//                        //OpcjaB();
//                        break;
//
//                    case 2:
//                        return 0;
//                    }
//                }
//                break;
            }


            SnakeGame.gotoxy( 1, poprzedniWybor  + 4 ); //czyszczenie strza³ki wyboru
           std::cout << " ";

        }
    }
    return 0;

    }
}
