#include<iostream>
#include<stdio.h>
#include"game.h"
#include<string>


void data_menu(player players[])
{
    system("cls");
    FILE* in;
    int number_of_players = 0;
    char my_choise;
    int is_there = fopen_s(&in, "Players.txt", "r"); // hier wird auch überprüft, ob die Datei exsistiert
    if (is_there != 0)
    {
        std::cerr << "Your File does not exists";
        return;
    }
    while (fscanf_s(in,"%s\t%i\t%i\n", players[number_of_players].name, 30, &players[number_of_players].age, &players[number_of_players].wins) != EOF)
        // Daten werden genauso wie bei "cin" abgespeichert
        // Daten werden in die jeweilige Stelle gesetzt
        // man kann leicht auf Daten zugreifen
        // man übergibt für alle  Variabeln immer die Adresse außer bei arrays

    {
        number_of_players++; // Damit man bei unterschiedlichen Stellen abgespeichern kann
    }
   
    fclose(in);
   
    do {
        system("cls");
        std::cout << "  \n\n\tPLAYERS_DATA\n\n   "
            << " \tWHAT DO YOU WANT TO DO ? \n"
            << " \tSEE RANKLIST (1)\n "
            << " \tSEARCH FOR SOMEBODY (2)\n "
            << " \tSET A FILTER (3)\n"
            << " \tQUIT (4)\n\t  ";
        std::cin >> my_choise;
        switch (my_choise)
        {
        case'1':
            show_ranklist(players, number_of_players);
            break;
       /* case'2':
            binary_search(players,0,number_of_players)
            break;*/
        /*case'3':
            set_filter(players);
            break;*/
        case'4':
            std::cout << "\tBACK TO MAIN MENU!!\n ";
            system("pause");
            break;
        default:
            std::cout << "\tINVAILD INPUT!!";
            break;
        }
    } while (my_choise != 'q' && my_choise != 'Q'&& my_choise!='4');
}


// Rankliste zeigen
void show_ranklist(player players[],int num_players)
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

// Falls man einen spezifischen Spieler sucht

int binary_search(player players[], int start, int end, int searched_num)
{
    int mittel = (start + end) / 2;
    if (mittel == searched_num) return mittel;
    if (searched_num > mittel)

    {
        return binary_search(players, mittel + 1, end, searched_num);
    }
    else
        return binary_search(players, start, mittel - 1, searched_num);

}

void selction_sort(player players[], int num_players) {
    
    player temp[MAX_SIZE];
    int higher = 0;
    for (int i = 0;i < num_players ;i++)
    {
        higher = i;
        for (int j = i+1; j < num_players;j++)
        {
            if (players[j].wins > players[higher].wins)
            {
                higher = j; //man speichert,die stelle bei higher  ab
            }
        }
        temp[higher] = players[higher]; // hier speichert man die groesste Zahl 
        players[higher] = players[i];
        players[i] = temp[higher];
    }
    for (int loop = 0;loop < num_players;loop++)
    {
        players[loop].ID = loop + 1; // Jeder Spieler hat eine Identifizierungsnummer
    }
}

