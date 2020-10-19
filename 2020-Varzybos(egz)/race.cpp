#include <iostream>
#include <fstream>

using namespace std;

struct info
{
    string name;
    int fishAmount;
    int score;
};

void readingFile(info participants[], int n);

int main(){
    int n;
    info participants[30];
    readingFile(participants, n);
    return 0;
}

void readingFile(info participants[], int n){
    ifstream data ("U1.txt");
    data >> n;
    string a;
    for (int i = 0; i < n; i++){
        while (getline(data,a))
        {
            data >> a;
            participants[i].name += a;
        }
        cout << participants[i].name;
    }
    return;
}
