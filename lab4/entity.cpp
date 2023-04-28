#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "entity.h"


using namespace std;

void Entity::setDate(string line)
{
    d = line;
    string t = line.substr(0,4);
    year = stoi(t);

    t = line.substr(4, 2);
    month = stoi(t);

    t = line.substr(6,2);
    day = stoi(t);
    
}

void Entity::addContent(string &line)
{
    content.push_back(line);
}

void Entity::write(ofstream &file)
{
    file << to_string(year);
    string m;
    if (month < 10)
        m = "0" + to_string(month);
    else 
        m = to_string(month);
    file << m;

    if (day < 10)
        m = "0" + to_string(day);
    else 
        m = to_string(day);

    file << m << endl;

    for (string& line: content)
    {
        file << line << endl;
    }
    file << "." << endl;
}

bool Entity::inRange(int s, int e)
{
    int m = year * 10000 + month * 100 + day;
    if (m >= s && m <= e)
        return true;
    else
        return false;
}

void Entity::showInfo()
{
    cout << d << endl;
    if(content.size() != 0)
        cout << content[0] << endl;
    else
        cout << "Oooops, Empty diary\n";
}

void Entity::showContent()
{
    for(auto& e: content)
    {
        cout << e << endl;
    }
}

