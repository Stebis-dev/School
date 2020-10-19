//2020-10-06
//komentuoti ar nekomentuoti
#include <iostream>
#include <fstream>

using namespace std;

struct begikas
{
    string vardas;
    int min, s;
};
void nuskaitymas(struct begikas beg[], int &n); //nuskaitom ir komentuojame galutini masyva
void rikiavimas(struct begikas beg[], int n);   //rikiuojame tiek atskirus, tiek galutinius
void irasymas(struct begikas beg[], int n);     //irasyme i faila

int main()
{
    struct begikas beg[25];
    int n = 0;
    nuskaitymas(beg, n);
    rikiavimas(beg, n);
    irasymas(beg, n);

    return 0;
}
void nuskaitymas(struct begikas beg[], int &n)
{
    struct begikas prad[50]; // tarpinis laikinas masyvas
    int k, kiek;
    char vardas[21];

    ifstream data("U2.txt");
    data >> k;

    for (int j = 0; j < k; j++)
    {
        data >> kiek;
        for (int i = 0; i < kiek; i++)
        {
            data.ignore();
            data.get(vardas, 21);
            prad[i].vardas = vardas;
            data >> prad[i].min;
            data >> prad[i].s;
        }
        rikiavimas(prad, kiek);
        for (int j = 0; j < kiek / 2; j++)
        {
            beg[n] = prad[j];
            n++;
        }
    }
    data.close();
    return;
}
void rikiavimas(struct begikas beg[], int n)
{
    struct begikas atsarginis;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (beg[i].min > beg[j].min || beg[i].min == beg[j].min && beg[i].s > beg[j].s)
            {
                atsarginis = beg[i];
                beg[i] = beg[j];
                beg[j] = atsarginis;
            }
        }
    return;
}
void irasymas(struct begikas beg[], int n)
{
    ofstream data("U2rez.txt");
    for (int i = 0; i < n; i++)
    {
        data << beg[i].vardas;
        data << beg[i].min << " ";
        data << beg[i].s << endl;
    }
    data.close();
    return;
}