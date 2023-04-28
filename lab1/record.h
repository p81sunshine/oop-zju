#pragma once

#include <string>

#define TOTAL 3
using namespace std;


class StudentRecord {
public:
    StudentRecord(string name, double scores[3]);
    StudentRecord();
    string getName();
    void setName(string name);
    void setRecords(double* scores);
    double getAverage();
    int  getScores(int index);

private:
    string name;
    double scores[TOTAL];
};
