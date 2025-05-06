#include <iostream>
#include"game.h"

void main_menu(char field[3][3], player players[])
{
   
   
    char my_input;
    
    do {
        system("cls");
        std::cout << "\n   WELCOME TO TICTACTOE !! \n\n";
        system("color e0");
        std::cout <<" "<< std::string(25, '-') << std::endl
            << " |   Enter a number\t |\n"
            << " |   PLAY (1)\t\t |\n"
            << " |   PLAYERS_Data (2)\t |\n"
            << " |   HELP (3)\t\t |\n"
            << " |   Credits (4)\t |\n"
            << " |   Quit (5)\t\t |\n"
            << " "<< std::string(25, '-') << "\n  ";
        std::cin >> my_input;
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


// Das Feld wir dadurch leer
void resetField(char* p_field)
{
    for (int j = 0; j < LENGTH; j++)
    {
        *p_field = ' ';
        p_field++;
    }
}



// Eingabe der Daten eines Spielers
void input_player(struct player players[])
{
    for (int i = 0; i < 2; i++)
    {

        std::cout << "\n\nPlayer " << players[i].number << " :\n\nEnter your name : ";
        std::cin >> players[i].name;
        std::cout << "Enter your age: ";
        std::cin >> players[i].age;
        

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
// hier wird überpruft, ob ein Spieler gewonnen hat
bool checkWin(char field[3][3])
{
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (field[r][0] != ' ' && field[r][0] == field[r][1] && field[r][2] == field[r][1])return true; //horizontal
            else if (field[0][c] != ' ' && field[0][c] == field[1][c] && field[2][c] == field[1][c])return true;// vertikal
            else  if (field[0][0] != ' ' && field[0][0] == field[1][1] && field[2][2] == field[1][1])return true;// diagonall
            else  if (field[0][2] != ' ' && field[0][2] == field[1][1] && field[2][0] == field[1][1])return true; //diagonall
        }
    }

    return false;
}

// falls das Spiel Unentschieden endet
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


void help()
{
    system("cls");
    system("color e4");
    std::cout <<"\t" << std::string(60, '*') << "\n\n"
        << " \t\t What is Tic-tac-toe ? \n\n\n"
        << "\t\tTic Tac Toe is a classic two-player game that is played on a 3X3 grid.\n\n"
        << "\n\n\t\tHow is it played ? \n\n"
        << "\t\tThe game is played by two players\n\n"
        << "\t\tFirst player is (X) and second player is (O)\n\n"
        << "\t\tGoal: get three of your symbols in a row (horizontally) ,\n \n"
        << "   \t\t(vertically) or (diagonally)\n\n"
        <<"\t" << std::string(60, '*') << "\n\n";
       system ("pause");
}

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
