#include<iostream>
#include<stdio.h>
#include"save.h"
#include"game.h"

void play_menu(char  field[3][3], struct player players[])
{
    int num_players=0;
    set_ready(players, num_players);
    players[num_players].number = 1; // Das ist 'X'  
    players[num_players + 1].number = 2; // 'O'
    system("cls");
    enum mode Mygame;
    char input = ' ';
   
    do
    {
        // Hier wählt man den Spielmodus aus.
        // Die Modi unterscheiden sich in der Anzahl der Spielrunden.
        system("color f0");
        std::cout << "\n\n\t\tPLAY_MENU\n";
        std::cout << "\n\tChoose your mode\n"
            << "\tclassic , press(1) \n"
            << "\tcrazy mode, press(2)\n"
            << "\tend game, press (q) or (3)\n\t";
        std::cin >> input;
        switch (input)
        {
       
        case'1':
            play(CLASSIC, field, players,num_players);
            break;
        case '2':
            play(CRAZY, field, players,num_players);
            break;

        case '3':

        case'q':
            std::cout << "\n\n\tEND!!\n\n";
            break;

        default:
            std::cout << "\nInvalid!!, please try again\n\n";
            break;
        }
    } while (input != 'q'  && input != 'Q' && input != '3');
}

// Das ist das eigentliche Spiel
void play(enum mode Mygame, char field[3][3], struct player players[],int num_players)
{
   
    FILE* add; // Deklaration einer Datei vom Typ FILE
    int result = fopen_s(&add, "Players.csv", "a"); // Die Datei wird geöffnet (Rückgabewert vom Typ int)
    int final = num_players + 2; // später fürs Schreiben in die Datei
    int i = num_players, n = 0, x = 0;
    // 'i' wird auf die Anzahl der Spieler gesetzt, damit man Fehler vermeiden kann
    // 'n' und 'x' sind für die Anzahl der Siege gedacht
   
    if (result != 0) // hier wird überprüft, ob das Oeffnen der Datei gelungen ist
    {
        std::cerr << "Your File can not be open !";
        return;
    }

    
    system("cls");
    std::cout << "\n\n";
    input_player(players,num_players); // Hier werden die Daten eingelesen
    for (int loop = num_players;loop < final;loop++)
    {
        players[loop].ID = loop + 1; // Jeder Spieler erhält eine eindeutige ID
    }
    system("cls");
    
    
  

    char con_input; // Abfrage, ob man mit dem Spiel fortfahren moechte
   
    int row, column; // Zeile und Spalte
    bool draw = false;
    int last_round;
    last_round = Mygame; // hier wird die Anzahl der Spieldurchläufe  gespeichert

    for (int loop = 0; loop < Mygame; loop++) // Das Spiel je nachdem, welchen Modus man ausgewählt hat
    {
        system("cls");
        // hier wird das Spiel vorbereitet
        resetField(&field[0][0]); 
        drawField(&field[0][0]);
        while (true)
        {
            draw = draw_game(field);
             // Man überprüft hier, ob das Spiel unentscheiden endet
            if (draw)
            {
                std::cout << "DRAW!!\n";
                break;
            }
            std::cout << "Player " << players[i].number << " enter the row: ";
            std::cin >> row;
            std::cout << "Player " << players[i].number << " enter the column: ";
            std::cin >> column;
            if (row >= 3 || row < 0 || column >= 3 || column < 0)
            {
                std::cout << "Invalid input! Try again.\n";
                continue;
            }

            if (field[row][column] != ' ') // Man überprüft, ob das Feld leer ist
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
                    n++; // Wenn Spieler 'X' eine Runde gewonnen hat
                    std::cout << "\n\n" << players[i].name << "  has won!!\n";
                    players[i].wins = n; // Die Siege werden hier abgespeichert

                    break;
                }
                else
                {
                    players[i].wins = n; // Hier wird ein Wert übergeben
                }
                i++;// Der Spielerwechsel erfolgt
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
       
        if ((players[i].wins == players[i + 1].wins) && loop==last_round) // Überprüfung auf Gleichstand der Siege
        {
            std::cout << "\n\nDRAW!!!";
            system("pause");
            break;
        }
        std::cout << "Continue (y)es or (N)o ? ";
        std::cin >> con_input;
        if (con_input == 'n' || con_input == 'N')
        {
            // hier wird angezeigt, wer am meisten gewonnen hat 
            if (players[0].wins > players[1].wins)
            {
                std::cout << "\nPlayer 1 won " << players[i].wins << " matches!!\n\n\n";
                system("PAUSE");
                break;
            }
            else 
            {
                std::cout << "\nPlayer 2 won " << players[i].wins << " matches!!\n\n\n";
                system("PAUSE");
                break;
            }
        }

        //Wenn ein Spieler drei Mal gewonnen hat
        else if ((con_input == 'y' || con_input == 'Y') && (players[i].wins == 3 || players[i + 1].wins == 3) && (loop == last_round))
        {
            std::cout << "Player " << players[i].number << " has won " << players[i].wins << "matchs!!";
            system("pause");
            break;
        }
        else
            system("cls");
    }

    // Die Spielergebnisse werden hier gespeichert
    char save_my_progress;
    std::cout << "\nDo you want to save your progress ?,(y)es or (n)o ";
    std::cin >> save_my_progress;
    if (save_my_progress == 'y' || save_my_progress == 'Y')
    {
        for (int k = num_players; k < final; k++) 
        {
            fprintf_s(add, "%s\t%i\t%i\t%i\n", players[k].name, players[k].age, players[k].wins,players[k].ID); // hier werden die Daten (Formatiert) in die Datei geschrieben
        }
        fclose(add); // Die Datei wird geschlossen
        system("cls");
    }
    else
    {
        std::cout << "\nBye bye!!\n\n";
        system("pause");
    }
}


