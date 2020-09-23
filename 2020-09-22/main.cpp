#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct info
{
    string vardas;
    int dienos;
    int karosu;
    int karpiu;
    int kuoju;
    int bendrasSk;
};

void nuskaitymas(info zv[], int &n);
void irasymas(info zv[], int n);

int main()
{
    struct info zv[100];
    int n;
    nuskaitymas(zv, n);
    irasymas(zv, n);

    return 0;
}

void nuskaitymas(info zv[], int &n)
{

    ifstream data("U2.txt");
    data >> n;

    char vardas[11];
    int nereikalingas;

    for (int i = 0; i < n; i++)
    {
        zv[i].karosu = 0;
        zv[i].karpiu = 0;
        zv[i].kuoju = 0;
        zv[i].bendrasSk = 0;

        data.ignore();
        data.get(vardas, 11);
        zv[i].vardas = vardas;
        data >> zv[i].dienos;
        for (int j = 0; j < zv[i].dienos; j++)
        {
            data >> nereikalingas;
            zv[i].karosu += nereikalingas;
            data >> nereikalingas;
            zv[i].karpiu += nereikalingas;
            data >> nereikalingas;
            zv[i].kuoju += nereikalingas;
            zv[i].bendrasSk = zv[i].karosu + zv[i].karpiu + zv[i].kuoju;
        }
    }

    data.close();
    return;
}

void irasymas(info zv[], int n)
{
    ofstream data("U2rez.txt");
    for (int i = 0; i < n; i++)
    {
        data << zv[i].vardas << setw(5) << zv[i].karosu << setw(5) << zv[i].karpiu << setw(5) << zv[i].kuoju << endl;
    }
    int atsarginis = zv[0].bendrasSk;
    int kelintas = 0;
    for (int i = 1; i < n; i++)
        if (atsarginis < zv[i].bendrasSk)
        {
            atsarginis = zv[i].bendrasSk;
            kelintas = i;
        }
    data << zv[kelintas].vardas << setw(5) << zv[kelintas].bendrasSk;

    data.close();
    return;
}