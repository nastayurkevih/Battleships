#include "MAP.h"
using namespace std;
const int n = 10;//размер карты
const int N = n * 2;//размер массива жизни

void MAP::placementShip(int mymap[10][10], int shipLength, int numships, int& shipsID, int shiplives[20])
{
    /////// //растановка в ручную
    int direction = 0;//начальное напрвление
    int x = 2, y = 2;//начальные координаты
    int moving;//направление движения корабля

    while (numships > 0)
    {
        showShip(mymap, x, y, direction, shipLength);//предварительная печать корабря
        int new_x = x;//сохраниние начальных координат
        int new_y = y;
        int new_direction = direction;
        moving = _getch();// ввод напраления
        switch (moving)
        {
        case 100://вправо
            x++;
            break;
        case 115://вниз
            y++;
            break;
        case 97://влево
            x--;
            break;
        case 119://вверх
            y--;
            break;
        case 114://смена направления
            direction = !direction;
            break;
        case 13://установка корабля
            if (setship(mymap, x, y, direction, shipLength, shipsID, shiplives))
            {
                x = 0;
                y = 0;
                direction = 0;
                numships--;
            }
            break;

        }
        if (!shipinmap(x, y, direction, shipLength))
        {
            x = 0;
            y = 0;
            direction = 0;
        }

        system("cls");
    }
    printMyMap(mymap);
    Sleep(1000);
    system("cls");
}
void MAP::showShip(int mymap[10][10], int x, int y, int direction, int shipLength) //предварительная печать корабля
{
    int new_x = x;
    int new_y = y;
    int new_direction = direction;
    int copymap[n][n] = { 0 };
    for (int i = 0; i < shipLength; i++)
    {
        if (mymap[x][y] == 0)
        {
            copymap[x][y] = -1;
        }
        else
        {
            copymap[x][y] = 1;
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
        case 3:
            y--;
            break;
        }
    }
    cout << " ";
    for (int i = 0; i < n; i++)//печать верхних индексов
    {
        cout << i;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i;//печать вертикальных индексов
        for (int j = 0; j < n; j++)
        {
            if (copymap[j][i] >= 1)//печать потопленной части
            {
                cout << "S";
            }
            else if (copymap[j][i] == -1)
            {
                cout << "#";
            }
            else if (mymap[j][i] >= 1)
            {
                cout << "S";
            }
            else
            {
                cout << '-';// печать нет коробля
            }
        }
        cout << endl;
    }
}
bool MAP::setship(int map[10][10], int x, int y, int direction, int shipLength, int& shipsID, int shiplives[20])//проверка возможности и поставление корабля
{
    int x_new = x;
    int y_new = y;
    bool settingPossible = 1;
    for (int i = 0; i < shipLength; i++)
    {
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
        case 3:
            y--;
            break;
        }
    }
    if (settingPossible)
    {
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
            case 3:
                y--;
                break;
            }
        }
        shiplives[shipsID] = shipLength;
        shipsID++;
    }

    return settingPossible;
}
bool MAP::shipinmap(int x, int y, int direction, int shipLength)//корбль не выходит за рамки карты
{
    bool in_map = 1;

    for (int i = 0; i < shipLength; i++) {
        if (x < 0 or x >= n and y < 0 or y >= n) {
            in_map = 0;
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
        case 3:
            y--;
            break;
        }
    }

    return in_map;
}
void MAP::printMyMap(int map[10][10])// печать карты компьютера
{
    cout << " ";
    for (int i = 0; i < n; i++)//печать верхних индексов
    {
        cout << i;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i;//печать вертикальных индексов
        for (int j = 0; j < n; j++)
        {
            if (map[j][i] >= 1)//печать живой части
            {
                cout << "S";
            }
            else if (map[j][i] == -1)//печать потопленной части
            {
                cout << "X";
            }

            else
            {
                cout << '-';// печать нет коробля
            }
        }
        cout << endl;
    }
}
void MAP::printEnemyMap(int mask[10][10])// печать карты компьютера
{
    cout << " ";
    for (int i = 0; i < n; i++)//печать верхних индексов
    {
        cout << i;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i;//печать вертикальных индексов
        for (int j = 0; j < n; j++)
        {
            if (mask[j][i] == -1)//печать потопленной части
            {
                cout << "x";
            }
            else if (mask[j][i] == -2)//печать попадания
            {
                cout << ".";
            }
            else
            {
                cout << '-';// печать нет коробля
            }
        }
        cout << endl;
    }
}
void MAP::placementShipRand(int map[10][10], int shipLength, int numships, int& shipsID, int shiplives[20])//постройка корабля в рандомном месте
{
    int x, y;// началальные рандомные координаты коробля
    int direction = 0;// рандомное направление 0-вправо 1-вниз 2-влево 3-вверх
    int countship = 0;// счётчик для постоенных кораблей
    int countmax = 0;// счетчик для остановления при зацикливаниии
    while (countship < numships)//пока кол-во построеных < кол-во заданых кораблей 
    {
        //проверка от зацикливания
        countmax++;
        if (countmax > 1000)
        {
            break;
        }
        //определение начальных координат
        x = rand() % n;
        y = rand() % n;
        int x_new = x;
        int y_new = y;
        //определениия начального напрвления
        direction = rand() % 4;

        //проверкка возможности постановки корабля
        bool settingPossible = 1;

        for (int i = 0; i < shipLength; i++) {
            if (x<0 or x>10 or y<0 or y>n) //если x или y выходит за границы
            {
                settingPossible = 0;
                break;
            }
            if (map[x][y] >= 1 or
                map[x][y + 1] >= 1 or
                map[x][y - 1] >= 1 or
                map[x + 1][y] >= 1 or
                map[x + 1][y + 1] >= 1 or
                map[x + 1][y - 1] >= 1 or
                map[x - 1][y] >= 1 or
                map[x - 1][y + 1] >= 1 or
                map[x - 1][y - 1] >= 1)//проверка не заниты ли клетки
            {
                settingPossible = 0;
                break;
            }
            // изменения координат для проверки
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
            case 3:
                y--;
                break;
            }
        }// постройка коробля если прошла проверка
        if (settingPossible) {
            //возвращаем x и y к изначальным значениям
            x = x_new;
            y = y_new;

            shiplives[shipsID] = shipLength;// записывание кол-во жизни кооробля по id

            for (int i = 0; i < shipLength; i++)
            {
                map[x][y] = shipsID;//присвоение карте номер корабля
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
                case 3:
                    y--;
                    break;
                }
            }

            shipsID++;// следующий номер 
            countship++;//+построенный корабль
        }
    }
}

