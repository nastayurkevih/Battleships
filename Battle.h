#pragma once
#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "MAP.h"
struct Battle
{

    MAP Map;
    bool playingAgainst(int map[n][n], int mask[n][n], int mymap[n][n], bool turn, int shiplives[N]);
    void creatPersonMap(int map[n][n], int numships, int& shipsID, int shiplives[N]);
    int WhoWin(int Shiplives[N], int ShiplivesMy[N]);
    void playingwWithEnemy(int map[n][n], int  mask[n][n], int& ShipID, int Shiplives[N], int mymap[n][n], int maskmy[n][n], int& ShipMyID, int  ShiplivesMy[N], int numships);
    void playingWithComputer(int map[n][n], int  mask[n][n], int& ShipID, int Shiplives[N], int mymap[n][n], int maskmy[n][n], int& ShipMyID, int  ShiplivesMy[N], int numships);
    bool playingCompicter(int map[n][n], int mask[n][n], bool turn, int shiplives[N]);
    void Play(int map[n][n], int  mask[n][n], int& ShipID, int Shiplives[N], int mymap[n][n], int maskmy[n][n], int& ShipMyID, int  ShiplivesMy[N], int numships);
};
