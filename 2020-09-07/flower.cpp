#include <iostream>
#include <fstream>
#define days 92

using namespace std;

void readingFile(int flowerArray[]);
void writingFile(int highestNumber, int startingDay, int endingDay);
int monthToDayConversion(int month);
int dayToMonthConversion(int day);
int mostDiffrentFlowerNumber(int flowerArray[]);
int monthAndDayBegining(int flowerArray[]);
int monthAndDayEnding(int flowerArray[]);

int main (){
    static int flowerArray[days];
    readingFile(flowerArray);
    writingFile(mostDiffrentFlowerNumber(flowerArray), monthAndDayBegining(flowerArray), monthAndDayEnding(flowerArray));
    return 0;
}

void readingFile(int flowerArray[]){
    int n, useless, monthBegining, dayBegining, monthEnd, dayEnd;
    ifstream data ("U1.txt");
    data >> n;
    for (int i = 0 ; i < n; i++){
        data >> useless;
        data >> monthBegining >> dayBegining;
        data >> monthEnd >> dayEnd;
        for (int i = monthToDayConversion(monthBegining) + dayBegining; i < (monthToDayConversion(monthEnd) + dayEnd); i++)
            flowerArray[i]++;
    }
    data.close();
    return;
}

int monthToDayConversion(int month){
    switch (month)
    {
    case 8:
        return 30 + 31;
    case 7:
        return 30;
    case 6:
        return 0;
    }
    return 0;
}

int dayToMonthConversion(int day){
    if (day > 61)
        return day - 61 + 800;
    if (day > 30)
        return day - 30 + 700;
    return day + 600;    
}

int mostDiffrentFlowerNumber(int flowerArray[]){
    // firstArray = is flowerArray's [0] used for finding largest number and also it's used to return highest number
    int firstArray = flowerArray[0];
    for (int i = 1; i < days; i++)
        if (firstArray < flowerArray[i])
            firstArray = flowerArray[i];
        
    return firstArray;
}

int monthAndDayBegining(int flowerArray[]){
    //using same part as in mostDiffrentFlowerNumber couse it works
    int firstArray = flowerArray[0];
    int staritnPoint;
    for (int i = 1; i < days; i++)
        if (firstArray < flowerArray[i]){
            firstArray = flowerArray[i];
            staritnPoint = i;
        }
    return dayToMonthConversion(staritnPoint) ;
}

int monthAndDayEnding(int flowerArray[]){
    //using same part as in mostDiffrentFlowerNumber couse it works
    int firstArray = flowerArray[0];
    int staritnPoint;
    for (int i = 1; i < days; i++)
        if (firstArray < flowerArray[i]){
            firstArray = flowerArray[i];
            staritnPoint = i;
        }
    
    for (int i = staritnPoint; i < days ; i++)
        if (firstArray != flowerArray[i])
            return dayToMonthConversion(i);
    return 0;
}

void writingFile(int highestNumber, int startingDay, int endingDay ){
    ofstream data ("U2.txt");
    data << highestNumber << '\n';
    data << startingDay/100 << " " << startingDay%100 << '\n';
    data << endingDay/100 << " " << endingDay%100 <<'\n';
    data.close();
    return;
}
