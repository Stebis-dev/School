#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    static int laukoX, laukoY;
    int laukas[500][500];
    int daugiausias = 0;

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
    cout << daugiausias;

    return 0;
}
