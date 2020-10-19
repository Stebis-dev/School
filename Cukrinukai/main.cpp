//Cukrinukai
#include <iostream>
#include <fstream>

using namespace std;

void fileRead(int hight[], int & amount, int & maxHightLimit);

int main(){
    static int hight[1000];
    static int rezult[1000];
    int maxHightLimit, amount;
    fileRead(hight, amount, maxHightLimit);
    
    static int a[1000];
    int highestSum = 0, melted = 0;

    for (int i = 1; i <= amount; i++)
        a[i] = 1;

    for (int i = 1; i <= amount; i++){
        if (hight[i] + maxHightLimit >= hight[i - 1] && hight[i] + maxHightLimit >= hight[i + 1] ){
            rezult[i] = 1;
            a[i] = 0;
            a[i + 1] = 0;
            a[i - 1] = 0;
            highestSum += 1;
        }
    }
    int temp = 0;
    for (int i = 1; i <= amount; i++){
        //if (rezult[i] != 0 && rezult[i + 1] != 0 && rezult[i - 1] == 0 && rezult[i + 3] == 0 && rezult[i - 2] != 0)
        //    rezult[i] = 0;
        if (highestSum == amount && i % 2){
            temp += rezult[i];
            rezult[i] = 0;
            }
    }
    highestSum -= temp;
    for (int i = 0; i <= amount; i++)
        melted += a[i];

    ofstream rez ("U2.txt");
    if (melted != 0)
        rez << "Nepavyks\n";
    else{
        rez << highestSum << endl;
        for (int i = 1; i <= amount; i++)
            if (rezult[i] != 0)
                rez << i << " ";
    }
    rez.close();
    return 0;
}

void fileRead(int hight[], int & amount, int & maxHightLimit){
    ifstream data ("U1.txt");
    data >> amount >> maxHightLimit;
    for (int i = 1; i <= amount; i++)
        data >> hight[i];
    data.close();
    return;
}

