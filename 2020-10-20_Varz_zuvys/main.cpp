#include <iostream>
#include <fstream>

using namespace std;

struct objektas
{
	string vardas;
	int kiekis;
};
struct zvejas
{
	string vardas;
	int kiekis;
	objektas pagautos[5];
};

void nuskaitymas(zvejas zvj[30], objektas zuvys[30], int &n, int &k);
void formavimas(zvejas zvj[30], objektas zuvys[30], int &n, int &k, objektas zuvys2[30], objektas zvj2[30]);
void rikiavimas(objektas masyvas[30], int n);
void spausdinimas(objektas zvj2[30], int n, objektas zuvys2[30], int k);

int main()
{
	zvejas zvj[30];
	objektas zuvys[30], zuvys2[30], zvj2[30];
	int n, k;

	nuskaitymas(zvj, zuvys, n, k);
	formavimas(zvj, zuvys, n, k, zuvys2, zvj2);
	//rikiuojame zvejus
	rikiavimas(zvj2, n);
	//rikiuojame zuvis
	rikiavimas(zuvys2, k);
	spausdinimas(zvj2, n, zuvys2, k);

	return 0;
}
void nuskaitymas(zvejas zvj[30], objektas zuvys[30], int &n, int &k)
{
	ifstream data("U2.txt");

	data >> n;

	char vardas[21];

	for (int i = 0; i < n; i++)
	{
		data.ignore();
		data.get(vardas, 21);
		zvj[i].vardas = vardas;
		data >> zvj[i].kiekis;

		for (int j = 0; j < zvj[i].kiekis; j++)
		{
			data.ignore();
			data.get(vardas, 21);
			zvj[i].pagautos[j].vardas = vardas;
			data >> zvj[i].pagautos[j].kiekis;
		}
	}

	data >> k;

	for (int i = 0; i < k; i++)
	{
		data.ignore();
		data.get(vardas, 21);
		zuvys[i].vardas = vardas;
		data >> zuvys[i].kiekis;
	}
	data.close();
	return;
}

void formavimas(zvejas zvj[30], objektas zuvys[30], int &n, int &k, objektas zuvys2[30], objektas zvj2[30])
{
	for (int i = 0; i < k; i++)
	{
		zuvys2[i].vardas = zuvys[i].vardas;
		zuvys2[i].kiekis = 0;
	}
	for (int i = 0; i < n; i++)
	{
		zvj2[i].vardas = zvj[i].vardas;
		zvj2[i].kiekis = 0;

		for (int j = 0; j < zvj[i].kiekis; j++)
			for (int a = 0; a < k; a++)
				if (zuvys2[a].vardas == zvj[i].pagautos[j].vardas)
				{
					zuvys2[a].kiekis += zvj[i].pagautos[j].kiekis;
					zvj2[i].kiekis += zuvys[a].kiekis;
					if (zvj[i].pagautos[j].kiekis > 200)
						zvj2[i].kiekis += 30;
					else
						zvj2[i].kiekis += 10;
				}
	}
	return;
}

void rikiavimas(objektas masyvas[30], int n)
{
	objektas atsarginis;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (masyvas[i].kiekis < masyvas[j].kiekis || masyvas[i].kiekis == masyvas[j].kiekis && masyvas[i].vardas < masyvas[j].vardas)
			{
				atsarginis = masyvas[i];
				masyvas[i] = masyvas[j];
				masyvas[j] = atsarginis;
			}
	return;
}

void spausdinimas(objektas zvj2[30], int n, objektas zuvys2[30], int k)
{
	ofstream data("U2rez.txt");

	data << "Dalyviai\n";
	for (int i = 0; i < n; i++)
		data << zvj2[i].vardas << zvj2[i].kiekis << '\n';

	data << "Laimikis\n";
	for (int i = 0; i < k; i++)
		data << zuvys2[i].vardas << zuvys2[i].kiekis << '\n';
	data.close();
	return;
}