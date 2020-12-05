#include <iostream>
#include <fstream>

using namespace std;

struct kalba
{
    string kalbosPavadinimas;
    int pirmuMetu;           //2010
    int antruMetu;           //2011
    int populiarumoIndeksas; // skirtumas tarp metu populiarumo (< 0 +) ( > 0 -)
};

void nuskaitymas(int &kiekis, struct kalba kalb[]);
void skirtumoSkaiciavimas(int kiekis, struct kalba kalb[]);
int didziausias(int kiekis, struct kalba kalb[]);
void padidejusiuPaieska(int kiekis, struct kalba kalb[], string padidejo[], int &k, int a);
int maziausias(int kiekis, struct kalba kalb[]);
void sumazejusiuPaieska(int kiekis, struct kalba kalb[], string sumazejo[], int &n, int a);
void irasymas(string sumazejo[], int n, string padidejo[], int &k, int kiekis, struct kalba kalb[]);
int main()
{
    int kiekis;
    int k = 0, n = 0;
    kalba kalb[50];
    string padidejo[50];
    string sumazejo[50];

    nuskaitymas(kiekis, kalb);
    skirtumoSkaiciavimas(kiekis, kalb);
    padidejusiuPaieska(kiekis, kalb, padidejo, k, didziausias(kiekis, kalb));
    sumazejusiuPaieska(kiekis, kalb, sumazejo, n, maziausias(kiekis, kalb));
    irasymas(sumazejo, n, padidejo, k, kiekis, kalb);

    return 0;
}

void nuskaitymas(int &kiekis, struct kalba kalb[])
{
    ifstream data("Duomenys.txt");
    char laikinas[25];
    data >> kiekis;
    for (int i = 1; i <= kiekis; i++)
    {
        data.ignore();
        data.get(laikinas, 25);
        kalb[i].kalbosPavadinimas = laikinas;
        data >> kalb[i].antruMetu >> kalb[i].pirmuMetu;
    }
    data.close();
    return;
}
void skirtumoSkaiciavimas(int kiekis, struct kalba kalb[])
{
    for (int i = 1; i <= kiekis; i++)
        kalb[i].populiarumoIndeksas = kalb[i].antruMetu - kalb[i].pirmuMetu;

    return;
}
int didziausias(int kiekis, struct kalba kalb[])
{
    int did = kalb[1].populiarumoIndeksas;
    for (int i = 2; i <= kiekis; i++)
        if (did > kalb[i].populiarumoIndeksas)
            did = kalb[i].populiarumoIndeksas;

    return did;
}
void padidejusiuPaieska(int kiekis, struct kalba kalb[], string padidejo[], int &k, int a)
{
    for (int i = 1; i <= kiekis; i++)
        if (kalb[i].populiarumoIndeksas == a)
        {
            padidejo[k] = kalb[i].kalbosPavadinimas;
            k++;
        }
    return;
}
int maziausias(int kiekis, struct kalba kalb[])
{
    int maz = kalb[1].populiarumoIndeksas;
    for (int i = 2; i <= kiekis; i++)
        if (maz < kalb[i].populiarumoIndeksas)
            maz = kalb[i].populiarumoIndeksas;

    return maz;
}
void sumazejusiuPaieska(int kiekis, struct kalba kalb[], string sumazejo[], int &n, int a)
{
    for (int i = 1; i <= kiekis; i++)
        if (kalb[i].populiarumoIndeksas == a)
        {
            sumazejo[n] = kalb[i].kalbosPavadinimas;
            n++;
        }
    return;
}
void irasymas(string sumazejo[], int n, string padidejo[], int &k, int kiekis, struct kalba kalb[])
{
    ofstream data("Rezultatai.txt");
    data << -didziausias(kiekis, kalb) << endl;
    for (int i = 0; i < k; i++)
        data << padidejo[i] << endl;
    data << maziausias(kiekis, kalb) << endl;
    for (int i = 0; i < n; i++)
        data << sumazejo[i] << endl;
    data.close();
    return;
}
