/**
 * @file Game.h
 * @author Liu Jiaxing lsnfzj@gmail.com
 * @brief header file for Game class
 * @version 0.1
 * @date 2023-04-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <map>
#include "Room.h"

using namespace std;
class Game
{
private:
    Room *rooms;
    bool isFindPrincess;
    int total;

public:
    Game();
    void initMap();
    void prologue();
    void dialogueWithPrincess();
    void dialogueWithMonster();
    void play();
    int randomRoomIndex();
    ~Game();
};
