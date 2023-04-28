/**
 * @file Room.h
 * @author Liu JiaXing (lsnfzj@gmail.com)
 * @brief Header file for room class 
 * @version 0.1
 * @date 2023-04-13
 * 
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <map>

using namespace std;

class Room
{
private:
    string name;
    vector<string> actions;
    map<string, Room *> exits;
    bool hasPrincess ;
    bool hasMonster ;

public:
    Room(string name);
    Room() {};
    void setPrincess(bool value);
    void setMonster(bool value);
    void addAction(string action, Room *room);
    bool hasAction(string action) const;
    bool hasExit(string direction) const;
    Room *getExit(string direction) const;
    string getName() const;
    bool princess() const;
    bool monster() const;
    void printInfo() const;
};
