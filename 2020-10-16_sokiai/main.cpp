//2020-10-16-sok
#include <iostream>
#include <fstream>
#define n 100
#define k 10

using namespace std;

struct sokejai
{
    string vardai;
    int technikosTaskai[k];
    int artistiskumoTaskai[k];
    int techniskosSuma;
    int artistiskumoSuma;
    int bendraSuma;
};

void nuskaitymas(sokejai sok[], int &sokejuSk, int &teisejusSk);
int taskuSkaiciavimas(int taskuMasyvas[], int teisejuSk);
void rikiavimas(sokejai sok[], int sokejuSk);
void spausdinimas(sokejai sok[], int sokejuSk);

int main()
{
    struct sokejai sok[n];
    int sokejuSk, teisejuSk;
    nuskaitymas(sok, sokejuSk, teisejuSk);
    rikiavimas(sok, sokejuSk);
    spausdinimas(sok, sokejuSk);

    return 0;
}

void nuskaitymas(sokejai sok[], int &sokejuSk, int &teisejusSk)
{
    char sokejuVardai[21];

    ifstream data("U2.txt");
    data >> sokejuSk >> teisejusSk;

    for (int i = 0; i < sokejuSk; i++)
    {
        data.ignore();
        data.get(sokejuVardai, 21);
        sok[i].vardai = sokejuVardai;

        for (int j = 0; j < teisejusSk; j++)
            data >> sok[i].technikosTaskai[j];
        sok[i].techniskosSuma = taskuSkaiciavimas(sok[i].technikosTaskai, teisejusSk);
        for (int j = 0; j < teisejusSk; j++)
            data >> sok[i].artistiskumoTaskai[j];
        sok[i].artistiskumoSuma = taskuSkaiciavimas(sok[i].artistiskumoTaskai, teisejusSk);

        sok[i].bendraSuma = sok[i].artistiskumoSuma + sok[i].techniskosSuma;
    }
    data.close();
    return;
}
int taskuSkaiciavimas(int taskuMasyvas[], int teisejuSk)
{
    int suma = 0;
    int atsarginis;

    for (int i = 0; i < teisejuSk - 1; i++)
        for (int j = i + 1; j < teisejuSk; j++)
            if (taskuMasyvas[i] < taskuMasyvas[j])
            {
                atsarginis = taskuMasyvas[i];
                taskuMasyvas[i] = taskuMasyvas[j];
                taskuMasyvas[j] = atsarginis;
            }

    taskuMasyvas[0] = 0;
    taskuMasyvas[teisejuSk - 1] = 0;

    for (int i = 0; i < teisejuSk; i++)
        suma += taskuMasyvas[i];

    return suma;
}
void rikiavimas(sokejai sok[], int sokejuSk)
{
    struct sokejai atsarginis;

    for (int i = 0; i < sokejuSk - 1; i++)
        for (int j = i + 1; j < sokejuSk; j++)
            if (sok[i].bendraSuma < sok[j].bendraSuma)
            {
                atsarginis = sok[i];
                sok[i] = sok[j];
                sok[j] = atsarginis;
            }
    return;
}
void spausdinimas(sokejai sok[], int sokejuSk)
{
    ofstream data("U2rez.txt");
    for (int i = 0; i < sokejuSk; i++)
        data << sok[i].vardai << sok[i].bendraSuma << endl;
    data.close();
    return;
}
