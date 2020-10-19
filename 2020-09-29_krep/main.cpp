//2020-09-29
//uzduotis nebloga . . .
#include <iostream>
#include <fstream>

using namespace std;

struct zaidInfo
{
    string vardas;
    string komanda;
    int taskai;
};
struct komanda
{
    string komPav;
    int kiekis;
    string rezVardas;
    int taskai;
};

void nuskaitymas(struct zaidInfo zaidejas[]);
void formavimas(struct zaidInfo zaidejas[], struct komanda kom[], int &n);
void rikiavimas(struct komanda kom[], int n);
void irasymas(struct komanda kom[], int n);

int main()
{
    struct zaidInfo zaidejas[10];
    struct komanda kom[100];
    int n;
    nuskaitymas(zaidejas);
    formavimas(zaidejas, kom, n);
    rikiavimas(kom, n);
    irasymas(kom, n);

    return 0;
}

void nuskaitymas(struct zaidInfo zaidejas[])
{
    ifstream data("U2.txt");

    char vardas[21], komanda[16];

    for (int i = 0; i < 10; i++)
    {
        data.get(vardas, 21);
        zaidejas[i].vardas = vardas;
        data.ignore();
        data.get(komanda, 16);
        data.ignore();
        zaidejas[i].komanda = komanda;
        data >> zaidejas[i].taskai;
        data.ignore();
    }
    data.close();
    return;
}
void formavimas(struct zaidInfo zaidejas[], struct komanda kom[], int &n)
{
    n = 0;
    int rasta;
    for (int i = 0; i < 10; i++)
    {
        rasta = 0;
        for (int j = 0; j < n; j++)
        {
            if (zaidejas[i].komanda == kom[j].komPav)
            {
                rasta = 1;
                kom[j].kiekis++;
                if (zaidejas[i].taskai > kom[j].taskai)
                {
                    kom[j].taskai = zaidejas[i].taskai;
                    kom[j].rezVardas = zaidejas[i].vardas;
                }
            }
        }
        if (rasta == 0)
        {
            kom[n].komPav = zaidejas[i].komanda;
            kom[n].rezVardas = zaidejas[i].vardas;
            kom[n].taskai = zaidejas[i].taskai;
            kom[n].kiekis = 1;
            n++;
        }
    }
    return;
}
void rikiavimas(struct komanda kom[], int n)
{
    struct komanda atsarginis;
    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n; j++)
            if (kom[i].kiekis < kom[j].kiekis || kom[i].kiekis == kom[j].kiekis && kom[i].komPav > kom[j].komPav)
            {
                atsarginis = kom[i];
                kom[i] = kom[j];
                kom[j] = atsarginis;
            }
    return;
}
void irasymas(struct komanda kom[], int n)
{
    ofstream data("U2rez.txt");
    data << n << endl;
    for (int i = 0; i < n; i++)
        data << kom[i].komPav << " " << kom[i].kiekis << " " << kom[i].rezVardas << '\n';
    data.close();
    return;
}