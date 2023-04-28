/**
 * @file Room.cpp
 * @author Liu JiaXing (lsnfzj@gmail.com)
 * @brief Implementation of room class 
 * @version 0.1
 * @date 2023-04-13
 * 
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <map>
#include "Room.h"

using namespace std;

Room::Room(string name)
{
    this->name = name;
    hasPrincess = false;
    hasMonster = false;
}
void Room::setPrincess(bool value)
{
    hasPrincess = value;
}
void Room::setMonster(bool value)
{
    hasMonster = value;
}
/**
 * @brief Add action of a room that player can do 
 * 
 * @param action 
 * @param room 
 */
void Room::addAction(string action, Room *room)
{
    actions.push_back(action);
    exits[action] = room;
}
bool Room::hasAction(string action) const
{
    for (string a : actions)
    {
        if (a == action)
        {
            return true;
        }
    }
    return false;
}
bool Room::hasExit(string direction) const
{
    return exits.find(direction) != exits.end();
}
Room* Room::getExit(string direction) const
{
    return exits.at(direction);
}
string Room::getName() const
{
    return name;
}

bool Room::princess() const
{
    return hasPrincess;
}

bool Room::monster() const
{
    return hasMonster;
}

void Room::printInfo() const
{
    cout << "There are " << exits.size() << " exits: ";
    for (auto &[direction, room] : exits)
    {
        cout << direction << ", ";
    }
    cout << endl;
}