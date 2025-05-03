#include<iostream>
#include<fstream>
#include"game.h"
#include<string>

void show_ranklist()
{
    system("cls");
    std::ifstream in("Daten.bin"); // Man erstellt eine Datei zum Lesen
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