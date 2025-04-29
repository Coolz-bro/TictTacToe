
#include<iostream>
#include"spiel.h"

int main()
{
    char field[3][3];
    struct player spieler[2]{
        {1,"Mohamad",19,2},
        {2,"Max",17,3},
    };
    /*spieler[0].number = 1;
    spieler[1].number = 2;*/
    enum mode Mygame;


    menu(field, spieler);


    return 0;

}
