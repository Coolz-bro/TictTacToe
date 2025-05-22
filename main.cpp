
#include<iostream>
#include"game.h" // Das ist eine Header_Datei (Dort werden einige Funktionen deklariert )

int main()
{
    system("title TIC TAC TOE"); // wird beim Konsollenfenster geschrieben
   
    char field[3][3]; 
    struct player players[MAX_SIZE]; //Struktur mit Zahn Elementen 
    enum mode Mygame; // für den modus
    show_main_menu(field, players);  // Hauptmenu wird aufgerufen 
    return 0; 

}