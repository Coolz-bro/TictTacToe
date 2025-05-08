#include<iostream>
#include<stdio.h>
#include <cstdio> 
#include"save.h"
#include"game.h"
#include<string>


void data_menu(player players[])
{
    int num_players = 0;
    set_ready(players,num_players);
    char my_choise;
    do {
        system("cls");
        std::cout << "  \n\n\tPLAYERS_DATA\n\n   "
            << " \tWHAT DO YOU WANT TO DO ? \n"
            << " \tSEE RANKLIST (1)\n "
            << " \tSET A FILTER (2)\n "
            << " \tSEARCH FOR SOMEONE (3)\n "
            <<"  \tDELATE ALL DATA (4)\n"
            << " \tQUIT (5)\n\t  ";
        std::cin >> my_choise;
        switch (my_choise)
        {
        case'1':
            show_ranklist(players, num_players);
            break;
        case'2':
            set_filter(players, num_players);
            break;
        case'3':
            search_player(players, num_players);
            break;
        case'4':
            delete_file();
            break;
        case'5':
            std::cout << "\tBACK TO MAIN MENU!!\n ";
            system("pause");
            break;
        default:
            std::cout << "\tINVAILD INPUT!!";
            break;
        }
    } while (my_choise != 'q' && my_choise != 'Q'&& my_choise!='5');
}


void set_ready(player players[], int& number_of_players)
{
    FILE* in;
    int is_there = fopen_s(&in, "Players.txt", "r"); // hier wird auch überprüft, ob die Datei exsistiert
    if (is_there != 0)
    {
        std::cerr << "Your File does not exists";
        return;
    }
    while (fscanf_s(in, "%s\t%i\t%i\n", players[number_of_players].name, 30, &players[number_of_players].age, &players[number_of_players].wins) != EOF)
        // Daten werden genauso wie bei "cin" abgespeichert
        // Daten werden in die jeweilige Stelle gesetzt
        // man kann leicht auf Daten zugreifen
        // man übergibt für alle  Variabeln immer die Adresse außer bei arrays

    {
        number_of_players++; // Damit man bei unterschiedlichen Stellen abgespeichern kann
    }

    fclose(in);
}

// Rankliste zeigen
void show_ranklist(player players[], int num_players)
{
    selction_sort(players, num_players);
    system("cls");
        std::cout << "Name\t" << "Age\t" << "Wins\t" << "ID\n"
            << std::string(35, '-') << std::endl;
        int j = 0;
        while (j < num_players)
        {
            std::cout << players[j].name << "\t" << players[j].age << "\t" << players[j].wins << "\t" << players[j].ID << std::endl;
            j++;
        }
        system("PAUSE");
}

void selction_sort(player players[], int num_players) {

    player temp;   // für die Zwischenergebnisse 
    int higher = 0; //laufvariable
    for (int i = 0;i < num_players;i++)
    {
        higher = i;
        for (int j = i + 1; j < num_players;j++)
        {
            if (players[j].wins > players[higher].wins)
            {
                higher = j; //man speichert,die stelle bei higher  ab
            }
        }
        temp = players[higher]; // hier speichert man die Person mit den  hoehsten Siegen ab
        players[higher] = players[i];
        players[i] = temp;
    }
    for (int loop = 0;loop < num_players;loop++)
    {
        players[loop].ID = loop + 1; // Jeder Spieler hat eine Identifizierungsnummer
    }
}

void set_filter(player players[], int num_players)
{
    char filter_num;
    do
    {
        system("cls");
        std::cout << "\n\n\t Which filter do you want to set ?\n"
            << "\t Players under 18 (1)\n"
            << "\t Adults (2)\n"
            << "\t first charackter (3)\n"
            << " \t QUIT (4)\n";
        std::cin >> filter_num;
        switch (filter_num)
        {
        case '1':
            show_under_age_players(players, num_players);
            break;
        case '2':
            show_adult_players(players, num_players);
            break;
        case '3':
            enter_first_character(players, num_players);
            break;
        case '4':
            std::cout << "\tQUIT\n";
            system("pause");
            break;
        default:
            std::cout << "\tINVALID INPUT,TRY AGAIN !!\n";
            break;
        }
    } while (filter_num != '4');
}

void show_under_age_players(player players[], int num_players)
{
    system("cls");
    std::cout << "\n\t PLAYERS UNDER 18: \n\n"
        << "Name\t" << "Age\t" << "Wins\t" << "ID\n"
        << std::string(35, '-') << std::endl;
    for (int l = 0;l < num_players;l++)
    {
        if (players[l].age <= 17)
        {
            std::cout << players[l].name << "\t" << players[l].age << "\t" << players[l].wins << "\t" << players[l].ID << std::endl;
        }

    }
    system("pause");
}
void show_adult_players(player players[], int num_players)
{
    system("cls");
    std::cout << "\n\t ADULTS: \n\n";
    std::cout << "Name\t" << "Age\t" << "Wins\t" << "ID\n"
        << std::string(35, '-') << std::endl;
    for (int f = 0;f < num_players;f++)
    {

        if (players[f].age > 17)
        {
            std::cout << players[f].name << "\t" << players[f].age << "\t" << players[f].wins << "\t" << players[f].ID << std::endl;
        }

    }
    system("pause");
}

void search_player(player players[], int number_of_players)
{
      
    int erg = linear_search(players, number_of_players);
    system("cls");
    if (erg == -1)
    {
        std::cout << "Not found on the list, try again ! ";
    }
    else if (players[erg].ID == 1)
    {
        std::cout << "\n\t"<<players[erg].name<< " is on the FIRST place !!.\n" ;
    }
    else if (players[erg].ID == 2)
    {
        std::cout << "\n\t"<<players[erg].name<<" is on the SECOND place !!.\n";
    }
    else if (players[erg].ID == 3)
    {
        std::cout << "\n\t" << players[erg].name << " is on the THIRD place !!.\n";
    }

    else if (players[erg].ID>=4)
    {
        std::cout << "\n\t" << players[erg].name << " is on the " << players[erg].ID<< "th place. ";
    }
    system("pause");
}




// Falls man einen spezifischen Spieler sucht

int linear_search(player players[], int end) 
{
    system("cls");
    std::string searched_player;
    std::cout << "\n\tENTER PLAYER NAME :";
    std::cin >> searched_player;
    for (int start = 0;start < end; start++)
    {
        if (searched_player == players[start].name)
        {
            return start;
        }
    }
    return -1;
   
}

void enter_first_character(player players[], int num_players)
{
    system("cls");
    char first_char;
    std::cout << "\n\tEnter the first character:";
    std::cin >> first_char;
    system("cls");
    std::cout << "\n\t  ALL PLAYERS WITH (" << first_char << ")\n\n"
             << "\tName\t" << "Age\t" << "Wins\t" << "ID\n"
             <<"\t" << std::string(28, '-') << std::endl;
    for (int loop = 0;loop < num_players;loop++)
    {
        if (players[loop].name[0] == first_char)
        {
            std::cout <<"\t"<< players[loop].name << "\t" << players[loop].age << "\t" << players[loop].wins << "\t" << players[loop].ID << std::endl;
        }
    }
    std::cout << "\n\n";
    system("pause");
}

void delete_file()
{
    if (remove("Players.txt") == 0)
        std::cout << "File deleted successfully.\n";
    else
        std::cerr << "Error deleting the file.\n";
}