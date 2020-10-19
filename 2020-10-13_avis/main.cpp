/// idomi uzduotis . . . .
#include <iostream>
#include <fstream>

using namespace std;

struct avis
{
    string vardas;
    string dnr;
    int koef;
};

void nuskaitymas(avis avys[], int &n, int &m, int &kel);
int sutapimo_koef(string tiriama, string kita, int m);
void uzpildymas(avis avys[], int n, int m, int kel);
void rikiavimas(avis avys[], int n);
void spausdinimas(avis avys[], int n);

int main()
{
    avis avys[20];
    int n, m, kel;
    nuskaitymas(avys, n, m, kel);
    uzpildymas(avys, n, m, kel);
    rikiavimas(avys, n);
    spausdinimas(avys, n);

    return 0;
}

void nuskaitymas(avis avys[], int &n, int &m, int &kel)
{
    char vardas[11];
    ifstream data("U2.txt");
    data >> n >> m >> kel;

    for (int i = 0; i < n; i++)
    {
        data.ignore();
        data.get(vardas, 11);
        avys[i].vardas = vardas;
        data >> avys[i].dnr;
    }
    data.close();
    return;
}
int sutapimo_koef(string tiriama, string kita, int m)
{
    int koef = 0;
    for (int i = 0; i < m; i++)
        if (tiriama[i] == kita[i])
            koef++;

    return koef;
}
void uzpildymas(avis avys[], int n, int m, int kel)
{
    for (int i = 0; i < n; i++)
        if (i != kel - 1)
            avys[i].koef = sutapimo_koef(avys[kel - 1].dnr, avys[i].dnr, m);
        else
            avys[i].koef = -1;

    return;
}
void rikiavimas(avis avys[], int n)
{
    avis atsarginis;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (avys[i].koef < avys[j].koef || avys[i].koef == avys[j].koef && avys[i].vardas > avys[j].vardas)
            {
                atsarginis = avys[i];
                avys[i] = avys[j];
                avys[j] = atsarginis;
            }
        }
    return;
}
void spausdinimas(avis avys[], int n)
{
    ofstream data("U2rez.txt");

    for (int i = 0; i < n; i++)
        if (avys[i].koef == -1)
            data << avys[i].vardas << endl;

    for (int i = 0; i < n; i++)
        if (avys[i].koef != -1)
            data << avys[i].vardas << " " << avys[i].koef << endl;

    data.close();
    return;
}