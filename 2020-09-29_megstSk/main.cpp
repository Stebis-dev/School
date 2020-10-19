//komentaras
#include <iostream>
#include <fstream>

using namespace std;

struct info
{
    int sk[10];
};

void nuskaitymas(int &n, int &m, info dalyvis[], int bend[]);
void populiariausias(int m, int bend[], int pop[]);

int main()
{
    struct info dalyvis[10];
    int n, m;
    static int bend[10], pop[10];
    nuskaitymas(n, m, dalyvis, bend);

    for (int i = 0; i < m; i++)
        cout << i + 1 << " " << bend[i] << '\n';

    populiariausias(m, bend, pop);
    return 0;
}

void nuskaitymas(int &n, int &m, info dalyvis[], int bend[])
{
    string nereikalingas;
    ifstream data("prad.txt");

    data >> n >> m;
    for (int i = 0; i < n; i++)
    {
        data >> nereikalingas;
        for (int j = 0; j < m; j++)
        {
            data >> dalyvis[i].sk[j];
            bend[dalyvis[i].sk[j] - 1]++;
        }
    }
    return;
}
void populiariausias(int m, int bend[], int pop[])
{
    int a = 0;
    pop[a] = bend[0];
    int atsarginis = 0;
    for (int i = 1; i < m; i++)
        if (pop[a] < bend[i])
        {
            pop[a] = bend[i];
            atsarginis = i + 1;
        }

    cout << pop << " " << atsarginis;

    for (int i = 0; i < m; i++)
    {
        if (pop[a] == bend[i] && i != atsarginis)
            pop[a]
    }

    return;
}