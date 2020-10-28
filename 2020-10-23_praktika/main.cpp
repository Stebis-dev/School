#include <iostream>
#include <fstream>

using namespace std;

struct vaikas
{
	string pavarde;
	string vardas;
	char lytis;
	int metai;
	int men;
	int diena;
};

void nuskaitymas(vaikas gimes[], int &n);
void menesesiuSkaiciavimas(vaikas gimes[], int n, int men[]);
int lytiesKiekis(vaikas gimes[], int n, char lytis);
string popliariausiasVardas(vaikas gimes[], int n, char lytis);
void irasymas(int bernSk, int mergSk, string popVyrVardas, string popMotVardas, int men[12]);

int main()
{
	static int n, bernSk, mergSk;
	static int men[12];
	vaikas gimes[10000];
	string popVyrVardas, popMotVardas;

	nuskaitymas(gimes, n);
	menesesiuSkaiciavimas(gimes, n, men);
	bernSk = lytiesKiekis(gimes, n, 'v');
	mergSk = lytiesKiekis(gimes, n, 'm');
	popVyrVardas = popliariausiasVardas(gimes, n, 'v');
	popMotVardas = popliariausiasVardas(gimes, n, 'm');
	irasymas(bernSk, mergSk, popVyrVardas, popMotVardas, men);

	return 0;
}

void nuskaitymas(vaikas gimes[], int &n)
{
	ifstream data("Duom1.txt");
	data >> n;
	data.ignore();
	char zodis[12];
	for (int i = 0; i < n; i++)
	{
		data.get(zodis, 12);
		gimes[i].pavarde = zodis;
		data.ignore();
		data.get(zodis, 12);
		gimes[i].vardas = zodis;
		data >> gimes[i].lytis;
		data >> gimes[i].metai >> gimes[i].men >> gimes[i].diena;
		data.ignore();
	}
	data.close();
	return;
}

int lytiesKiekis(vaikas gimes[], int n, char lytis)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		if (gimes[i].lytis == lytis)
			sum++;
	return sum;
}

string popliariausiasVardas(vaikas gimes[], int n, char lytis)
{
	string vardas[10];
	static int vardasSk[10];
	int same = 0, k = 0;

	for (int i = 0; i < n; i++)
	{
		if (gimes[i].lytis == lytis)
		{
			same = 0;
			for (int j = 0; j < k; j++)
			{
				if (gimes[i].vardas == vardas[j])
				{
					same = 1;
					vardasSk[j]++;
				}
			}
			if (same == 0)
			{
				vardasSk[k] = 1;
				vardas[k] = gimes[i].vardas;
				k++;
			}
		}
	}
	string atsarginis;
	int atsarga;
	for (int i = 0; i < k - 1; i++)
		for (int j = i + 1; j < k; j++)
			if (vardasSk[i] < vardasSk[j] || vardasSk[i] == vardasSk[j] && vardas[i] > vardas[j])
			{
				atsarginis = vardas[i];
				vardas[i] = vardas[j];
				vardas[j] = atsarginis;
				atsarga = vardasSk[i];
				vardasSk[i] = vardasSk[j];
				vardasSk[j] = atsarga;
			}

	return vardas[0];
}

void menesesiuSkaiciavimas(vaikas gimes[], int n, int men[])
{
	for (int i = 0; i < n; i++)
		men[gimes[i].men - 1]++;

	return;
}

void irasymas(int bernSk, int mergSk, string popVyrVardas, string popMotVardas, int men[12])
{
	ofstream data("Rez1.txt");

	data << "Berniukai: " << bernSk << '\n';
	data << popVyrVardas << '\n';
	data << "Mergaites: " << mergSk << '\n';
	data << popMotVardas << '\n';
	for (int i = 0; i < 12; i++)
		data << men[i] << " ";

	data.close();
	return;
}
