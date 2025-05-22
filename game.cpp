#include <iostream>
#include"save.h"
#include"game.h"


void show_main_menu(char field[3][3], player players[])
{
    char my_input;
    
    do {
        system("cls");
        // Formatierung 
        std::cout << "\n\t\tMAIN MENU\n\n";
        system("color e0");
        std::cout <<"\t\xDA"<< std::string(24, '-') <<"\xbf\n" /* Rahmen*/
            << " \t|   Enter a number\t |\n"
            << " \t|   PLAY (1)\t\t |\n"
            << " \t|   PLAYERS_Data (2)\t |\n"
            << " \t|   HELP (3)\t\t |\n"
            << " \t|   Credits (4)\t\t |\n"
            << " \t|   Quit (5)\t\t |\n"
            << "\t\xC0"<< std::string(24, '-') << "\xD9\n\n\t";
        std::cin >> my_input;
        // Hier können einige Menu aufgerufen
        switch (my_input)
        {
        case'1':
            play_menu(field, players);
            break;
        case'2':
            data_menu(players);
            break;
        case'3':
            help();
            system("cls");
            break;
        case'4':
            credits();
            system("cls");
            break;
        case'5':

        case'q':
            std::cout << "\n  END!!\n";
            break;
        default:
            std::cout << "\n  Invalid input!!\n\n";
            system("pause");
            break;
        }
    } while (my_input != 'q' && my_input != 'Q' && my_input != '5');
    
}


// Das Spielfeld wird nach jedem Spielzug zurückgesetzt
void resetField(char* p_field)
{
    for (int j = 0; j < LENGTH; j++)
    {
        // Alle Felder werden auf Leerzeichen gesetzt
        *p_field = ' ';
        p_field++;
    }
}

// Spielerdaten eingeben
void input_player(struct player players[],int num_players)
{
    // Es wird überprüft, wie viele Spieler überhaupt extieren
    // Davor muss von der Datei gelesen werden 
    int final = num_players + 2;
    for (int i = num_players ; i < final; i++)
    {
        system("cls");
        std::cout << "\n\nPlayer " << players[i].number << " :\n\nEnter your name : ";
        std::cin >> players[i].name;
        std::cout << "Enter your age: ";
        std::cin >> players[i].age;
        // Falls man Blödsinn eingiibt
        if (players[i].age <= 5)
        {
            std::cout << "\n\tYOU ARE TOO YOUNG!!\n";
            i--;
            system("pause");
            continue;
        }
    }
}

// hier wird das Spielfeld gezeichnet
void drawField(char* p_field)
{
    std::cout << "---------------\n";
    for (int r = 0; r < 3; r++)
    {
        std::cout << " | ";
        for (int c = 0; c < 3; c++)
        {
            std::cout << *p_field << " | ";
            p_field++;

        }
        std::cout << "\n---------------\n";

    }
}
// Hier wird überprüft, ob ein Spieler gewonnen hat
bool checkWin(char field[3][3])
{
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (field[r][0] != ' ' && field[r][0] == field[r][1] && field[r][2] == field[r][1])return true; //horizontal
            else if (field[0][c] != ' ' && field[0][c] == field[1][c] && field[2][c] == field[1][c])return true;// vertikal
           
        }
    }
      if (field[0][0] != ' ' && field[0][0] == field[1][1] && field[2][2] == field[1][1])return true;// diagonall
      if (field[0][2] != ' ' && field[0][2] == field[1][1] && field[2][0] == field[1][1])return true; //diagonall
    
      return false;
}

// Hier wird überprüft, ob das Spiel uentschieden endet 
bool draw_game(char field[3][3])
{
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (field[r][c] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

// Anzeige der Spielregeln für neue Spieler
void help()
{
    system("cls");
    system("color F4");
    std::cout <<"\t" << std::string(60, '*') << "\n\n"
        << " \t What is Tic-tac-toe ? \n\n\n"
        << "\tTic Tac Toe is a classic two-player game that is played on a 3X3 grid.\n\n"
        << "\n\n\tHow is it played ? \n\n"
        << "\tThe game is played by two players\n\n"
        << "\tFirst player is (X) and second player is (O)\n\n"
        << "\tGoal: get three of your symbols in a row (horizontally) ,\n \n"
        << "   \t(vertically) or (diagonally)\n\n"
        <<"\t" << std::string(60, '*') << "\n\n";
       system ("pause");
}

// Hier werden alle angezeigt, die an diesem Projekt gearbeit haben 
void credits()
{
    system("cls");
    system("color 70");
    std::cout << "\t\t"<<std::string(60, '.') << "\n\n\n"
        << "\t\t\tA game created by Mohamad Taha\n\n"
        << "\t\t\tCopyright (c) 2025 Orignall_games_studios\n\n\n";

    std::cout << "\t\t\tSPECIAL THANKS:\n\n"
        << "\t\t\tMr. John\n"
        << "\t\t\tMy IT class\n"
        << "\t\t\tMy cat\n";
    std::cout << "\t\t" << std::string(60, '.') << "\n\n\n";
    system("PAUSE");
}
