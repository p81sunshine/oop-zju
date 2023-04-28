#include<iostream>
#include<string>
#include<vector>
#include <fstream>
#include <sstream>
#include "entity.h"
#include "diary.h"

using namespace std;
void Diary::Read(string name )
{
    ifstream file(name);
    if (!file)
    {
        cerr << "Ooops, Load diary Error!" << endl;
        exit(-100);
    } 

    string line;
    while (getline(file, line))
    {
        Entity e;
        e.setDate(line);
        string date = line.substr(0,8);
        
        getline(file, line);
        while (!(line[0] == '.' && line.size() <= 2))
        {
            e.addContent(line);
            getline(file, line);
        }

        content[date] = e;
    }

    
}

void Diary::Save(string name )
{
    ofstream file(name);
    
    for (auto& [s, entity]: content)
    {
        entity.write(file);
    }

}

void Diary::add()
{
    Entity e;
    string line;
    cin >> line;
    string date = line.substr(0, 8);
    e.setDate(line);
    
    cin >> line;
    while (line != ".")
    {
        e.addContent(line);
        cin >> line;
    }

    content[date] = e;
    
}

void Diary::list()
{
    for(auto& [p, c]: content)
    {
        c.showInfo();
    }
}

void Diary::list(int year_s, int month_s, int day_s, int year_e, int month_e, int day_e)
{
    int s = year_s * 10000 + month_s * 100 + day_s;
    int e = year_e * 10000 + month_e * 100 + day_e;
    cout << "\n----------List result---------\n\n";
    for(auto& [p, c]: content)
    {
        if(c.inRange(s, e))
        {
            c.showInfo();
        }
    }
}

void Diary::show()
{
    string date;
    cin >> date;
    date = date.substr(0,8);
    if (content.count(date))
        content[date].showContent();
    else
        cout << "No record at this date" << endl;
}

int Diary::remove(string date)
{
    date = date.substr(0,8);
    if (content.count(date))
    {
        content.erase(date);
        cout << "Successfully delete!" << endl;
        return 0;
    }
    
    return -1;
}
