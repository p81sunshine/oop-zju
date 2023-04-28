/**
 * @file record.cpp
 * @author Liu JiaXing (lsnfzj@gmial.com)
 * @brief Implementation of the Student2 problem.
 * @version 0.1
 * @date 2023-03-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include<string>
#include<iostream>
#include"record.h"
#include<cstring>
#include <iomanip>
#include<vector>
#include<set>
#include <fstream>
#include <sstream>
using namespace std;


/**
 * @brief The number of people attending a course and the total grade 
 * 
 */
struct avergeinfo
{
    int avg; // Averge score
    int num; // The number of students in the course;
};


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
void StudentRecord::setScore(const string course, const int grade)
{
    this->scores[course] = grade; 
}

int StudentRecord::getScore(const string course)
{
    return this->scores[course];
}

double StudentRecord::getAverage()
{
    int i = 0;
    double total = 0;
    for(auto p: this->scores)
    {
        total += p.second;
        i++;
    }
    return total / i;
}

bool StudentRecord::isExist(string course)
{
    return this->scores.count(course);
}

/**
 * @brief Output the average socre infor. 
 * 
 * @param average 
 */
void outAverage(map<string, avergeinfo> average)
{
    cout << setw(6) << left << "" << setw(10) << left << "average" ;
    for(auto &p: average)
        cout << setw(10) << left << p.second.avg / (double)p.second.num;
    cout << endl;
}

void outMin(map<string, int> minScore)
{
    cout << setw(6) << left << "" << setw(10) << left << "min" ;
    for(auto p: minScore)
        cout << setw(10) << left << p.second;
    cout << endl;
}

void outMax(map<string, int> maxScore)
{
    cout << setw(6) << left << "" << setw(10) << left << "max" ;
    for(auto p: maxScore)
        cout << setw(10) << left << p.second;
    cout << endl;
}

int main() 
{
    vector<StudentRecord> students;
    map<string, int> minScore;
    map<string, int> maxScore;

    map<string, avergeinfo> average;
    set<string> course;
    

    /* Use a set to store all courses. */


    ifstream file("./test.txt");
    if (!file)
    {
        cerr << "Open file error!" << endl;
        return -1;
    }

    string record;
    /**
     * @brief Read the information line by line
     * , corresponding to the record of each student.
     * 
     */
    while(getline(file, record))
    {
        StudentRecord s;
        /**
         * @brief Convert the string to stream,
         * making we can read the information 
         * using cin. 
         * @return stringstream 
         */
        stringstream ss(record);
        string name;
        ss >> name;
        s.setName(name);

        int score;
        string course;
        while(ss >> course >> score)
        {
            s.setScore(course, score);
            if(average.count(course))// This course exists.
            {
               average[course].avg += score; 
               average[course].num++;
               minScore[course] = minScore[course] < score ? minScore[course] : score;
               maxScore[course] = maxScore[course] > score ? maxScore[course] : score;
            }
            else // This course does not exsit.
            {
                average[course] = {score, 1};
                minScore[course] = score;
                maxScore[course] = score;
            }
        }

        students.push_back(s);
    }

    cout << setw(6) << left << "no" << setw(10) << left << "name";
    for(auto&p: minScore)
    {
        cout << setw(10) << left << p.first;
    }
    cout << setw(10) << left << "average" << endl;

    int i = 0;
    for(auto s: students)
    {
        cout << setw(6) << left << ++i  << setw(10) << left << s.getName();
        for(auto&p: minScore)
        {
            string thisCourse = p.first; // The column for one specific course; 
            if(s.isExist(thisCourse))
                cout << setw(10) << left << s.getScore(thisCourse);
            else
                cout << setw(10) << left << "";;
        }
        cout << setw(10) << left << s.getAverage();
        cout << endl;
    }

    outAverage(average);
    outMin(minScore);
    outMax(maxScore);


    return 0;
        


}