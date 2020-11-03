//autobusai
// Pradeta 14:00
#include <iostream>
#include <fstream>
using namespace std;

struct autoInfo
{
    int numeris;
    string rusis;
    int stoteliuSk;
    int atstumas[50];
    int atstumoSuma;
};
struct daiktas
{
    string rusis;
    int kiekis;
    int atstumas;
};
void nuskaitymas(autoInfo autobusas[100], int &n);
void rikiavimas(autoInfo autobusas[100], int n);
void transportoPildymas(autoInfo autobusas[100], int n, daiktas transportas[3]);
void irasymas(autoInfo autobusas[100], int n, daiktas autobus, daiktas mikroautobusas, daiktas troleibusas);

int main()
{
    autoInfo autobusas[100];
    daiktas transportas[3];
    int n;

    nuskaitymas(autobusas, n);
    transportoPildymas(autobusas, n, transportas);
    rikiavimas(autobusas, n);
    cout << transportas[0].rusis << " " << transportas[0].kiekis << " " << transportas[0].atstumas;

    /*
    for (int i = 0; i < n; i++)
    {
        cout << autobusas[i].numeris << " " << autobusas[i].rusis << " " << autobusas[i].stoteliuSk;
        for (int j = 0; j < autobusas[i].stoteliuSk - 1; j++)
        {
            cout << " " << autobusas[i].atstumas[j];
        }
        cout << endl;
    }*/

    return 0;
}

void nuskaitymas(autoInfo autobusas[100], int &n)
{
    char vardas[15];
    ifstream data("Duom2.txt");
    data >> n;
    for (int i = 0; i < n; i++)
    {
        data.ignore();
        data >> autobusas[i].numeris;
        data.ignore();
        data.get(vardas, 15);
        autobusas[i].rusis = vardas;
        data.ignore();
        data >> autobusas[i].stoteliuSk;
        for (int j = 0; j < autobusas[i].stoteliuSk - 1; j++)
        {
            data.ignore();
            data >> autobusas[i].atstumas[j];
        }
    }
    data.close();
    return;
}
void rikiavimas(autoInfo autobusas[100], int n)
{
    autoInfo atsarga;
    for (int i = 0; i < n; i++)
    {
        autobusas[i].atstumoSuma = 0;
        for (int j = 0; j < autobusas[i].stoteliuSk; j++)
            autobusas[i].atstumoSuma += autobusas[i].atstumas[j];
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n; j++)
            if (autobusas[i].atstumas < autobusas[j].atstumas)
                return;
}
void transportoPildymas(autoInfo autobusas[100], int n, daiktas transportas[3])
{

    transportas[0].rusis = "autobusas     ";
    transportas[1].rusis = "mikroautobusas";
    transportas[2].rusis = "troleibusas   ";

    for (int k = 0; k < 3; k++)
    {
        transportas[k].kiekis = 0;
        transportas[k].atstumas = 0;
        for (int i = 0; i < n; i++)
        {
            if (transportas[k].rusis == autobusas[i].rusis)
            {
                cout << transportas[k].rusis << "--\n"
                     << autobusas[i].rusis << "--" << endl;
                transportas[k].kiekis++;
                cout << transportas[k].kiekis << endl;
                for (int j = 0; j < autobusas[i].stoteliuSk; j++)
                    transportas[k].atstumas += autobusas[i].atstumas[j];
            }
        }
    }
    return;
}
void irasymas(autoInfo autobusas[100], int n, daiktas transportas[3])
{

    ofstream data("Rez2.txt");

    for (int i = 0; i < 3; i++)
    {
        data << transportas[i].rusis << " ";
        if (transportas[i].kiekis == 0)
            data << "nera" << endl;
        else
            data << transportas[i].kiekis << " " << transportas[i].atstumas << endl;
    }
    data << autobusas[0].rusis << " " << autobusas[0].numeris << " " << autobusas[0].atstumoSuma << endl;
    return;
}
