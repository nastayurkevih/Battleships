#pragma once
#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "Battle.h"
struct MAP
{

    void placementShipRand(int map[n][n], int shipLength, int numships, int& shipsID, int shiplives[N]);
    void printEnemyMap(int mask[n][n]);
    void printMyMap(int map[n][n]);
    bool shipinmap(int x, int y, int direction, int shipLength);
    bool setship(int map[n][n], int x, int y, int direction, int shipLength, int& shipsID, int shiplives[N]);
    void showShip(int mymap[n][n], int x, int y, int direction, int shipLength);
    void placementShip(int mymap[n][n], int shipLength, int numships, int& shipsID, int shiplives[N]);
};
