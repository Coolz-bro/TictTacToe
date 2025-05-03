#include <iostream>
#include"game.h"

void resetField(char* p_field)
{
    for (int j = 0; j < LENGTH; j++)
    {
        *p_field = ' ';
        p_field++;
    }
}

void welcome()
{
    std::cout << "\n\033[6;31;43m Welcome to TICTACTOE\033[0m\n\n"; //for the color 
}

void input_player(struct player spieler[])
{
    for (int i = 0; i < 2; i++)
    {

        std::cout << "\n\nPlayer " << spieler[i].number << " :\n\nEnter your name : ";
        std::cin >> spieler[i].name;
        std::cout << "Enter your age: ";
        std::cin >> spieler[i].age;
    }
}

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




void binary_search(player spieler[])
{
    int num_of_player;
    std::cout << "Enter the num of the player: ";
    std::cin >> num_of_player;
    for (int rund = 0; rund < 2; rund++)
    {
        if (spieler[rund].number == num_of_player)
        {
            if (!spieler[rund].name.empty())// hier wird überprüft, ob der Name leer ist
            {
                std::cout << "His name is  " << spieler[rund].name << std::endl;
                break;
            }
            else
                std::cout << "\nA player does not exist \n\n";// du kannst hier eine Farbe hinzufuegen
        }
    }

}

