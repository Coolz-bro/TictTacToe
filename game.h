#pragma once

 /*hier werden alle Funktionen,
 Elemente der der Struktur und Festwerte deklariert*/

 // funktioniert wie define
enum mode
{
    CLASSIC = 3,
    crazy = 10,
    LENGTH = 9,
    MAX_SIZE = 10
};

struct player
{
    int number;
    char name[30];
    int age;
    int wins;
    int ID;
};

void resetField(char* p_field);
void input_player(struct player players[]);
void drawField(char* p_field);
bool checkWin(char field[3][3]);
bool draw_game(char field[3][3]);
void play(enum mode Mygame, char field[3][3], struct player players[]);
void main_menu(char field[3][3],player players[]);
void help();
void credits();
void play_menu(char  field[3][3], struct player players[]);


void data_menu(player players[]);
void show_ranklist(player players[],int num_players);
int binary_search(player players[], int start, int end, int searched_num);
void selction_sort(player players[], int num_players);