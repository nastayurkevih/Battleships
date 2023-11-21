﻿#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "MAP.h"
#include "Battle.h"

using namespace std;
const int n = 10;//размер карты
const int N = n * 2;//размер массива жизни


int main()
{
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Battle battle;
    MAP Map;
    int map[n][n] = { 0 };// создание карты противника
    int mymap[n][n] = { 0 };//создание своей карты
    int mask[n][n] = {0};// маска для создания тумана войны
    int maskmy[n][n] = {0};
    int shipLength = 4;//длина коробля
    int numships = 4;//колво кораблей заданной длины
    int ShipID = 1;
    int ShipMyID = 1;
    int Shiplives[N] = { 0 };
    int ShiplivesMy[N] = { 0 };
    //battle.playingWithComputer(map,mask, ShipID, Shiplives , mymap, maskmy, ShipMyID, ShiplivesMy, numships);
    cout << endl << endl << "\t ВАС ПРИВЕТСТВУЕТ ИГРА \t" << endl;
    cout << "\t    МОРСКОЙ БОЙ \t" << endl;
    cout << "..^v^\n_____________$…... ^v ^ ..\n____... ^v ^ $$\n_____________$_$$\n_____________$$$ …..... ^ v ^\n _... ^v ^__$$_§§§.\n___________$$$_§§§§§\n___________$_$_§§§§§§ ………..... ^ v ^\n__________$$_$__§§§§§§\n_________$$$_$__§§§§§§§\n________$$$$_$__§§§§§§§§\n_______$$$$$_$__§§§§§§§§\n_____$$$$$$$_$__§§§§§§§§§\n____$$$$$$$$_$_§§§§§§§§§§§\n_$_$$$$$$$$$_$_§§§§§§§§§§§\n_$$_$________$$$_____$$$$$___$$\n__$$$$$$$$$$$$$$$$$$$$$$$_$$$$.\n___$$$$$$$$$$$$$$$$$$$$$$$$$$\n_.. - +*° * -.._ ~~~*° * ~~~_.. - *° * -.._\n~~~_.. - *° * -..~~~~_.. - *° * -.._\n_.. - *~~° * -..__.. - *~~~~° * -.._ * -... - *°\n_.~*° * ~~~~_.. - *~~~~° * -.._ * . - *° * -.._";
    int choise;
    Sleep(2000);
    system("cls");
    cout << "  Если вы не закомы с правилами нажмите i\n" << endl;
    cout << "  Если правила вам знакомы переходим к выбору режима игры.\n " << endl;
    choise = _getch();
    system("cls");
    if (choise == 13)
    {
        battle.Play(map, mask, ShipID, Shiplives, mymap, maskmy, ShipMyID, ShiplivesMy, numships);
    }
    else if (choise == 105)
    {
        cout << "\tПРАВИЛА ИГРЫ\t\n" << endl;
        cout << "1) Вам необходимо делать выстрелы по карте противника, пока один извас не победит.\n";
        cout << "2) На вашем поле символ 'S' означает ваш целый корабль, а 'Х' убитая часть корабля \n";
        cout << "3) На карте противника 'Х' попадание по вражескому караблю, а '.' промах \n";
        cout << "4) Вам будет предложенно 2 режима игры: с компьютером и с противником\n";
        cout << "5) Вам будут предложенно 2 варианта растоновки кораблей: вручную и рандомно\n";
        cout << "\nПриступим к игре? " << endl;
        _getch();
        battle.Play(map, mask, ShipID, Shiplives, mymap, maskmy, ShipMyID, ShiplivesMy, numships);
    }
}


