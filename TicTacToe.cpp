#include<iostream>
#include<stdio.h>
#include"game.h"

void play_menu(char  field[3][3], struct player players[])
{

    system("cls");
    enum mode Mygame;
    char input = ' ';
   
    do
    {
        system("color f0");
        std::cout << "\nChose the mod \n"
            << "classic , press(1) \n"
            << "crazy mode, press(2)\n"
            << "end game, press (q) or (3) ";
        std::cin >> input;
        switch (input)
        {
        case'1':
            play(CLASSIC, field, players);
            break;
        case '2':
            play(crazy, field, players);
            break;

        case '3':

        case'q':
            std::cout << "\n\nEND!!\n\n";
            break;

        default:
            std::cout << "\nInvalid!!, please try again\n\n";
            break;
        }
    } while (input != 'q'  && input != 'Q' && input != '3');
}

// Das ist das eigentliche Spiel
void play(enum mode Mygame, char field[3][3], struct player players[])
{
    FILE* add; // deklaration einer Datei vom Typ FILE
    int result = fopen_s(&add, "Players.txt", "w"); // Datei wird geoeffnet (Rückgabewert(int))
   
    if (result != 0) // hier wird überprüft, ob das Oeffnen der Datei gelungen ist
    {
        std::cerr << "Your File can not be open !";
        return;
    }

    input_player(players);
    system("cls");

    int i = 0, n = 0, x = 0; // Laufvariabeln

    char con_input; // Abfrage, ob man mit dem Spiel fortfahren moechte

    int row, column;
    bool draw = false;
    for (int loop = 0; loop < Mygame; loop++) // 
    {
        system("cls");

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
            std::cout << "Player " << players[i].number << " enter the row: ";
            std::cin >> row;
            std::cout << "Player " << players[i].number << " enter the column: ";
            std::cin >> column;
            if (row >= 3 || row < 0 || column >= 3 || column < 0)// Fix this
            {
                std::cout << "Invalid input! Try again.\n";
                continue;
            }

            if (field[row][column] != ' ')
            {
                std::cout << "Your field is already set!!\n";
                continue;
            }

            if (players[i].number == 1)
            {
                field[row][column] = 'X';

                if (checkWin(field))
                {
                    system("cls");
                    drawField(&field[0][0]);
                    n++; // you won one match
                    std::cout << "\n\n" << players[i].name << "  has won!!\n";
                    players[i].wins = n;

                    break;
                }
                else
                {
                    players[i].wins = n; // hier wird einen Wert übergeben 
                }
                i++;// abwechslung
                system("cls");
                drawField(&field[0][0]);

            }
            else if (players[i].number == 2)
            {
                field[row][column] = 'O';

                if (checkWin(field))
                {
                    system("cls");
                    drawField(&field[0][0]);
                    x++;
                    std::cout << "\n\n" << players[i].name << "  has won!!\n";
                    players[i].wins = x;

                    break;
                }
                else
                {
                    players[i].wins = x;
                }
                i--;
                system("cls");
                drawField(&field[0][0]);
            }


        }
        std::cout << "Continue (y)es or (N)o ? ";
        std::cin >> con_input;
        if (players[i].wins == players[i + 1].wins)
        {
            std::cout << "\n\nDRAW!!!";
            system("pause");
            break;
        }

        if (con_input == 'n' || con_input == 'N')
        {
            // hier wird angezeigt, wer am meisten gewonnen hat 
            if (players[i].wins > players[i + 1].wins)
            {
                std::cout << "\nPlayer 1 won " << players[i].wins << " matchs!!\n\n\n";
                system("PAUSE");
                break;
            }
            else
            {
                std::cout << "\nPlayer 2 won  " << players[i + 1].wins << " matchs!!";
                system("PAUSE");
                break;
            }
        }
        else if ((con_input == 'y' || con_input == 'Y') && (players[i].wins == 3 || players[i + 1].wins == 3))
        {
            std::cout << "Player " << players[i].number << " has won " << players[i].wins << "matchs!!";
            system("pause");
            break;
        }
        else
            system("cls");
    }

    // hier werden die Ergebnisse gespeichert
    char save_my_progress;
    std::cout << "\nDo you want to save your progress ?,(y)es or (n)o ";
    std::cin >> save_my_progress;
    if (save_my_progress == 'y' || save_my_progress == 'N')
    {
        for (int k = 0; k < 2; k++)
        {
            fprintf_s(add, "%s\t%i\t%i\n", players[k].name, players[k].age, players[k].wins); // hier werden die Daten (Formatiert) in die Datei geschrieben
        }
        fclose(add);
    }
    else
    {
        std::cout << "\nBye bye!!\n\n";
    }
}