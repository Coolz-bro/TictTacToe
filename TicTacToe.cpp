#include<iostream>
#include<fstream>
#include"game.h"

void menu(char  field[3][3], struct player spieler[])
{
   
   
    enum mode Mygame;
    char input = ' ';
  
    do
    {
        system("cls");
        std::cout << "\nChose the mod \n"
            << "classic , press(1) \n"
            /* << "costum , press(2) \n"*/
            << "crazy mode, press(2)\n"
            << "Show ranklist, press(3)\n"
            << "looking for somebody, press(4)\n"
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


void play(enum mode Mygame, char field[3][3], struct player spieler[])
{
    std::ofstream add("Daten.bin", std::ios::app); // Man erstellt eine Datei zum Einfuegen von Dateien
    if (!add.is_open())
    {
        std::cerr << "Datei kann nicht geoeffnet werden!!";
        return;
    }
    
    input_player(spieler);
    system("cls"); 

    int i = 0, n = 0, x = 0; // for the wins

    char con_input; // to continue the game

    int row, column;
    bool draw = false;
    for (int loop = 0; loop < Mygame; loop++) // 
    {
        system("cls");
       /* welcome();*/
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

            if (spieler[i].number == 1)
            {
                field[row][column] = 'X';

                if (checkWin(field))
                {
                    system("cls");
                    drawField(&field[0][0]);
                    n++; // you won one match
                    std::cout << "\n\n" << spieler[i].name << "  has won!!\n";
                    spieler[i].wins = n;
                    
                    break;
                }
                else
                {
                    spieler[i].wins = n;
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
                else
                {
                    spieler[i].wins = x;
                }
                i--;
                system("cls");
                drawField(&field[0][0]);
            }
           

        }
        std::cout << "Continue (y)es or (N)o ? ";
        std::cin >> con_input;
        if (spieler[i].wins == spieler[i + 1].wins)
        {
            std::cout << "\n\nDRAW!!!";
            system("pause");
            break;
        }
       
        if (con_input == 'n' || con_input == 'N')
        {
           
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
    

   
    char save_my_progress;
    std::cout << "\nDo you want to save your progress ?,(y)es or (n)o ";
    std::cin >> save_my_progress;
    if (save_my_progress == 'y' || save_my_progress == 'N')
    {
        add << "Name\t\t" << "Age\t\t" << "Wins\t\t" << "Number" << std::endl // hier wird in die Datei geschrieben
            << std::string(55, '-') << std::endl;

        for (int i = 0; i < 2; i++)
        {
            if (spieler[i].wins <= 0)
            {
                spieler[i].wins == 0;
            }
            add << spieler[i].name << "\t\t" << spieler[i].age << "\t\t" << spieler[i].wins << "\t\t" << spieler[i].number << std::endl;

        }
        add.close();// Die Datei wird am Ende geschlossen
    }
    else
    {
        std::cout << "\nBye bye!!\n\n";
    }
}
