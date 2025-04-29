

#include <iostream>
#include"spiel.h"
#include<fstream>
#include<string>
// works like define

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
    for (int r = 0;r < 3;r++)
    {
        std::cout << " | ";
        for (int c = 0;c < 3;c++)
        {
            std::cout << *p_field << " | ";
            p_field++;

        }
        std::cout << "\n---------------\n";

    }
}
bool checkWin(char field[3][3])
{
    for (int r = 0;r < 3;r++)
    {
        for (int c = 0;c < 3;c++)
        {
            if (field[r][0] != ' ' && field[r][0] == field[r][1] && field[r][2] == field[r][1])return true;
            else if (field[0][c] != ' ' && field[0][c] == field[1][c] && field[2][c] == field[1][c])return true;
            else  if (field[0][0] != ' ' && field[0][0] == field[1][1] && field[2][2] == field[1][1])return true;
            else  if (field[0][2] != ' ' && field[0][2] == field[1][1] && field[2][0] == field[1][1])return true;
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
    std::ofstream out;// Eine Datei zum Schreiben erstellen
    out.open("Daten.txt"); // Hier wird die Datei geöffnent
    if (!out)// Wenn man beispielsweise keine Berichtigung hat
    {
        std::cout << "Fehler!!";
        return;
    }
    input_player(spieler);
    system("cls"); // to clear the screen

    int i = 0, n = 0, x = 0;

    char con_input;

    int row, column;
    bool draw = false;
    for (int loop = 0; loop < Mygame; loop++) // 
    {
        welcome();
        resetField(&field[0][0]);
        drawField(&field[0][0]);
        while (true)
        {


            draw = draw_game(field);
            if (draw)
            {
                std::cout << "DRAW!!\n";
                break;
            }
            std::cout << "Player " << spieler[i].number << " enter the row: ";
            std::cin >> row;
            std::cout << "Player " << spieler[i].number << " enter the column: ";
            std::cin >> column;
            if (row >= 3 || row < 0 || column >= 3 || column < 0)
            {
                std::cout << "Invalid input! Try again.\n";
                continue;
            }

            if (field[row][column] != ' ')
            {
                std::cout << "Your field is already set!!\n";
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
                    std::cout << "\n\n" << spieler[i].name << "  has won!!\n";
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
                    std::cout << "\n\n" << spieler[i].name << "  has won!!\n";
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
        std::cout << "\nDo you want to continue ?,(Y)es,(N)o  ";
        std::cin >> con_input;
        if (con_input == 'N' || con_input == 'n')
        {
            if (spieler[0].wins == spieler[1].wins)
            {
                std::cout << "\n\nDRAW!!!";
                system("cls");
                break;
            }

            if (spieler[i].wins > spieler[i + 1].wins)
            {
                std::cout << "\nPlayer 1 won " << spieler[i].wins << " matchs!!\n\n\n";
                system("PAUSE");
                break;
            }
            else
            {
                std::cout << "\nPlayer 2 won  " << spieler[i + 1].wins << " matchs!!";
                system("PAUSE");


                break;
            }


        }
        else
            system("cls");
    }
    
    out << "Name\t\t" << "Age\t\t" << "Wins\t\t" << "Number" << std::endl // hier wird in die Datei geschrieben
        << std::string(55, '-') << std::endl;
    
    for (int i = 0;i < 2;i++)
    {
        if (spieler[i].wins <= 0)
        {
            spieler[i].wins == 0;
        }
        out << spieler[i].name << "\t\t" << spieler[i].age << "\t\t" << spieler[i].wins << "\t\t" << spieler[i].number<<std::endl;
       
    }
    out.close();// Die Datei wird am Ende geschlossen
}

void show_ranklist()
{
    system("cls");
    std::ifstream in("Daten.txt"); // Man erstellt eine Datei zum Lesen
    std::string line; 
    if (in.is_open())
    {
        while (getline(in, line))
        {
            std::cout << line << std::endl;// Man liest Zeile für Zeile
        }
        in.close();// Die Datei wird am Ende geschlossen
    }
    else
        std::cout << "File did not find, try again!!";

}
 
void binary_search(player spieler[])
{
    int num_of_player;
    std::cout << "Enter the num of the player: ";
    std::cin >> num_of_player;
    for (int rund = 0;rund < 2;rund++)
    {
        if (spieler[rund].number == num_of_player)
        {
            std::cout << "His name is " << spieler[rund].name << std::endl;
            break;
        }
    }
   
}

void menu(char  field[3][3], struct player spieler[])
{
    system("cls");
    enum mode Mygame;
    char input = ' ';
    welcome();
    do
    {
        system("cls");
        std::cout << "\nChose the mod \n"
            << "classic , press(1) \n"
            /* << "costum , press(2) \n"*/
            << "crazy mode, press(2)\n"
            << "Show ranklist, press(3)\n"
            <<"looking for somebody, press(4)\n"
            << "end game, press (q) or (5) ";
        std::cin >> input;
        switch (input)
        {
        case'1':
            play(CLASSIC, field, spieler);
            break;
        case '2':
            play(crazy, field, spieler);
            break;
        case'3':
            show_ranklist();
            std::cout << "\n\n";
            system("pause");
            break;
        case'4':
            binary_search(spieler);
            system("pause");
            break;
        case '5':

        case'q':
            std::cout << "\n\nEND!!\n\n";
            break;

        default:
            std::cout << "\nInvalid!!, please try again\n\n";
            break;
        }
    } while (input != 'q' && input != 'Q' && input != '5');
}
