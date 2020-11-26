#include <iostream>
#include <fstream>

using namespace std;

void nuskaitymas(int paieska[5]);
void skaiciavimai(int paieska[5], int visi[10]);
void irasymas(int visi[10]);

int main()
{
    int paieska[5];
    int visi[10] = {0};
    nuskaitymas(paieska);
    skaiciavimai(paieska, visi);
    irasymas(visi);
    return 0;
}

void nuskaitymas(int paieska[5])
{
    ifstream data("U1.txt");
    for (int i = 0; i < 5; i++)
        data >> paieska[i];
    return;
}

void skaiciavimai(int paieska[5], int visi[10])
{

    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (paieska[i] > 0)
            {
                visi[j]++;
                paieska[i]--;
            }
        }
        visi[i] += paieska[i];
        //cout << visi[i] << " ";
    }

    return;
}
void irasymas(int visi[10])
{
    ofstream data("U2rez.txt");
    for (int i = 0; i < 10; i++)
        data << visi[i] << " ";
    return;
}
