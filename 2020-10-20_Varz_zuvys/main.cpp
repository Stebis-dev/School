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
	int kieks;
	objektas pagautos[5];
};

void nuskaitymas(zvejas zvj[30], objektas zuvys[30], int &n, int &k);

int main()
{
	zvejas zvj[30];
	objektas zuvys[30];
	int n, k;

	nuskaitymas(zvj, zuvys, n, k);

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
		data >> zvj[i].kieks;

		for (int j = 0; j < zvj[i].kieks; j++)
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
		data.get(vardas, 21);
		zuvys[i].vardas = vardas;
		data >> zuvys[i].kiekis;
	}
	data.close();
	return;
}

/*
	cout << n << endl;
	for (int i = 0; i < n; i++)
	{
		cout << zvj[i].vardas << zvj[i].kieks << '\n';
		for (int j = 0; j < zvj[i].kieks; i++)
			cout << zvj[i].pagautos[j].vardas << zvj[i].pagautos[j].kiekis << '\n';
	}
	cout << k << '\n';
	for (int i = 0; i < k; i++)
		cout << zuvys[i].vardas << zuvys[i].kiekis << '\n';

*/