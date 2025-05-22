
#pragma once

 /*hier werden alle Funktionen,
 Struktur und Festwerte deklariert*/

 // funktioniert wie define
enum mode
{
    CLASSIC = 3, // Drei Spieldurchläufe
    CRAZY = 10,
    LENGTH = 9,
    MAX_SIZE = 100 // Maximale länge für die Struktur
};

// Struktur variabeln 
struct player
{
    int number;
    char name[30];
    int rank;
    int age;
    int wins;
    int ID;
};

// Funktionen werden in game.cpp vorgestellt 
void resetField(char* p_field);
void input_player(struct player players[],int num_players);
void drawField(char* p_field);
bool checkWin(char field[3][3]);
bool draw_game(char field[3][3]);
void play(enum mode Mygame, char field[3][3], struct player players[],int num_players);
void show_main_menu(char field[3][3],player players[]);
void help();
void credits();
void play_menu(char  field[3][3], struct player players[]);

