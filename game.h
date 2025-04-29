#pragma once
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
    std::string name;
    int age;
    int wins;
};

void resetField(char* p_field);
void welcome();
void input_player(struct player spieler[]);
void drawField(char* p_field);
bool checkWin(char field[3][3]);
bool draw_game(char field[3][3]);
void play(enum mode Mygame, char field[3][3], struct player spieler[2]);
void show_ranklist();
void binary_search(player spieler[]);
void menu(char  field[3][3], struct player spieler[]);
