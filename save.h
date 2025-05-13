#pragma once
#include"game.h"
#include<iostream>

// Hier werden die restlichen Funktionen deklariert
// Alle haben mit den Datensätzen der Spieler zu tun

void set_ready(player players[],int &num_players);
void data_menu(player players[]);
void show_ranklist(player players[], int num_players);
int linear_search(player players[],  int end);
void selection_sort(player players[], int num_players);
void set_filter(player players[],int num_players);
void search_player(player players[], int num_players);
void search_player_name(player players[], int num_players);
void search_player_rank(player players[], int num_players);
void show_under_age_players(player players[], int num_players);
void show_adult_players(player players[], int num_players);
void enter_first_character(player players[], int num_players);
void show_player_alphabetically(player players[], int num_players);
void delete_file();
void delete_players_data(player players[],int number_of_players,int delete_num);
