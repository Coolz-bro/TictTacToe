
#include <iostream>

using namespace std;

enum mode
{
    classic = 3,
    crazy = 10
};

struct player
{
    int number;
    string name;
    int age;
};

void input_player(struct player spieler[])
{
    for (int i = 0; i < 2; i++)
    {
        cout << " \nYou are player (1) or (2)? ";
        cin >> spieler[i].number;

        if (spieler[i].number != 1 && spieler[i].number != 2)
        {
            cout << "Invalid, try again!!\n";
            i--;
            continue;
        }

        cout << "Enter your name: ";
        cin >> spieler[i].name;
        cout << "Enter your age: ";
        cin >> spieler[i].age;
    }
}

void drewField(char* p_field)
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
bool checkWin(char field[3][3])// rules
{
    for (int z = 0;z < 3;z++)
    {
        for (int s = 0;s < 3;s++)
        {
            if (field[z][0] == 'X' && field[z][1] == 'X' && field[z][2] == 'X')return true;
            else if (field[0][s] == 'X' && field[1][s] == 'X' && field[2][s] == 'X')return true;
            else  if (field[0][0] == 'X' && field[1][1] == 'X' && field[2][2] == 'X')return true;
            else  if (field[0][2] == 'X' && field[1][1] == 'X' && field[2][0] == 'X')return true;
            else if (field[z][0] == 'O' && field[z][1] == 'O' && field[z][2] == 'O')return true;
            else if (field[0][s] == 'O' && field[1][s] == 'O' && field[2][s] == 'O')return true;
            else if (field[0][0] == 'O' && field[1][1] == 'O' && field[2][2] == 'O')return true;
            else if (field[0][2] == 'O' && field[1][1] == 'O' && field[2][0] == 'O')return true;
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
    int i = 0;
  
    int row, column;
    bool draw = false;
    for (int loop = 0; loop < Mygame; loop++)
    {
        cout << "\n\033[6;31;43m Welcome to TICTACTOE\033[0m\n\n"; //for the color 
        drewField(&field[0][0]);
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
                    cout << endl << spieler[i].name << "  has won!!";
                    system("cls");
                    break;
                }
                if (spieler[1].number == 1)
                {
                    i--;
                }
                else

                    i++;

            }
            else if (spieler[i].number == 2)
            {
                field[row][column] = 'O';
                if (checkWin(field))
                {
                    cout << endl << spieler[i].name << "  has won!!\n";
                    break;
                }
                if (spieler[0].number == 2)
                {
                    i++;
                }
                else
                    i--;
            }
            system("cls");
            drewField(&field[0][0]);

        }
    }
}
void menu(char  field[3][3],struct player spieler[])
{
    enum mode Mygame;
    char input=' ';
    do
    {
        cout << "Chose the mod \n"
            << "classic , press(1) \n"
            << "costum , press(2) \n"
            << "crazy mode, press(3)\n"
            << "end game, press (q) or (4) ";
        cin >> input;
        switch (input)
        {
         case'1':
            play(classic,field, spieler);
            break;
       case '2':
            play(crazy, field, spieler);
            break;
       case '3':
           
       case'q':
           cout << "END!!\n\n";
           break;
           
        default:
            cout << "Invalid!!, please try again";
            break;
        }
    } while (input != 'q' && input != 'Q' && input != '3');
}

