//pradeta uzd. 8:50
#include <iostream>
#include <fstream>

using namespace std;

struct miestas
{
    string miestas;
    string apskritis;
    int gyventojai;
};
struct apskritis
{
    string apskritis;
    int mazGyventojai; //miestas su maziausiu gyventoju kiekiu
    int sumGyventojai;
};

void nuskaitymas(struct miestas mie[], int &n);
void formavimas(struct apskritis aps[], struct miestas mie[], int n, int &a);
void rikiavimas(struct apskritis aps[], int a);
void irasymas(struct apskritis aps[], int a);

int main()
{
    struct miestas mie[103];
    struct apskritis aps[10];
    int n = 0, a = 0;
    nuskaitymas(mie, n);
    formavimas(aps, mie, n, a);
    rikiavimas(aps, a);
    irasymas(aps, a);
    return 0;
}
void nuskaitymas(struct miestas mie[], int &n)
{
    ifstream data("U2.txt");

    char mPav[21], aPav[14];

    data >> n;
    data.ignore();
    for (int i = 0; i < n; i++)
    {
        data.get(mPav, 21);
        mie[i].miestas = mPav;
        data.get(aPav, 14);
        mie[i].apskritis = aPav;
        data >> mie[i].gyventojai;
        data.ignore();
    }

    data.close();
    return;
}

void formavimas(struct apskritis aps[], struct miestas mie[], int n, int &a)
{
    int rasta;

    for (int i = 0; i < n; i++)
    {
        rasta = 0;
        for (int j = 0; j < a; j++)
        {
            if (mie[i].apskritis == aps[j].apskritis)
            {
                rasta = 1;
                aps[j].sumGyventojai += mie[i].gyventojai;
                if (aps[j].mazGyventojai > mie[i].gyventojai)
                    aps[j].mazGyventojai = mie[i].gyventojai;
            }
        }
        if (rasta == 0)
        {
            aps[a].apskritis = mie[i].apskritis;
            aps[a].mazGyventojai = mie[i].gyventojai;
            aps[a].sumGyventojai = mie[i].gyventojai;
            a++;
        }
    }
    return;
}
void rikiavimas(struct apskritis aps[], int a)
{
    struct apskritis nereikalingas; // "nereikalingas" naudojamas laikinam kintamojo laikimui
    for (int i = 0; i < a - 1; i++)
        for (int j = i; j < a; j++)
            if (aps[i].mazGyventojai > aps[j].mazGyventojai)
            {
                nereikalingas = aps[i];
                aps[i] = aps[j];
                aps[j] = nereikalingas;
            }
    return;
}

void irasymas(struct apskritis aps[], int a)
{
    ofstream data("U2rez.txt");
    data << a << endl;
    for (int i = 0; i < a; i++)
        data << aps[i].apskritis << aps[i].mazGyventojai << " " << aps[i].sumGyventojai << endl;
    data.close();
    return;
}
