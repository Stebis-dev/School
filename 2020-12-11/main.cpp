#include <iostream>
#include <fstream>
using namespace std;

void nuskaitom(int &n, int map[50][50])
{
    ifstream data("U.txt");
    data >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            data >> map[i][j];
    data.close();
    return;
}
void ivedam(int &n, int map[50][50])
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    return;
}
void vertimas(int n, int map[50][50])
{
    int atsarginis[50][50];
    for (int i = 0; i < n; i++)
        for (int x = 0; x < n; x++)
            atsarginis[i][x] = map[x][(n - 1) - i];

    for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++)
            map[y][x] = atsarginis[y][x];

    return;
}
int tikrinimas(int n, int map[50][50])
{
    int did = 0;
    int maziausias = map[0][0];
    for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++)
        {
            if (maziausias < map[y][x])
            {
                did += map[y][x] - maziausias;
                maziausias = map[y][x] - (map[y][x] - maziausias);
            }
            if (maziausias > map[y][x] && x + 1 <= n)
                maziausias = map[y][x];
        }

    return did;
}
int main()
{
    int n;
    int map[50][50];
    //int map[3][3]= {{9,9,10}, {9,8,9},{10,9,9}};

    ///nuskaitymas is file
    nuskaitom(n, map);

    ///ivedimas is terminalo
    //ivedam(n, map);
    int didziausias = 0, did; //rez

    didziausias = tikrinimas(n, map);

    for (int i = 0; i < 3; i++)
    {
        vertimas(n, map);
        did = tikrinimas(n, map);
        if (did < didziausias)
            didziausias = did;
    }
    cout << didziausias << endl;
    return 0;
}