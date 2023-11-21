#include "Battle.h"
using namespace std;
const int n = 10;//������ �����
const int N = n * 2;//������ ������� �����

void Battle::Play(int map[10][10], int  mask[10][10], int& ShipID, int Shiplives[20], int mymap[10][10], int maskmy[10][10], int& ShipMyID, int  ShiplivesMy[20], int numships)
{
    string name;
    string nameMy;
    int Win = 0;
    while (Win == 0)
    {
        system("cls");
        int coise1;
        cout << "����� 1 : ���� ������ ���������.\t" << "����� 2 : ���� � �����������." << endl;
        cout << "��� �����: ";
        cin >> coise1;
        if (coise1 == 1)
        {
            cout << "������� ���� ��� :";
            cin >> nameMy;
            name = "���������";
            system("cls");
            playingWithComputer(map, mask, ShipID, Shiplives, mymap, maskmy, ShipMyID, ShiplivesMy, numships);
        }
        else
        {
            cout << "��� ������� ������ : ";
            cin >> nameMy;
            std::cout << "��� ������� ������ :";
            cin >> name;
            playingwWithEnemy(map, mask, ShipID, Shiplives, mymap, maskmy, ShipMyID, ShiplivesMy, numships);
        }
        Win = WhoWin(Shiplives, ShiplivesMy);
    }
    system("cls");
    if (Win == 2)
    {
        cout << "\n\t������� " << nameMy << "!!!" << endl;
        cout << "" << nameMy << endl;
        Map.printMyMap(mymap);
        cout << "" << name << endl;
        Map.printMyMap(map);
    }
    else
    {
        cout << "\n\t ������� " << name << "!!!" << endl;
        cout << "" << name << endl;
        Map.printMyMap(map);
        cout << "" << nameMy << endl;
        Map.printMyMap(mymap);
    }
    _getch();
}
void Battle::playingWithComputer(int map[10][10], int  mask[10][10], int& ShipID, int Shiplives[20], int mymap[10][10], int maskmy[10][10], int& ShipMyID, int  ShiplivesMy[20], int numships)
{

    for (int i = 1; i < numships + 1; i++)
    {
        Map.placementShipRand(map, numships - i + 1, i, ShipID, Shiplives);
    }
    creatPersonMap(mymap, numships, ShipMyID, ShiplivesMy);
    bool turn = 1;

    cout << "\n\n****���������� ����******" << endl;
    Sleep(2000);
    int win = 0;
    while (win == 0)
    {
        system("cls");
        if (turn)
        {
            cout << "  ��� ���  ";
            turn = playingAgainst(map, mask, mymap, turn, Shiplives);

        }
        else
        {
            turn = playingCompicter(mymap, maskmy, turn, ShiplivesMy);
        }
        win = WhoWin(Shiplives, ShiplivesMy);
    }
    system("cls");
}
bool Battle::playingCompicter(int map[10][10], int mask[10][10], bool turn, int shiplives[20])
{
    //������� ���� �������� ������ ���������
//std::cout << " ��� ���������� " << endl;
//Map.printEnemyMap(mask);
//int x = 0, y = 0;

////���������� ��� ��������

//int new_x, new_y;
//int made = 0; //��������� ��������
//int dir = 0;//����������� ��������
//int sum = 0;
//for (int i = 0; i < N; i++)
//{
//    sum += Shiplives[i];

//}
//while (sum != 0) {
//    
//    if (made == 0)
//    {
//        x = rand() % n;
//        y = rand() % n;
//        
//        if (map[x][y] == 1)
//        {
//            made = 1;
//            map[x][y] = -1;
//            mask[x][y] = -1;
//            new_x = x;
//            new_y = y;
//            Shiplives[map[x][y]]--;
//            std::cout << "�����" << endl;
//        }
//        else
//        {
//            mask[x][y] = -2;
//            std::cout << "������" << endl;
//        }

//    }
//    else if (made == 1) {
//        if (dir == 0)//�����
//        {
//            if (x > 0)
//            {
//                x--;
//            }
//            else
//            {
//                dir = 1;
//                x = new_x;
//                y = new_y;
//                continue;
//            }
//        }
//        else if (dir == 1)//������
//        {
//            if (x < n - 1)
//            {
//                x++;
//            }
//            else
//            {
//                dir = 2;
//                x = new_x;
//                y = new_y;
//                continue;
//            }
//        }
//        else if (dir == 2)//�����
//        {
//            if (y > 0)
//            {
//                y--;
//            }
//            else
//            {
//                dir = 3;
//                x = new_x;
//                y = new_y;
//                continue;
//            }
//        }
//        else if (dir == 3)//����
//        {
//            if (y < n - 1)
//            {
//                y++;
//            }
//            else
//            {
//                dir = 0;
//                x = new_x;
//                y = new_y;
//                continue;
//            }
//        }
//        if (map[x][y] > 0  and Shiplives[map[x][y]] > 1)
//        {
//            map[x][y] = -1;
//            mask[x][y] = -1;
//            std::cout << "�����" << endl;
//            Shiplives[map[x][y]]--;
//        }
//        else if (map[x][y] > 0 and Shiplives[map[x][y]] <= 1)
//        {
//            map[x][y] = -1;
//            mask[x][y] = -1;
//            std::cout << "����" << endl;
//            Shiplives[map[x][y]] = 0;
//            made = 0;
//        }
//        else
//        {
//            dir = (dir + 1) % 4;
//            x = new_x;
//            y = new_y;
//            mask[x][y] = -2;
//            std::cout << "������ " << endl;
//        }
//        Map.printMyMap(mask);
//        sum = 0;
//        for (int i = 0; i < N; i++)
//        {
//            sum += Shiplives[i];
//            cout << Shiplives[i] << " ";

//        }
//    }
    //������� ���� �������� ������ ���������
    cout << " ��� ���������� " << endl;
    Map.printEnemyMap(mask);
    while (true)
    {
        int x = 0, y = 0;//���������� ��� ��������
        x = rand() % n;
        y = rand() % n;
        int new_x, new_y;
        if (mask[x][y] != -1 and mask[x][y] != -2)
        {
            if (map[x][y] >= 1)
            {
                shiplives[map[x][y]]--;//��������� ���-�� ����� �������� �� ������ �� ����
                if (shiplives[map[x][y]] == 0)
                {
                    cout << "������� ����" << endl;//���� ��� ������ ������� ����
                }
                else
                {
                    new_x = x;
                    new_y = y;
                    cout << "������� �����" << endl;
                }
                Sleep(2500);
                mask[x][y] = -1;//���������� ������ �����
                map[x][y] = -1;//�������� �������
                system("cls");
                Map.printEnemyMap(mask);
            }
            else {
                cout << "������" << endl;
                mask[x][y] = -2;//��������� ���������
                Sleep(2500);
                system("cls");
                Map.printEnemyMap(mask);
                return !turn;
            }
        }
        else
        {
            x = rand() % n;
            y = rand() % n;
        }

    }
    return turn;
}
void Battle::playingwWithEnemy(int map[10][10], int  mask[10][10], int& ShipID, int Shiplives[20], int mymap[10][10], int maskmy[10][10], int& ShipMyID, int  ShiplivesMy[20], int numships)
{
    // ���� � �����������
    creatPersonMap(map, numships, ShipID, Shiplives);
    creatPersonMap(mymap, numships, ShipMyID, ShiplivesMy);
    bool turn = 1;
    WhoWin(Shiplives, ShiplivesMy);
    cout << "\n\n****���������� ����******" << endl;
    Sleep(2000);
    bool win = 0;
    while (win == 0)
    {
        system("cls");
        cout << " ��������� �� ������������ ? " << endl;
        _getch();
        system("cls");
        if (turn)
        {
            cout << "  ����� ������ ";
            turn = playingAgainst(mymap, maskmy, map, turn, ShiplivesMy);
        }
        else
        {
            cout << "  ����� ������ ";
            turn = playingAgainst(map, mask, mymap, turn, Shiplives);
        }
        win = WhoWin(Shiplives, ShiplivesMy);
    }

    system("cls");
}
int Battle::WhoWin(int Shiplives[20], int ShiplivesMy[20])
{
    int sum = 0;
    int summy = 0;
    for (int i = 1; i < N; i++)
    {
        sum += Shiplives[i];
        summy += ShiplivesMy[i];
    }

    if (sum == 0)
    {
        return 1;
    }
    else if (summy == 0)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
void Battle::creatPersonMap(int map[10][10], int numships, int& shipsID, int shiplives[20])
{
    cout << "\n\n****** ���������� ���������� ******" << endl;
    cout << " \n��������� �� ������������ ? " << endl;
    _getch();
    system("cls");
    cout << "\n��� ��������: \n 4 ������������ ��������\n 3 ������������ ��������\n 2 ������������ ��������\n 1 �������������� �������\n ";
    cout << " \n��� ��������� �������:\n ���������� �������: 1\t ���������� ��������: 2\n �����: ";
    int shoce;
    cin >> shoce;
    system("cls");
    for (int i = 1; i < numships + 1; i++)
    {
        if (shoce == 2)
        {

            Map.placementShipRand(map, numships - i + 1, i, shipsID, shiplives);

        }
        else
        {
            Map.placementShip(map, numships - i + 1, i, shipsID, shiplives);
        }

    }
    system("cls");
    cout << " ���� ����� \n";
    Map.printMyMap(map);
    Sleep(2000);
    system("cls");
}
bool Battle::playingAgainst(int map[10][10], int mask[10][10], int mymap[10][10], bool turn, int shiplives[20])
{
    //������� ���� �������� ������ ���������
    cout << endl << " ��� �����" << endl;
    Map.printMyMap(mymap);
    cout << " ����� �����" << endl;
    Map.printEnemyMap(mask);
    while (true)
    {
        int x = 0, y = 0;//���������� ��� ��������
        cout << "������� ���������� � : ";
        cin >> x;
        cout << "������� ���������� � : ";
        cin >> y;
        if (map[x][y] >= 1)
        {
            shiplives[map[x][y]]--;//��������� ���-�� ����� �������� �� ������ �� ����
            if (shiplives[map[x][y]] == 0)
            {
                cout << "������� ����" << endl;//���� ��� ������ ������� ����
            }
            else
            {
                cout << "������� �����" << endl;
            }
            Sleep(2000);
            mask[x][y] = -1;//���������� ������ �����
            map[x][y] = -1;//�������� �������
            system("cls");
            cout << endl << " ��� �����" << endl;
            Map.printMyMap(mymap);
            Map.printEnemyMap(mask);
        }
        else {
            cout << "������" << endl;
            mask[x][y] = -2;
            Sleep(2000);
            system("cls");
            cout << endl << " ��� �����" << endl;
            Map.printMyMap(mymap);
            Map.printEnemyMap(mask);
            return !turn;
        }
    }
    return turn;
}
