#pragma once
#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>

struct MAP
{

    void placementShipRand(int map[10][10], int shipLength, int numships, int& shipsID, int shiplives[20]);
    void printEnemyMap(int mask[10][10]);
    void printMyMap(int map[10][10]);
    bool shipinmap(int x, int y, int direction, int shipLength);
    bool setship(int map[10][10], int x, int y, int direction, int shipLength, int& shipsID, int shiplives[20]);
    void showShip(int mymap[10][10], int x, int y, int direction, int shipLength);
    void placementShip(int mymap[10][10], int shipLength, int numships, int& shipsID, int shiplives[20]);
};
