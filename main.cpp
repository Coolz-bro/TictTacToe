#include<iostream>
#include"game.h"

int main()
{
    char field[3][3]; 
    struct player players[MAX_SIZE]; //Struktur mit Zahn Elementen 
    enum mode Mygame; // f�r den modus
    system("color f0"); // Hintergrundfarbe
    main_menu(field, players);
    return 0; 

}