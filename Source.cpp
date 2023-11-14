#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;
const int n = 10;
int shipsID = 1;
int ships[n] = { 0 };

void placementShip(int map[n][n], int shipLength, int numships)
{
    int x, y;
    int direction = 0;
    int countship = 0;
    int countmax = 0;
    while (countship < numships)
    {
        countmax++;
        if (countmax > 100)
        {
            break;
        }
        //первичная позиция
        x = rand() % n;
        y = rand() % n;
        int x_new = x;
        int y_new = y;
        //генерация напрвления
        direction = rand() % 4;
        //постойка корабля
        //проверкка возможности постановки корабля
        bool settingPossible = 1;

        for (int i = 0; i < shipLength; i++) {
            if (x<0 or x>n and y<0 or y>n) {
                settingPossible = 0;
                break;
            }
            if (map[x][y] >= 1 or map[x][y + 1] >= 1 or map[x][y - 1] >= 1 or map[x + 1][y] >= 1 or map[x + 1][y + 1] >= 1 or map[x + 1][y - 1] >= 1 or map[x - 1][y] >= 1 or map[x - 1][y + 1] >= 1 or map[x - 1][y - 1] >= 1)
            {
                settingPossible = 0;
                break;
            }
            switch (direction)
            {
            case 0:
                x++;
                break;
            case 1:
                y++;
                break;
            case 2:
                x--;
                break;
            case 4:
                y--;
                break;
            }
        }
        if (settingPossible) {
            x = x_new;
            y = y_new;
            for (int i = 0; i < shipLength; i++)
            {
                map[x][y] = shipsID;
                switch (direction)
                {
                case 0:
                    x++;
                    break;
                case 1:
                    y++;
                    break;
                case 2:
                    x--;
                    break;
                case 4:
                    y--;
                    break;
                }
            }
            ships[shipsID] = shipLength;
            shipsID++;
            countship++;
        }
    }
}
void print(int map[n][n], int mask[n][n])
{
    cout << " ";
    for (int i = 0; i < n; i++)
    {
        cout << i;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i;
        for (int j = 0; j < n; j++)
        {
            //if (mask[j][i]==1)
            //{
            if (map[j][i] >= 1)
            {
                cout << map[j][i];
            }
            else if (map[j][i] == -1)
            {
                cout << "x";
            }
            else
            {
                cout << '-';
            }
            //}
            // else{
             //cout << ' ';
              /// }   

        }
        cout << endl;
    }
}
//void gotoxy(int x, int y) {
//    COORD p = { x,y };
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
void showship(int x, int y, int dir, int shipLength) {
    for (int i = 0; i < shipLength; i++)
    {
        //gotoxy(x + 1, y + 1);
        cout << "#";
        switch (dir)
        {
        case 0:
            x++;
            break;
        case 1:
            y++;
            break;
        case 2:
            x--;
            break;
        case 4:
            y--;
            break;
        }
    }
}
bool shipinmap(int x, int y, int dir, int shipLength)
{
    bool inmap = 1;

    for (int i = 0; i < shipLength; i++) {
        if (x<0 or x>n and y<0 or y>n) {
            inmap = 0;
            break;
        }

        switch (dir)
        {
        case 0:
            x++;
            break;
        case 1:
            y++;
            break;
        case 2:
            x--;
            break;
        case 4:
            y--;
            break;

        }
    }

    return inmap;
}
bool setship(int map[n][n], int x, int y, int dir, int shipLength)
{
    int x_new = x;
    int y_new = y;
    bool settingPossible = 1;

    for (int i = 0; i < shipLength; i++) {
        if (x<0 or x>n and y<0 or y>n) {
            settingPossible = 0;
            break;
        }

        if (map[x][y] >= 1)
        {
            settingPossible = 0;
            break;
        }

        if (y < n - 1)
        {
            if (map[x][y + 1] >= 1)
            {
                settingPossible = 0;
                break;
            }
        }
        if (y > 0)
        {
            if (map[x][y - 1] >= 1)
            {
                settingPossible = 0;
                break;
            }
        }
        if (x < n - 1)
        {
            if (map[x + 1][y] >= 1)
            {
                settingPossible = 0;
                break;
            }
        }
        if (y < n - 1 and x < n - 1)
        {
            if (map[x + 1][y + 1] >= 1)
            {
                settingPossible = 0;
                break;
            }
        }
        if (x < n - 1 and y>0)
        {
            if (map[x + 1][y - 1] >= 1)
            {
                settingPossible = 0;
                break;
            }
        }

        if (x > 0)
        {
            if (map[x - 1][y] >= 1)
            {
                settingPossible = 0;
                break;
            }
        }

        if (x > 0 and y < n - 1)
        {
            if (map[x - 1][y + 1] >= 1)
            {
                settingPossible = 0;
                break;
            }
        }
        if (x > 0 and y > 0)
        {
            if (map[x - 1][y - 1] >= 1)
            {
                settingPossible = 0;
                break;
            }
        }

    }

    switch (dir)
    {
    case 0:
        x++;
        break;
    case 1:
        y++;
        break;
    case 2:
        x--;
        break;
    case 4:
        y--;
        break;
    }
}
if (settingPossible) {
    x = x_new;
    y = y_new;
    for (int i = 0; i < shipLength; i++)
    {
        map[x][y] = shipsID;
        switch (dir)
        {
        case 0:
            x++;
            break;
        case 1:
            y++;
            break;
        case 2:
            x--;
            break;
        case 4:
            y--;
            break;
        }
    }
    ships[shipsID] = shipLength;
    shipsID++;
}
return settingPossible;
}
int main()
{
    srand(time(NULL));
    const int n = 10;
    int map[n][n] = { {0 };
    int mymap[n][n] = {0 };
    int mask[n][n];
    int shipLength = 4;
    int numships = 3;
    int dir = 0;
    int X = 0, Y = 0;
    int kuda;
    //растановка в ручную
    while (true)
    {
        print(map, mask);
        showship(X, Y, dir, shipLength);

        int newx = X;
        int newy = Y;
        int newdir = dir;
        kuda = _getch();
        switch (kuda)
        {
        case 100://d
            X++;
            break;
        case 115:///s
            Y++;
            break;
        case 97://a
            X--;
            break;
        case 119://w
            Y--;
            break;
        case 114:
            dir = !dir;
            break;
        case 13://установка корабля
            if (setship(map, X, Y, dir, shipLength))
            {
                X = 0;
                Y = 0;
                dir = 0;
                shipLength--;
            }
            break;

        }
        if (!shipinmap(X, Y, dir, shipLength))
        {
            X = newx;
            Y = newy;
            dir = newdir;
        }

        system("cls");
    }



    //игра
    while (true)
    {
        int x = 0, y = 0;
        cout << "введите координаты ";
        cin >> x >> y;

        if (map[x][y] >= 1)
        {
            ships[map[x][y]]--;
            if (ships[map[x][y]] <= 0)
            {
                cout << "убит";

            }
            else
            {
                cout << "ранен";
                print(map, mask);
                //Sleep(2000);
                //system("cls");
                mask[x][y] = -1;
            }
        }
        else {
            cout << "промах";
        }
    }
    //вывод массива
     // _getch();
      //system("cls");//очиска консоли

}