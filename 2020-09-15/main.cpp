#include <iostream>
#include <fstream>
#define dydis 100

using namespace std;

struct group{
    int grupesNr;
    string grupesPav;
};
struct preke{
    int grupesNr;
    int prekesNr;
    string prekesPav;
};
struct irasa{
    int grupesNr;
    int prekesNr;
    string grupesPav;
    string prekesPav;
};

void irasoPildymas (group grup[], preke prek[], irasa ira[], int grupesN, int prekesN);
void nuskaitymas (group grup[], preke prek[], int & grupesN, int & prekesN);
void menu (group grup[], preke prek[], irasa ira[], int & grupesN, int & prekesN);
void rikiavimasPagalGrupesNr (irasa ira[], int prekesN);
void rikiavimasPagalPrekesNr (irasa ira[], int prekesN);
void rikiavimasPagalGrupesAbc (irasa ira[], int prekesN);
void rikiavimasPagalPrekesAbc (irasa ira[], int prekesN);
void prekiuFailoPildymas (preke prek[], int & prekesN);
void grupesFailoPildymas (group grup[], int & grupesN);
void pakeitimuIs (group grup[], preke prek[], int grupesN, int prekesN);

int main(){
    struct group grup[dydis];
    struct preke prek[dydis];
    struct irasa ira[dydis];
    int grupesN, prekesN;
    nuskaitymas(grup, prek, grupesN, prekesN);
    menu(grup, prek, ira, grupesN, prekesN);
    return 0 ;
}

void nuskaitymas (group grup[], preke prek[], int & grupesN, int & prekesN){
    grupesN = 0;
    prekesN = 0;

    ifstream data1 ("grupes.txt");
    while(!data1.eof()){
        data1 >> grup[grupesN].grupesNr >> grup[grupesN].grupesPav;
        grupesN ++;
    }
    data1.close();

    ifstream data2 ("prekes.txt");
    while(!data2.eof()){
        data2 >> prek[prekesN].grupesNr >> prek[prekesN].prekesNr >> prek[prekesN].prekesPav;
        prekesN ++;
    }
    data2.close();
    return;
}

void irasoPildymas (group grup[], preke prek[], irasa ira[], int grupesN, int prekesN){
    for (int i = 0; i < prekesN; i++){
        ira[i].grupesNr = prek[i].grupesNr;
        ira[i].prekesNr = prek[i].prekesNr;
        ira[i].prekesPav = prek[i].prekesPav;
        for (int j = 0; j < grupesN; j++)
            if (prek[i].grupesNr == grup[j].grupesNr)
                ira[i].grupesPav = grup[j].grupesPav;
    }
    return ;
}

void menu(group grup[], preke prek[], irasa ira[], int & grupesN, int & prekesN){
    int pasirinkimas = 1;
    bool tvarkyta = false;
    struct irasa atsarginis;

    irasoPildymas(grup, prek, ira, grupesN, prekesN);

    while (pasirinkimas != 0){
        cout << "Rikiavimas pagal grupes nr (didejimo tvarka) 1\n";
        cout << "Rikiavimas pagal prekiu nr (didejimo tvarka) 2\n";
        cout << "Rikiavimas pagal grupes abc..................3\n";
        cout << "Rikiavimas pagal prekiu abc..................4\n";
        cout << "kiesti prkiu duomenis........................5\n";
        cout << "kiesti grupes duomenis.......................6\n";
        cout << "Exit.........................................0\n";

        cin >> pasirinkimas;
        cout << endl;

        switch (pasirinkimas){
            case 1:
                rikiavimasPagalGrupesNr(ira, prekesN);
                break;
            case 2:
                rikiavimasPagalPrekesNr(ira, prekesN);
                break;
            case 3:
                rikiavimasPagalGrupesAbc(ira, prekesN);
                break;
            case 4:
                rikiavimasPagalPrekesAbc(ira, prekesN);
                break;
            case 5:
                tvarkyta = true;
                prekiuFailoPildymas(prek, prekesN);
                irasoPildymas(grup, prek, ira, grupesN, prekesN);
                break;
            case 6:
                tvarkyta = true;
                grupesFailoPildymas(grup, grupesN);
                irasoPildymas(grup, prek, ira, grupesN, prekesN);
                break;
        }
        if (pasirinkimas != 0)
            for (int i = 0; i < prekesN; i++){
                cout << ira[i].grupesNr << " ";
                cout << ira[i].grupesPav << " ";
                cout << ira[i].prekesNr << " ";
                cout << ira[i].prekesPav << " \n";
            }
        cout << "______________________________________________\n";
    }
    if (tvarkyta){
        cout <<"Ar norite issaugoti pakeitimus ?\n\t 0 = ne \t 1 = taip\n";
        cin >> pasirinkimas;
        if (pasirinkimas == 1)
            pakeitimuIs(grup, prek, grupesN, prekesN);
    }
    return ;
}

void rikiavimasPagalGrupesNr (irasa ira[], int prekesN){
    struct irasa atsarginis;
    for (int i = 0; i < prekesN - 1; i++)
        for (int j = i +1; j < prekesN; j++)
            if (ira[i].grupesNr > ira[j].grupesNr){
                atsarginis = ira[i];
                ira[i] = ira[j];
                ira[j] = atsarginis;
            }
    return;
}

void rikiavimasPagalPrekesNr (irasa ira[], int prekesN){
    struct irasa atsarginis;
    for (int i = 0; i < prekesN - 1; i++)
        for (int j = i +1; j < prekesN; j++)
            if (ira[i].prekesNr > ira[j].prekesNr){
                atsarginis = ira[i];
                ira[i] = ira[j];
                ira[j] = atsarginis;
            }
    return;
}

void rikiavimasPagalGrupesAbc (irasa ira[], int prekesN){
    struct irasa atsarginis;
    for (int i = 0; i < prekesN - 1; i++)
        for (int j = i +1; j < prekesN; j++)
             if (ira[i].grupesPav > ira[j].grupesPav){
                atsarginis = ira[i];
                ira[i] = ira[j];
                ira[j] = atsarginis;
            }
    return;
}

void rikiavimasPagalPrekesAbc (irasa ira[], int prekesN){
    struct irasa atsarginis;
    for (int i = 0; i < prekesN - 1; i++)
        for (int j = i +1; j < prekesN; j++)
            if (ira[i].prekesPav > ira[j].prekesPav){
                atsarginis = ira[i];
                ira[i] = ira[j];
                ira[j] = atsarginis;
            }
    return;
}

void prekiuFailoPildymas (preke prek[], int & prekesN){
    int grupesNr, prekesNr;
    string prekesPav;
    cout << "Iveskite prekes grupesNr : ";
    cin >> grupesNr;
    cout << "Iveskite prekesNr : ";
    cin >> prekesNr;
    cout << "Iveskite prekesPav : ";
    cin >> prekesPav;
    prek[prekesN].grupesNr = grupesNr;
    prek[prekesN].prekesNr = prekesNr;
    prek[prekesN].prekesPav = prekesPav;
    prekesN ++;    
    return;
}

void grupesFailoPildymas (group grup[], int & grupesN){
    int grupesNr;
    string grupesPav;
    cout << "Iveskite grupesNr : ";
    cin >> grupesNr;
    cout << "Iveskite grupesPav : ";
    cin >> grupesPav;
    grup[grupesN].grupesNr = grupesNr;
    grup[grupesN].grupesPav = grupesPav;
    grupesN ++;
    return;
}

void pakeitimuIs (group grup[], preke prek[], int grupesN, int prekesN){
    ofstream data1 ("grupes.txt");
    for (int i = 0 ; i < grupesN; i++){
        data1 << grup[i].grupesNr << " " << grup[i].grupesPav;
        if (i != grupesN - 1)
            data1 << '\n';
    }
    data1.close();

    ofstream data2 ("prekes.txt");
    for (int i = 0; i < prekesN; i++){
        data2 << prek[i].grupesNr << " " << prek[i].prekesNr << " " << prek[i].prekesPav;
        if (i != prekesN - 1)
            data2 << '\n';
    }
    data2.close();
    return;
}
