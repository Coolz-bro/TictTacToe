#pragma once

#include <iostream>

using namespace std;

// works like define
enum mode
{
    CLASSIC = 3,
    crazy = 10,
    LENGTH=9 
};

struct player
{
    int number;
    string name;
    int age;
    int wins;
};

void resetField(char* p_field)
{
    for (int j = 0;j < LENGTH;j++)
    {
        *p_field = ' ';
        p_field++;
    }
}
void welcome()
{
    cout << "\n\033[6;31;43m Welcome to TICTACTOE\033[0m\n\n"; //for the color 
}
void input_player(struct player spieler[])
{
    for (int i = 0; i < 2; i++)
    {
       
        cout << "\n\nPlayer " << spieler[i].number << " :\n\nEnter your name : ";
        cin >> spieler[i].name;
        cout << "Enter your age: ";
        cin >> spieler[i].age;
    }
}

void drawField(char* p_field)
{
    cout << "---------------\n";
    for (int r = 0;r < 3;r++)
    {
        cout << " | ";
        for (int c = 0;c < 3;c++)
        {
            cout << *p_field << " | ";
            p_field++;

        }
        cout << "\n---------------\n";

    }
}
bool checkWin(char field[3][3])
{
    for (int r = 0;r < 3;r++)
    {
        for (int c = 0;c < 3;c++)
        {
                if (field[r][0]!=' '&&field[r][0] == field[r][1] && field[r][2] == field[r][1])return true;
                else if (field[0][c]!=' '&&field[0][c] == field[1][c] && field[2][c] == field[1][c])return true;
                else  if (field[0][0]!=' '&&field[0][0] == field[1][1] && field[2][2] == field[1][1])return true;
                else  if (field[0][2]!=' '&&field[0][2] == field[1][1] && field[2][0] == field[1][1])return true;
        }
    }

    return false;
}
bool draw_game(char field[3][3])
{
    for (int r = 0;r < 3;r++)
    {
        for (int c = 0;c < 3;c++)
        {
            if (field[r][c] == ' ') 
            {
                return false;
            }
        }
    }
    return true;
}

void play(enum mode Mygame, char field[3][3], struct player spieler[2])
{
    input_player(spieler);
    system("cls"); // to clear the screen
    int i = 0,n=0,x=0;
    char con_input;
    int row, column;
    bool draw = false;
    for (int loop = 0; loop < Mygame; loop++)
    {
        welcome();
        resetField(&field[0][0]);
        drawField(&field[0][0]);
        while (true)
        {
        

            draw = draw_game(field);
            if (draw)
            {
                cout << "DRAW!!\n";
                break;
            }
            cout << "Player " << spieler[i].number << " enter the row: ";
            cin >> row;
            cout << "Player " << spieler[i].number << " enter the column: ";
            cin >> column;

            if (row >= 3 || row < 0 || column >= 3 || column < 0)
            {
                cout << "Invalid input! Try again.\n";
                continue;
            }

            if (field[row][column] != ' ')
            {
                cout << "Your field is already set!!\n";
                continue;
            }

            if (spieler[i].number == 1)
            {
                field[row][column] = 'X';
               
                if (checkWin(field))
                {
                    system("cls");
                    drawField(&field[0][0]);
                    n++;
                    cout << "\n\n" << spieler[i].name << "  has won!!\n";
                    spieler[i].wins = n;
                   
                    break;
                }
                i++;
                    system("cls");
                    drawField(&field[0][0]);
               
            }
            else if (spieler[i].number == 2)
            {
                field[row][column] = 'O';
               
                if (checkWin(field))
                {
                    system("cls");
                    drawField(&field[0][0]);
                    x++;
                    cout << "\n\n" << spieler[i].name << "  has won!!\n";
                    spieler[i].wins = x;
                    break;
                }
                i--;
            }
            system("cls");
            drawField(&field[0][0]);

        }
        /*if (spieler[i].wins == 2 || spieler[i + 1].wins == 2)
        {
            if (spieler[i].wins > spieler[i + 1].wins)
            {
                cout << "\nPlayer 1 won " << spieler[i].wins << " matchs!!\n\n\n";
            }
            else
                cout << "\nPlayer 2 won  " << spieler[i + 1].wins << " matchs!!";
            break;
        }*/
        cout << "\nDo you want to continue ?,(Y)es,(N)o  ";
        cin >> con_input;
        if (con_input == 'N' || con_input == 'n')
        {
            if (spieler[0].wins == spieler[1].wins)
            {
                cout << "\n\nDRAW!!!";
                break;
            }

            if (spieler[i].wins > spieler[i + 1].wins)
            {
                cout << "\nPlayer 1 won " << spieler[i].wins << " matchs!!\n\n\n";
                break;
            }
            else
            {
                cout << "\nPlayer 2 won  " << spieler[i + 1].wins << " matchs!!";
                break;
            }
         
            
        }
        else
            system("cls");
    }
}
void menu(char  field[3][3],struct player spieler[])
{
    system("cls");
    enum mode Mygame;
    char input=' ';
    welcome();
    do
    {
        system("cls");
        cout << "\nChose the mod \n"
            << "classic , press(1) \n"
           /* << "costum , press(2) \n"*/
            << "crazy mode, press(2)\n"
            << "end game, press (q) or (3) ";
        cin >> input;
        switch (input)
        {
         case'1':
            play(CLASSIC,field, spieler);
            break;
       case '2':
            play(crazy, field, spieler);
            break;
       case '3':
           
       case'q':
           cout << "\n\nEND!!\n\n";
           break;
           
        default:
            cout << "\nInvalid!!, please try again\n\n";
            break;
        }
    } while (input != 'q' && input != 'Q' && input != '3');
}

