//idomi uzduotis
#include <iostream>
#include <fstream>

using namespace std;

struct komandos
{
	int komanduKiekis;
	int komanduMasyvas[30];
	string rezultatas;
	int praejo;
	int x;
	int y;
};

void nuskaitymas(komandos kmd[10], int &n, int &x, int &y);
void kordinates(komandos kmd[10], int n, int x, int y);
void irasymas(komandos kmd[10], int n);

int main()
{
	komandos kmd[10];
	int n, x, y;

	nuskaitymas(kmd, n, x, y);
	kordinates(kmd, n, x, y);
	irasymas(kmd, n);
	/*
    cout<< x << " " << y << endl;
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << '\n'
             << kmd[i].komanduKiekis << " ";
        for (int j = 0; j < kmd[i].komanduKiekis; j++)
            cout << kmd[i].komanduMasyvas[j] << " ";
    }
    */

	return 0;
}

void nuskaitymas(komandos kmd[10], int &n, int &x, int &y)
{
	ifstream data("U2.txt");

	data >> x >> y;
	data >> n;

	for (int i = 0; i < n; i++)
	{
		data >> kmd[i].komanduKiekis;
		for (int j = 0; j < kmd[i].komanduKiekis; j++)
			data >> kmd[i].komanduMasyvas[j];
	}
	data.close();
	return;
}

void kordinates(komandos kmd[10], int n, int x, int y)
{
	for (int i = 0; i < n; i++)
	{
		kmd[i].x = x;
		kmd[i].y = y;
		kmd[i].praejo = 0;
		for (int j = 0; j < kmd[i].komanduKiekis; j++)
		{
			switch (kmd[i].komanduMasyvas[j])
			{
			case 1:
				kmd[i].x++;
				kmd[i].y++;
				break;
			case 2:
				kmd[i].x++;
				kmd[i].y--;
				break;
			case 3:
				kmd[i].x--;
				kmd[i].y--;
				break;
			case 4:
				kmd[i].x--;
				kmd[i].y++;
				break;
			}

			kmd[i].praejo++;

			if (kmd[i].x == x && kmd[i].y == y)
			{
				kmd[i].rezultatas = "pasiektas tikslas   ";
				break;
			}
			else
				kmd[i].rezultatas = "sekos pabaiga       ";
		}
	}
	return;
}

void irasymas(komandos kmd[10], int n)
{
	ofstream data("U2rez.txt");

	for (int i = 0; i < n; i++)
	{
		if (kmd[i].rezultatas == "pasiektas tikslas   ")
		{
			data << kmd[i].rezultatas;
			for (int j = 0; j < kmd[i].praejo; j++)
				data << kmd[i].komanduMasyvas[j] << " ";
			data << kmd[i].praejo << '\n';
		}
		else
		{
			data << kmd[i].rezultatas;
			for (int j = 0; j < kmd[i].komanduKiekis; j++)
				data << kmd[i].komanduMasyvas[j] << " ";
			data << kmd[i].praejo << " ";
			data << kmd[i].x << " " << kmd[i].y << '\n';
		}
	}
	data.close();
	return;
}
