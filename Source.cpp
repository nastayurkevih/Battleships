#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>

using namespace std;
const int n = 10;//размер карты
const int N = n * 2;//размер массива жизни
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
struct Battle
{

    MAP Map;
    int IsAlive(int shiplives[N]);
    bool playingAgainst(int map[n][n], int mask[n][n], int mymap[n][n], bool turn, int shiplives[N]);
    void creatPersonMap(int map[n][n], int numships, int& shipsID, int shiplives[N]);
    int WhoWin(int Shiplives[N], int ShiplivesMy[N]);
    void playingwWithEnemy(int map[n][n], int  mask[n][n], int& ShipID, int Shiplives[N], int mymap[n][n], int maskmy[n][n], int& ShipMyID, int  ShiplivesMy[N], int numships);
    void playingWithComputer(int map[n][n], int  mask[n][n], int& ShipID, int Shiplives[N], int mymap[n][n], int maskmy[n][n], int& ShipMyID, int  ShiplivesMy[N], int numships);
    bool playingCompicter(int map[n][n], int mask[n][n], bool turn, int shiplives[N]);
    void Play(int map[n][n], int  mask[n][n], int& ShipID, int Shiplives[N], int mymap[n][n], int maskmy[n][n], int& ShipMyID, int  ShiplivesMy[N], int numships);
};
void Battle::Play(int map[n][n], int  mask[n][n], int& ShipID, int Shiplives[N], int mymap[n][n], int maskmy[n][n], int& ShipMyID, int  ShiplivesMy[N], int numships)
{
    string name;
    string nameMy;
    bool Win = 0;
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
            cout << "Имя второго игрока :";
            cin >> name;
            playingwWithEnemy(map, mask, ShipID, Shiplives, mymap, maskmy, ShipMyID, ShiplivesMy, numships);
        }
        Win = WhoWin(Shiplives, ShiplivesMy);
    }
    if (Win == 2)
    {
        cout << "Победил " << nameMy << "!!!" << endl;
    }
    else
    {
        cout << "Победил " << name << "!!!" << endl;
    }
}
void Battle::playingWithComputer(int map[n][n], int  mask[n][n], int& ShipID, int Shiplives[N], int mymap[n][n], int maskmy[n][n], int& ShipMyID, int  ShiplivesMy[N], int numships)
{
    for (int i = 1; i < numships + 1; i++)
    {
        Map.placementShipRand(map, numships - i + 1, i, ShipID, Shiplives);
    }
    creatPersonMap(mymap, numships, ShipMyID, ShiplivesMy);
    bool turn = 1;
    cout << "\n\n****НАЧИНАЕТСЯ ИГРА******" << endl;
    Sleep(2000);
    bool win = 0;
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
            Map.printMyMap(map);
            Map.printEnemyMap(mymap);
            _getch();
        }
        win = WhoWin(Shiplives, ShiplivesMy);
    }

}

int main()
{
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    MAP Map;
    Battle battle;
    int map[n][n] = { 0 };// создание карты противника
    int mymap[n][n] = { 0 };//создание своей карты
    int mask[n][n];// маска для создания тумана войны
    int maskmy[n][n];
    int shipLength = 4;//длина коробля
    int numships = 4;//колво кораблей заданной длины
    int ShipID = 1;
    int ShipMyID = 1;
    int Shiplives[N] = { 0 };
    int ShiplivesMy[N] = { 0 };




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
bool Battle::playingCompicter(int map[n][n], int mask[n][n], bool turn, int shiplives[N])
{

    while (turn)
    {
        int x = 0, y = 0;
        x = rand() % 10;
        y = rand() % 10;
        if (mask[x][y] < 0)
        {
            if (map[x][y] >= 1)
            {
                shiplives[map[x][y]]--;
                mask[x][y] = -1;
                map[x][y] = -1;
            }
            else {

                mask[x][y] = -2;
                return !turn;
            }
        }
        else {
            x = rand() % 10;
            y = rand() % 10;
        }

    }
    return 1;
}
void Battle::playingwWithEnemy(int map[n][n], int  mask[n][n], int& ShipID, int Shiplives[N], int mymap[n][n], int maskmy[n][n], int& ShipMyID, int  ShiplivesMy[N], int numships)
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


}

int Battle::WhoWin(int Shiplives[N], int ShiplivesMy[N])
{
    int sum = 0;
    int summy = 0;
    for (int i = 0; i < N; i++)
    {
        sum += Shiplives[i];
        summy += ShiplivesMy[i];
        cout << endl;
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
void Battle::creatPersonMap(int map[n][n], int numships, int& shipsID, int shiplives[N])
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
void MAP::placementShipRand(int map[n][n], int shipLength, int numships, int& shipsID, int shiplives[N])//постройка корабля в рандомном месте
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
            if (x<0 or x>n or y<0 or y>n) //если x или y выходит за границы
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
            shipsID++;// следующий номер 
            countship++;//+построенный корабль
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


        }
    }
}
void MAP::printEnemyMap(int mask[n][n])// печать карты компьютера
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
int Battle::IsAlive(int shiplives[N])//подсчёт кол-во жизни
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += shiplives[i];
    }
    return sum;
}
bool Battle::playingAgainst(int map[n][n], int mask[n][n], int mymap[n][n], bool turn, int shiplives[N])
{
    //процесс игра человека против копьютера
    cout << endl << " Моя карта" << endl;
    Map.printMyMap(mymap);
    cout << " Карта врага" << endl;
    Map.printEnemyMap(mask);
    while (IsAlive(shiplives) > 0)
    {
        int x = 0, y = 0;//координаты для выстрела
        cout << "Введите координату х : ";
        cin >> x;
        cout << "Введите координату у : ";
        cin >> y;
        if (map[x][y] >= 1)
        {
            shiplives[map[x][y]]--;//уменьшить кол-во жизни кооробля по номеру на поле
            if (shiplives[map[x][y]] <= 0)
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
}
void MAP::printMyMap(int map[n][n])// печать карты компьютера
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
bool MAP::setship(int map[n][n], int x, int y, int direction, int shipLength, int& shipsID, int shiplives[N])//проверка возможности и поставление корабля
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
void MAP::showShip(int mymap[n][n], int x, int y, int direction, int shipLength) //предварительная печать корабля
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
void MAP::placementShip(int mymap[n][n], int shipLength, int numships, int& shipsID, int shiplives[N])
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
