#include<string>
#include<iostream>
#include"record.h"
#include<cstring>
#include <iomanip>
using namespace std;

StudentRecord::StudentRecord(string name, double scores[3]) 
{
    this->name = name;
    memcpy(this->scores, scores, 3);
}

StudentRecord::StudentRecord() 
{
}

string StudentRecord::getName()
{
    return this->name;
}

void StudentRecord::setName(string name)
{
    this->name = name;
}

// Set attribute scores  
void StudentRecord::setRecords(double scores[])
{
    for(int i = 0; i < 3; i++)
    {
        this->scores[i] = scores[i];
    }
}

int StudentRecord::getScores(int index)
{
    return this->scores[index];
}
double StudentRecord::getAverage()
{
    double sum = 0;
    for(double score: this->scores)
    {
        sum += score;
    }

    return sum / TOTAL;
}
/**
 * @brief 
 * output average score
 * @param average 
 */
void outAverage()
{
    cout << setw(6) << left << "" << setw(10) << left << "average" ;
    cout << setw(10) << left << average[0] / 10 ;
    cout << setw(10) << left << average[1] / 10;
    cout << setw(10) << left << average[2] / 10 << endl ;
}
/**
 * @brief 
 * output min score
 * @param min 
 */
void outMin(double* min)
{
    cout << setw(6) << left << "" << setw(10) << left << "min" ;
    cout << setw(10) << left << min[0];
    cout << setw(10) << left << min[1];
    cout << setw(10) << left << min[2]  << endl ;
}
/**
 * @brief 
 * output max score
 * @param max 
 */
void outMax(double* max)
{
    cout << setw(6) << left << "" << setw(10) << left << "max" ;
    cout << setw(10) << left << max[0];
    cout << setw(10) << left << max[1];
    cout << setw(10) << left << max[2]  << endl ;
}
int main() 
{
    StudentRecord* records = new StudentRecord[10];
    double average[3] = {0, 0, 0};
    double min[3] = {5, 5 ,5};
    double max[3] = {0, 0, 0};
    for(int i = 0; i < 10; i++)
    {
        string name;
        cin >> name;
        double scores[3];
        cin >> scores[0] >> scores[1] >> scores[2];
        
        for(int j = 0; j < 3; j++)
        {
            average[j] += scores[j];
            min[j] = min[j] < scores[j] ? min[j] : scores[j];
            max[j] = max[j] > scores[j] ? max[j] : scores[j];
        }

        records[i].setName(name);
        records[i].setRecords(scores);
    }
    cout << setw(6) << left << "no" << setw(10) << left << "name";
    cout << setw(10) << left << "score1" ;
    cout << setw(10) << left << "score2" ;
    cout << setw(10) << left << "score3" ;
    cout << setw(10) << left << "average" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << setw(6) << left << i + 1<< setw(10) << left << records[i].getName();
        cout << setw(10) << left << records[i].getScores(0) ;
        cout << setw(10) << left << records[i].getScores(1) ;
        cout << setw(10) << left << records[i].getScores(2) ;
        cout << setw(10) << left << records[i].getAverage() << endl ;
    }
    outAverage(average);
    outMin(min);
    outMax(max);
}

