#pragma once
#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "MAP.h"
struct Battle
{

    MAP Map;
    bool playingAgainst(int map[10][10], int mask[10][10], int mymap[10][10], bool turn, int shiplives[20]);
    void creatPersonMap(int map[10][10], int numships, int& shipsID, int shiplives[20]);
    int WhoWin(int Shiplives[20], int ShiplivesMy[20]);
    void playingwWithEnemy(int map[10][10], int  mask[10][10], int& ShipID, int Shiplives[20], int mymap[10][10], int maskmy[10][10], int& ShipMyID, int  ShiplivesMy[20], int numships);
    void playingWithComputer(int map[10][10], int  mask[10][10], int& ShipID, int Shiplives[20], int mymap[10][10], int maskmy[10][10], int& ShipMyID, int  ShiplivesMy[20], int numships);
    bool playingCompicter(int map[10][10], int mask[10][10], bool turn, int shiplives[20]);
    void Play(int map[10][10], int  mask[10][10], int& ShipID, int Shiplives[20], int mymap[10][10], int maskmy[10][10], int& ShipMyID, int  ShiplivesMy[20], int numships);
};
