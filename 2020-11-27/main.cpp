#include <iostream>
#include <fstream>

using namespace std;

void nuskaitymas(int &x, int &y, int laukas[500][500])
{
    cin >> y >> x;
    char vertimui;
    for (int i = 1; i <= y; i++)
        for (int j = 1; j <= x; j++)
        {
            cin >> vertimui;
            if (vertimui == '.')
                laukas[i][j] = 0;
            else if (vertimui == 'o')
                laukas[i][j] = 1;
            else
                laukas[i][j] = -1;
        }
    return;
}
void nuskaitymas(int &x, int &y, int laukas[500][500], string filename)
{
    ifstream data(filename);
    data >> y >> x;
    char vertimui;
    for (int i = 1; i <= y; i++)
        for (int j = 1; j <= x; j++)
        {
            data.ignore();
            data >> vertimui;
            if (vertimui == '.')
                laukas[i][j] = 0;
            else if (vertimui == 'o')
                laukas[i][j] = 1;
            else
                laukas[i][j] = -1;
        }
    return;
}

void irasymas(int x, int y, int laukas[500][500], int daugiausias)
{
    cout << y << " " << x << endl;
    for (int i = 1; i <= y; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (laukas[i][j] == 0)
                cout << '.';
            else if (laukas[i][j] == 1)
                cout << 'o';
            else
                cout << 'x';
            cout << " ";
        }
        cout << endl;
    }
    cout << "Daugiausias = " << daugiausias << endl;

    return;
}
void irasymas(int x, int y, int laukas[500][500], int daugiausias, string filename)
{
    ofstream data(filename);
    data << y << " " << x << endl;

    for (int i = 1; i <= y; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (laukas[i][j] == 0)
                data << '.';
            else if (laukas[i][j] == 1)
                data << 'o';
            else
                data << 'x';
            data << " ";
        }
        data << endl;
    }
    data << "Daugiausias = " << daugiausias << endl;

    return;
}

int main()
{
    static int laukoX, laukoY;
    int laukas[500][500];
    int daugiausias = 0;

    /// Nuskaitymas
    nuskaitymas(laukoX, laukoY, laukas, "U2.txt");

    int x = laukoX, y = laukoY, laikinas = 0;
    for (int h = laukoX; h > 0; h--)
    {
        laikinas = 0;
        x = h;
        y = laukoY;
        if (laukas[y][x] != -1)
            for (int i = y; i > 0; i--)
                for (int j = x; j > 0; j--)
                {
                    if (laukas[i][j] == 1)
                        laikinas++;
                    if (laukas[i][j - 1] == -1)
                    {
                        y = i - 1;
                        x = j;
                        break;
                    }
                    x = j;
                }
        if (daugiausias < laikinas)
            daugiausias = laikinas;
    }
    ///Irasyams
    irasymas(laukoX, laukoY, laukas, daugiausias, "U2.txt");
    irasymas(laukoX, laukoY, laukas, daugiausias);
    return 0;
}
