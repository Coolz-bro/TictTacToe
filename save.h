#pragma once
#include"game.h"


void set_ready(player players[],int &num_players);
void data_menu(player players[]);
void show_ranklist(player players[], int num_players);
int linear_search(player players[],  int end);
void selction_sort(player players[], int num_players);
void set_filter(player players[],int num_players);
void search_player(player players[], int num_players);
void show_under_age_players(player players[], int num_players);
void show_adult_players(player players[], int num_players);
void enter_first_character(player players[], int num_players);
void delete_file();
