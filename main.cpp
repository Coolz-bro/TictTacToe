#include<iostream>
#include"game.h"

int main()
{
    char field[3][3];
    struct player spieler[MAX_SIZE];
    spieler[0].number = 1;
    spieler[1].number = 2;
    enum mode Mygame;
    while (true)
    {
        system("color f0");
        menu(field, spieler);
    }
    return 0;

}