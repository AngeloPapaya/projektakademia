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

    while(true) //glowna petla programu
    {
        wybor = 0;
        poprzedniWybor = wybor;
        wykonujPetle = true;

                //rysowanie menu
        system( "cls" );
        SnakeGame.Menu();


        while (wykonujPetle)   //strzalki (gora, dol)
        {
            SnakeGame.gotoxy( 9, wybor  + 4 );          //rysowanie strzalkani
            std::cout << static_cast < char >( 16 );
            poprzedniWybor = wybor;         //obslugga klawiatury

            switch( getch() )
            {
            case 224:           // STRZALKI
                switch( getch() )
                {
                case 72:                //strzalka w góre, ilosc opcji w menu (aktualnie dwie)
                    if ( 0 < wybor )
                    wybor--;
                    else wybor = 2;
                    break;

                case 80:                    //strzalka w dól, ilosc opcji w menu (aktualnie dwie)
                    if ( wybor < 2 )
                    wybor++;
                    else wybor = 0;
                    break;

                case 77: //strzalka w prawo //je¿eli wciœniêto strzalkê w prawo, sprawdz wybrana opcje i wykonaj odpowiednia akcje

//                  if ( wybor == 0)
//                  {
//                         //tutaj bedzie kod snake'a
//                  }
                    if ( wybor == 1 ) //menu opcji
                    {
                        system( "cls" );
                        break;
                    }
                    if ( wybor == 2 )
                    {
                        system( "cls" );
                        wykonujPetle = false;
                        SnakeGame.KoniecGry();
                        break;
                    }


                case 75: //strzalka w lewo cofa do menu
                    {
                        wybor = 0;
                        system( "cls" );
                        SnakeGame.Menu();
                        break;
                    }



                }


            SnakeGame.gotoxy( 9, poprzedniWybor  + 4 ); //czyszczenie strzalki wyboru
            std::cout << " ";

            }
    }
    return 0;

    }
}



