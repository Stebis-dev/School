//autobusai
// Pradeta 14:00
// Pabaigta 15:42
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
    int maziausiasAtstumas;
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
void maziausiasAtstumas(autoInfo autobusas[100], int n);
void irasymas(autoInfo autobusas[100], int n, daiktas transportas[3]);

int main()
{
    autoInfo autobusas[100];
    daiktas transportas[3];
    int n;

    nuskaitymas(autobusas, n);
    transportoPildymas(autobusas, n, transportas);
    irasymas(autobusas, n, transportas);

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
    ifstream data("Duom2.txt"); //data is read in english 
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
        for (int j = 0; j < autobusas[i].stoteliuSk - 1; j++)
            autobusas[i].atstumoSuma += autobusas[i].atstumas[j];
    }

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (autobusas[i].atstumoSuma < autobusas[j].atstumoSuma)
            {
                atsarga = autobusas[i];
                autobusas[i] = autobusas[j];
                autobusas[j] = atsarga;
            }

    return;
}
void maziausiasAtstumas(autoInfo autobusas[100], int n)
{
    for (int i = 0; i < n; i++)
    {
        autobusas[i].maziausiasAtstumas = autobusas[i].atstumas[0];
        for (int k = 0; k < autobusas[i].stoteliuSk - 2; k++)
            for (int j = k + 1; j < autobusas[i].stoteliuSk - 1; j++)
                if (autobusas[i].atstumas[k] > autobusas[i].atstumas[j])
                    autobusas[i].maziausiasAtstumas = autobusas[i].atstumas[j];
    }
    autoInfo atsarga;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (autobusas[i].maziausiasAtstumas > autobusas[j].maziausiasAtstumas || autobusas[i].maziausiasAtstumas == autobusas[j].maziausiasAtstumas && autobusas[i].rusis > autobusas[j].rusis)
            {
                atsarga = autobusas[i];
                autobusas[i] = autobusas[j];
                autobusas[j] = atsarga;
            }

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
            if (transportas[k].rusis == autobusas[i].rusis)
            {
                transportas[k].kiekis++;
                for (int j = 0; j < autobusas[i].stoteliuSk - 1; j++)
                    transportas[k].atstumas += autobusas[i].atstumas[j];
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
    rikiavimas(autobusas, n);
    data << autobusas[0].rusis << " " << autobusas[0].numeris << " " << autobusas[0].atstumoSuma << endl;
    maziausiasAtstumas(autobusas, n);
    data << autobusas[0].rusis << " " << autobusas[0].numeris << " " << autobusas[0].maziausiasAtstumas << endl;
    data.close();
    return;
}
