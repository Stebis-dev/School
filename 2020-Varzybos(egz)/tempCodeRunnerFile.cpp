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