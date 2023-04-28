#pragma once
#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Entity
{
    private:
        std::vector<string> content;
        string d;
        int year;
        int month;
        int day;
    
    public:
        void setDate(string line);
        void addContent(string &line);
        void write(ofstream &file);
        bool inRange(int s, int e);
        void showInfo();
        void showContent();

};