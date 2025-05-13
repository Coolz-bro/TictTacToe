#include<iostream>
#include<stdio.h>
#include"save.h"
#include"game.h"



void data_menu(player players[])
{
  
    int num_players = 0;
    int remove_player=0;
    set_ready(players, num_players);
    selection_sort(players, num_players);
    char my_choice;
    do {
        system("cls");
        system("color 8F");
        std::cout << "  \n\n\tPLAYERS_DATA\n\n   "
            << " \tWHAT DO YOU WANT TO DO ? \n"
            << " \tSEE RANKLIST (1)\n "
            << " \tSET A FILTER (2)\n "
            << " \tSEARCH FOR SOMEONE (3)\n "
            <<"  \tDELATE ALL DATA (4)\n"
            <<"  \tDELETE A PLAYER FROM THE LIST(5)\n"
            << " \tQUIT (6)\n\t  ";
        std::cin >> my_choice;
        switch (my_choice)
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
            system("cls");
            std::cout << "Which player do you want to delete, enter his ID: ";
            std::cin >> remove_player;
            delete_players_data(players, num_players,remove_player);
            break;
        case'6':
            std::cout << "\tBACK TO MAIN MENU!!\n ";
            system("pause");
            break;
        default:
            std::cout << "\INVALID INPUT!!";
            break;
        }
    } while (my_choice != 'q' && my_choice != 'Q'&& my_choice !='6');
}


void set_ready(player players[], int& number_of_players)
{
   
    FILE* in; // Hier wird eine Datei zum Lesen deklariert
    int is_there = fopen_s(&in, "Players.csv", "r"); // hier wird auch überprüft, ob die Datei existiert
    if (is_there != 0)
    {
        std::cerr << "Your File does not exists";
        return;
    }
    
    while (fscanf_s(in, "%s\t%i\t%i\t%i\n", players[number_of_players].name, 30, &players[number_of_players].age, &players[number_of_players].wins,&players[number_of_players].ID) != EOF)
        //  Die Daten werden ähnlich wie bei "cin" eingelesen
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
   
    selection_sort(players, num_players); // es wird zuerst sotiert, dann gezeigt
    system("cls");
    if (num_players > 0) // Man überprüft, ob Spieler überhaupt exsistieren
    {
        std::cout << "\n\n\t\t\t       RANKLIST";

        std::cout << "\n\n\t\xDA" <<
            std::string(50, '-') << "\xbf" << "\n";
        std::cout << "\t|" << "\t\t\t\t\t\t   |\n";
        
        system("color 9F");

        std::cout << "\t|\tName\t" << "Age\t" << "Wins\t" << "ID\t" << "Rank\t   |\n"
            << "\t|\t" << std::string(37, '-') << "\t   |\n";

        int j = 0;
        while (j < num_players)
        {

            std::cout << "\t|" << "\t" << players[j].name << "\t" << players[j].age << "\t" << players[j].wins << "\t" << players[j].ID << "\t" << players[j].rank << "\t " << "  |" << std::endl;
            j++;
        }
        std::cout << "\t|" << "\t\t\t\t\t\t   |";
        std::cout << "\n\t\xC0" <<
            std::string(50, '-') << "\xD9";
        std::cout << "\n\n\n\n";
        system("PAUSE");
    }
    else
    {
        std::cout << "\n\t\No PLAYER FOUNDED !!\n\n\n"; // Falls keine Spieler gefunden wurden 
        system("PAUSE");
    }
}

void selection_sort(player players[], int num_players) {

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

        // hier wird getauscht
        temp = players[higher]; // hier speichert man die Person mit den  hoehsten Siegen ab
        players[higher] = players[i];
        players[i] = temp;
    }
    for (int u = 0;u < num_players;u++)
    {
        players[u].rank = u + 1; // Reihenfolge
    }
}

// Man kann hier ein bisschen filtern 
void set_filter(player players[], int num_players)
{
    char filter_num;
    do
    {
        system("cls");
        
        std::cout << "\n\n\t Which filter do you want to set ?\n\n"
            << "\t Players under 18 (1)\n"
            << "\t Adults (2)\n"
            << "\t first character (3)\n"
            << "\t players sorted alphabetically (4)\n"
            << " \t QUIT (5)\n\t";
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
        case'4':
            show_player_alphabetically(players, num_players);
            break;
        case '5':
            std::cout << "\tQUIT\n";
            system("pause");
            break;
        default:
            std::cout << "\tINVALID INPUT,TRY AGAIN !!\n";
            break;
        }
    } while (filter_num != '5');
}

void show_under_age_players(player players[], int num_players) // Wie der Name sagt, hier werden die Spieler angezeigt, die Minderjährig sind
{
    system("cls");
    if (num_players > 0) // genau wie eben 
    {
        std::cout << "\n\t\t PLAYERS UNDER 18: \n\n"
            << "\tName\t" << "Age\t" << "Wins\t" << "ID\t" << "Rank\n"
            << "\t" << std::string(40, '-') << std::endl;
        for (int l = 0;l < num_players;l++)
        {
            if (players[l].age <= 17)
            {
                std::cout << "\t" << players[l].name << "\t" << players[l].age << "\t" << players[l].wins << "\t" << players[l].ID << "\t" << players[l].rank << std::endl;
            }

        }
        std::cout << "\n\n";
        system("pause");
    }
    else
    {
        std::cout << "\n\t\NO PLAYER FOUNDED !!\n\n\n";
        system("PAUSE");
    }
}
void show_adult_players(player players[], int num_players) // Das ist der oberen Funktion entgegengesetzt
{
    system("cls");
    if (num_players > 0)
    {
        std::cout << "\n\t\t     ADULTS: \n\n";
        std::cout << "\tName\t" << "Age\t" << "Wins\t" << "ID\t" << "Rank\n"
            << "\t" << std::string(40, '-') << std::endl;
        for (int f = 0;f < num_players;f++)
        {

            if (players[f].age > 17)
            {
                std::cout << "\t" << players[f].name << "\t" << players[f].age << "\t" << players[f].wins << "\t" << players[f].ID << "\t" << players[f].rank << std::endl;
            }

        }
        std::cout << "\n\n";
        system("pause");
    }
    else
    {
        std::cout << "\n\t\NO PLAYER FOUND !!\n\n\n";
        system("PAUSE");
    }
}
void enter_first_character(player players[], int num_players) // Hier werden die Spieler, je nach eingegebenen Buchstabe, angezeigt
{
    system("cls");
    if (num_players > 0)
    {
        char first_char;
        std::cout << "\n\tEnter the first character:";
        std::cin >> first_char;
        system("cls");
        std::cout << "\n\t\t ALL PLAYERS WITH (" << first_char << ")\n\n"
            << "\tName\t" << "Age\t" << "Wins\t" << "ID\t" << "Rank\n"
            << "\t" << std::string(35, '-') << std::endl;
        for (int loop = 0;loop < num_players;loop++)
        {
            if (players[loop].name[0] == first_char)
            {
                std::cout << "\t" << players[loop].name << "\t" << players[loop].age << "\t" << players[loop].wins << "\t" << players[loop].ID << "\t" << players[loop].rank << std::endl;
            }
        }
        std::cout << "\n\n";
        system("pause");
    }
    else
    {
        std::cout << "\n\t\tNO PLAYER FOUNDED !!\n\n\n";
        system("PAUSE");
    }
}

void show_player_alphabetically(player players[], int num_players) // Alphabetisch sortieren
{
    system("cls");
    player temp;
    int min;
    for (int i = 0;i < num_players-1 ;i++)
    {
        min = i;
        for (int j = i + 1;j < num_players;j++)
        {
            if (players[min].name[0] > players[j].name[0])
            {
                min = j;
            }
        }
        temp = players[i];
        players[i] = players[min];
        players[min] = temp;
    }
    if (num_players > 0)
    {
        std::cout << "\n\t  PLAYER SORTED ALPHABETICALLY\n\n";
        std::cout << "\tName\t" << "Age\t" << "Wins\t" << "ID\t" << "Rank\n"
            << "\t" << std::string(40, '-') << std::endl;
        int j = 0;
        while (j < num_players)
        {
            std::cout << "\t" << players[j].name << "\t" << players[j].age << "\t" << players[j].wins << "\t" << players[j].ID << "\t" << players[j].rank << std::endl;
            j++;
        }
        std::cout << "\n\n";
        system("PAUSE");
    }
    else
    {
        std::cout << "\n\t\NO PLAYER FOUNDED !!\n\n\n";
        system("PAUSE");
    }
}
void search_player(player players[], int number_of_players) // Man kann hier spezifischer suchen
{
   
    char input_search;
    do
    {
        system("cls");
        std::cout << "\n\n\tSearch  by name (1)\n "
            << "\tSearch by ID (2)\n"
            << "\tQuit (3)\n\t";
        std::cin >> input_search;
        switch (input_search)
        {
        case'1':
            search_player_rank(players, number_of_players);
            break;
        case'2':
            search_player_name(players, number_of_players);
            break;
        case'3':
            std::cout << "\tBACK TO MENU!!\n\n";
            system("pause");
            break;

        default:
            std::cout << "\tINVALID!!\n\n";
            system("pause");
            break;
        }
    } while (input_search != '3');
   
}

int linear_search(player players[], int end) // Das hilft sehr bei der Suche
{
    system("cls");
    std::string searched_player;
    std::cout << "\n\tENTER PLAYER'S NAME :";
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

void search_player_rank(player players[], int num_players) // Hier kann man herausfinden, an welcher Stelle ein  Spieler auf der Liste steht 
{
  
    system("cls");
    if (num_players == 0)
    {
        std::cout << "\n\n\tNO PLAYER ON THE LIST!!\n\n";
        system("pause");
        system("cls");
    }
    else
    {
        int erg = linear_search(players, num_players);
        system("cls");
        if (erg == -1)
        {
            std::cout << "\nNot found on the list, try again !\n\n ";


        }
        else if (players[erg].rank == 1)
        {
            std::cout << "\n\t" << players[erg].name << " is on the FIRST place !!.\n";
        }
        else if (players[erg].rank == 2)
        {
            std::cout << "\n\t" << players[erg].name << " is on the SECOND place !!.\n";
        }
        else if (players[erg].rank == 3)
        {
            std::cout << "\n\t" << players[erg].name << " is on the THIRD place !!.\n";
        }

        else if (players[erg].rank >= 4)
        {
            std::cout << "\n\t" << players[erg].name << " is on the " << players[erg].rank << "th place. ";

        }
        system("pause");
    }
}

void search_player_name(player players[], int num_players) // hier ´kann man nach einem Spieler suchen 
{
    system("cls");
    int in = 0;
    bool found=false;
    if (num_players == 0)
    {
        std::cout << "\n\n\tNO PLAYER ON THE LIST!!\n\n";
        system("pause");
        system("cls");
    }
    else
    {
        std::cout << "\n\tEnter PLAYER'S ID :";
        std::cin >> in;
        for (int lp = 0;lp < num_players;lp++)
        {
            if (in == players[lp].ID)
            {
                std::cout << "\n\tThe searched Player is " << players[lp].name << "\n\n";
                found = true;
                break;
            }
        }
        if (!found)
        {
            std::cout << "\n\tPLAYER NOT FOUND!!,try again please!!\n\n";
        }
        system("pause");
    }
}


// Hier kann man einen gewählten Spieler aus der Liste entfernen 
void delete_players_data(player players[], int number_of_players,int delete_num) {
   
    system("cls");
    FILE* read;
    int result_1 = fopen_s(&read, "Players.csv", "r"); // Man oeffnet die orignale Datei zum Lesen
    FILE* write;
    int result_2 = fopen_s(&write, "temp.csv", "a"); // Man oeffnet eine temporäre Datei zum Schreiben bsw. einfuegen
    if (result_1 != 0 || result_2 != 0) 
    {
        std::cerr << "File can not opened!!";
        return;
    }
    

    int count = 0;

    while (fscanf_s(read, "%s\t%d\t%d\t%i\n", players[count].name,30, &players[count].age, &players[count].wins,&players[count].ID) != EOF) {
       
        if(players[count].ID!=delete_num)
        {
            fprintf_s(write, "%s\t%d\t%d\t%i\n", players[count].name, players[count].age, players[count].wins, players[count].ID); // Hier werden die Datensätze geschrieben,die man wirklich haben moechte
            count++;
        }
    }

    // hier schliesst man  die Dateien
    fclose(read);
    fclose(write);

    remove("Players.csv"); // hier löscht man die Datei 
    rename("temp.csv", "Players.csv"); // hier wird die temporäre Datei umbenennen

  
}

// Damit löscht man alle Datensätze
void delete_file()
{
    system("cls");
    system("color CF ");
    bool input;
    std::cout << "\n\n\t\tARE YOU SURE ABOUT THAT ?? (1) yes (0) no ";
    std::cin >> input;
    if (input)
    {
        if (remove("Players.csv") == 0) 
        {
            std::cout << "File deleted successfully.\n";
            system("pause");
        }
        else
            std::cerr << "Error deleting the file.\n";
    }
}

