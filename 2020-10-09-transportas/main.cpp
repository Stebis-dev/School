#include <iostream>
#include <fstream>
#define n 100

using namespace std;

struct autobusas
{
    string vardas;
    int stoteliuKiekis;
    int autobusaiStoteleje[n];
};

void nuskaitymas(autobusas aut[], int &a);

int kelintasisAutobusas(autobusas aut[], int a);

void irasymas(autobusas aut[], int b, int a);

int main()
{
    autobusas aut[n];
    int a, b;
    nuskaitymas(aut, a);
    b = kelintasisAutobusas(aut, a);
    irasymas(aut, b, a);
    return 0;
}
void nuskaitymas(autobusas aut[], int &a)
{
    char vardas[21];
    ifstream data("U2.txt");
    data >> a;
    for (int i = 0; i < a; i++)
    {
        data.ignore();
        data.get(vardas, 21);
        aut[i].vardas = vardas;
        data >> aut[i].stoteliuKiekis;
        for (int j = 0; j < aut[i].stoteliuKiekis; j++)
            data >> aut[i].autobusaiStoteleje[j];
    }
    data.close();
    return;
}

int kelintasisAutobusas(autobusas aut[], int a)
{
    static int autobusai[n];
    for (int i = 0; i < a; i++)
        for (int j = 0; j < aut[i].stoteliuKiekis; j++)
            autobusai[aut[i].autobusaiStoteleje[j]]++;

    int autobusas = autobusai[0];
    for (int i = 1; i < n; i++)
        if (autobusas < autobusai[i])
            autobusas = autobusai[i];

    return autobusas + 1;
}

void irasymas(autobusas aut[], int b, int a)
{
    ofstream data("U2rez.txt");
    data << b << endl;
    for (int i = 0; i < a; i++)
        for (int j = 0; j < aut[i].stoteliuKiekis; j++)
            if (aut[i].autobusaiStoteleje[j] == b)
                data << aut[i].vardas << endl;
    data.close();
    return;
}

/*
for (int i = 0; i < a; i++)
    {
        cout << aut[i].vardas;
        cout << aut[i].stoteliuKiekis << " ";
        for (int j = 0; j < aut[i].stoteliuKiekis; j++)
            cout << aut[i].autobusaiStoteleje[j] << " ";
        cout << endl;
    }
*/