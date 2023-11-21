#include "MAP.h"
using namespace std;
const int n = 10;//������ �����
const int N = n * 2;//������ ������� �����

void MAP::placementShip(int mymap[10][10], int shipLength, int numships, int& shipsID, int shiplives[20])
{
    /////// //���������� � ������
    int direction = 0;//��������� ����������
    int x = 2, y = 2;//��������� ����������
    int moving;//����������� �������� �������

    while (numships > 0)
    {
        showShip(mymap, x, y, direction, shipLength);//��������������� ������ �������
        int new_x = x;//���������� ��������� ���������
        int new_y = y;
        int new_direction = direction;
        moving = _getch();// ���� ����������
        switch (moving)
        {
        case 100://������
            x++;
            break;
        case 115://����
            y++;
            break;
        case 97://�����
            x--;
            break;
        case 119://�����
            y--;
            break;
        case 114://����� �����������
            direction = !direction;
            break;
        case 13://��������� �������
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
void MAP::showShip(int mymap[10][10], int x, int y, int direction, int shipLength) //��������������� ������ �������
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
    for (int i = 0; i < n; i++)//������ ������� ��������
    {
        cout << i;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i;//������ ������������ ��������
        for (int j = 0; j < n; j++)
        {
            if (copymap[j][i] >= 1)//������ ����������� �����
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
                cout << '-';// ������ ��� �������
            }
        }
        cout << endl;
    }
}
bool MAP::setship(int map[10][10], int x, int y, int direction, int shipLength, int& shipsID, int shiplives[20])//�������� ����������� � ����������� �������
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
bool MAP::shipinmap(int x, int y, int direction, int shipLength)//������ �� ������� �� ����� �����
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
void MAP::printMyMap(int map[10][10])// ������ ����� ����������
{
    cout << " ";
    for (int i = 0; i < n; i++)//������ ������� ��������
    {
        cout << i;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i;//������ ������������ ��������
        for (int j = 0; j < n; j++)
        {
            if (map[j][i] >= 1)//������ ����� �����
            {
                cout << "S";
            }
            else if (map[j][i] == -1)//������ ����������� �����
            {
                cout << "X";
            }

            else
            {
                cout << '-';// ������ ��� �������
            }
        }
        cout << endl;
    }
}
void MAP::printEnemyMap(int mask[10][10])// ������ ����� ����������
{
    cout << " ";
    for (int i = 0; i < n; i++)//������ ������� ��������
    {
        cout << i;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i;//������ ������������ ��������
        for (int j = 0; j < n; j++)
        {
            if (mask[j][i] == -1)//������ ����������� �����
            {
                cout << "x";
            }
            else if (mask[j][i] == -2)//������ ���������
            {
                cout << ".";
            }
            else
            {
                cout << '-';// ������ ��� �������
            }
        }
        cout << endl;
    }
}
void MAP::placementShipRand(int map[10][10], int shipLength, int numships, int& shipsID, int shiplives[20])//��������� ������� � ��������� �����
{
    int x, y;// ����������� ��������� ���������� �������
    int direction = 0;// ��������� ����������� 0-������ 1-���� 2-����� 3-�����
    int countship = 0;// ������� ��� ���������� ��������
    int countmax = 0;// ������� ��� ������������ ��� �������������
    while (countship < numships)//���� ���-�� ���������� < ���-�� ������� �������� 
    {
        //�������� �� ������������
        countmax++;
        if (countmax > 1000)
        {
            break;
        }
        //����������� ��������� ���������
        x = rand() % n;
        y = rand() % n;
        int x_new = x;
        int y_new = y;
        //������������ ���������� ����������
        direction = rand() % 4;

        //��������� ����������� ���������� �������
        bool settingPossible = 1;

        for (int i = 0; i < shipLength; i++) {
            if (x<0 or x>10 or y<0 or y>n) //���� x ��� y ������� �� �������
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
                map[x - 1][y - 1] >= 1)//�������� �� ������ �� ������
            {
                settingPossible = 0;
                break;
            }
            // ��������� ��������� ��� ��������
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
        }// ��������� ������� ���� ������ ��������
        if (settingPossible) {
            //���������� x � y � ����������� ���������
            x = x_new;
            y = y_new;

            shiplives[shipsID] = shipLength;// ����������� ���-�� ����� �������� �� id

            for (int i = 0; i < shipLength; i++)
            {
                map[x][y] = shipsID;//���������� ����� ����� �������
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

            shipsID++;// ��������� ����� 
            countship++;//+����������� �������
        }
    }
}

