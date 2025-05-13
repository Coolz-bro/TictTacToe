
#include<iostream>
#include"game.h" // Das ist eine Header_Datei (Funktion: Deklaration der Funktionen)

int main()
{
    system("title TIC TAC TOE"); // wird beim Konsollenfenster geschrieben
   
    char field[3][3]; 
    struct player players[MAX_SIZE]; //Struktur mit Zahn Elementen 
    enum mode Mygame; // für den modus
    system("color f0"); // Hintergrundfarbe
    show_main_menu(field, players); 
    return 0; 

}