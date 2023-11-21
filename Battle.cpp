#include "Battle.h"
using namespace std;
const int n = 10;//размер карты
const int N = n * 2;//размер массива жизни

void Battle::Play(int map[10][10], int  mask[10][10], int& ShipID, int Shiplives[20], int mymap[10][10], int maskmy[10][10], int& ShipMyID, int  ShiplivesMy[20], int numships)
{
    string name;
    string nameMy;
    int Win = 0;
    while (Win == 0)
    {
        system("cls");
        int coise1;
        cout << "Выбор 1 : игра против компьтера.\t" << "Выбор 2 : игра с противником." << endl;
        cout << "Ваш выбор: ";
        cin >> coise1;
        if (coise1 == 1)
        {
            cout << "Введите выше имя :";
            cin >> nameMy;
            name = "Компьютер";
            system("cls");
            playingWithComputer(map, mask, ShipID, Shiplives, mymap, maskmy, ShipMyID, ShiplivesMy, numships);
        }
        else
        {
            cout << "Имя первого игрока : ";
            cin >> nameMy;
            std::cout << "Имя второго игрока :";
            cin >> name;
            playingwWithEnemy(map, mask, ShipID, Shiplives, mymap, maskmy, ShipMyID, ShiplivesMy, numships);
        }
        Win = WhoWin(Shiplives, ShiplivesMy);
    }
    system("cls");
    if (Win == 2)
    {
        cout << "\n\tПобедил " << nameMy << "!!!" << endl;
        cout << "" << nameMy << endl;
        Map.printMyMap(mymap);
        cout << "" << name << endl;
        Map.printMyMap(map);
    }
    else
    {
        cout << "\n\t Победил " << name << "!!!" << endl;
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

    cout << "\n\n****НАЧИНАЕТСЯ ИГРА******" << endl;
    Sleep(2000);
    int win = 0;
    while (win == 0)
    {
        system("cls");
        if (turn)
        {
            cout << "  Ваш ход  ";
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
    //процесс игра человека против копьютера
//std::cout << " Ход компьютера " << endl;
//Map.printEnemyMap(mask);
//int x = 0, y = 0;

////координаты для выстрела

//int new_x, new_y;
//int made = 0; //состояние стрельбы
//int dir = 0;//направление стрельбы
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
//            std::cout << "Ранен" << endl;
//        }
//        else
//        {
//            mask[x][y] = -2;
//            std::cout << "Промах" << endl;
//        }

//    }
//    else if (made == 1) {
//        if (dir == 0)//влево
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
//        else if (dir == 1)//вправо
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
//        else if (dir == 2)//вверх
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
//        else if (dir == 3)//вниз
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
//            std::cout << "Ранен" << endl;
//            Shiplives[map[x][y]]--;
//        }
//        else if (map[x][y] > 0 and Shiplives[map[x][y]] <= 1)
//        {
//            map[x][y] = -1;
//            mask[x][y] = -1;
//            std::cout << "Убит" << endl;
//            Shiplives[map[x][y]] = 0;
//            made = 0;
//        }
//        else
//        {
//            dir = (dir + 1) % 4;
//            x = new_x;
//            y = new_y;
//            mask[x][y] = -2;
//            std::cout << "Промах " << endl;
//        }
//        Map.printMyMap(mask);
//        sum = 0;
//        for (int i = 0; i < N; i++)
//        {
//            sum += Shiplives[i];
//            cout << Shiplives[i] << " ";

//        }
//    }
    //процесс игра человека против копьютера
    cout << " Ход компьютера " << endl;
    Map.printEnemyMap(mask);
    while (true)
    {
        int x = 0, y = 0;//координаты для выстрела
        x = rand() % n;
        y = rand() % n;
        int new_x, new_y;
        if (mask[x][y] != -1 and mask[x][y] != -2)
        {
            if (map[x][y] >= 1)
            {
                shiplives[map[x][y]]--;//уменьшить кол-во жизни кооробля по номеру на поле
                if (shiplives[map[x][y]] == 0)
                {
                    cout << "Корабль убит" << endl;//если нет жизней корабль убит
                }
                else
                {
                    new_x = x;
                    new_y = y;
                    cout << "Корабль ранен" << endl;
                }
                Sleep(2500);
                mask[x][y] = -1;//показывать убитую часть
                map[x][y] = -1;//обнулить корабль
                system("cls");
                Map.printEnemyMap(mask);
            }
            else {
                cout << "промах" << endl;
                mask[x][y] = -2;//показывть попадания
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
    // игра с противником
    creatPersonMap(map, numships, ShipID, Shiplives);
    creatPersonMap(mymap, numships, ShipMyID, ShiplivesMy);
    bool turn = 1;
    WhoWin(Shiplives, ShiplivesMy);
    cout << "\n\n****НАЧИНАЕТСЯ ИГРА******" << endl;
    Sleep(2000);
    bool win = 0;
    while (win == 0)
    {
        system("cls");
        cout << " противник не подглядывает ? " << endl;
        _getch();
        system("cls");
        if (turn)
        {
            cout << "  ходит первый ";
            turn = playingAgainst(mymap, maskmy, map, turn, ShiplivesMy);
        }
        else
        {
            cout << "  ходит второй ";
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
    cout << "\n\n****** НАЧИНАЕТСЯ РАСТАНОВКА ******" << endl;
    cout << " \nпротивник не подглядывает ? " << endl;
    _getch();
    system("cls");
    cout << "\nВам доступно: \n 4 однопалубных караблей\n 3 двухпалубных караблей\n 2 трехпалубных караблей\n 1 четырёхпалубный карабль\n ";
    cout << " \nКак раставить корабли:\n Расставить вручную: 1\t Расставить рандомно: 2\n Выбор: ";
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
    cout << " Ваша карта \n";
    Map.printMyMap(map);
    Sleep(2000);
    system("cls");
}
bool Battle::playingAgainst(int map[10][10], int mask[10][10], int mymap[10][10], bool turn, int shiplives[20])
{
    //процесс игра человека против копьютера
    cout << endl << " Моя карта" << endl;
    Map.printMyMap(mymap);
    cout << " Карта врага" << endl;
    Map.printEnemyMap(mask);
    while (true)
    {
        int x = 0, y = 0;//координаты для выстрела
        cout << "Введите координату х : ";
        cin >> x;
        cout << "Введите координату у : ";
        cin >> y;
        if (map[x][y] >= 1)
        {
            shiplives[map[x][y]]--;//уменьшить кол-во жизни кооробля по номеру на поле
            if (shiplives[map[x][y]] == 0)
            {
                cout << "Корабль убит" << endl;//если нет жизней корабль убит
            }
            else
            {
                cout << "Корабль ранен" << endl;
            }
            Sleep(2000);
            mask[x][y] = -1;//показывать убитую часть
            map[x][y] = -1;//обнулить корабль
            system("cls");
            cout << endl << " Моя карта" << endl;
            Map.printMyMap(mymap);
            Map.printEnemyMap(mask);
        }
        else {
            cout << "промах" << endl;
            mask[x][y] = -2;
            Sleep(2000);
            system("cls");
            cout << endl << " Моя карта" << endl;
            Map.printMyMap(mymap);
            Map.printEnemyMap(mask);
            return !turn;
        }
    }
    return turn;
}
