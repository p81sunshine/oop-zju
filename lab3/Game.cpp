/**
 * @file Game.cpp
 * @author Liu Jiaxing (lsnfzj@gmail.com)
 * @brief Implementation of Game class 
 * Main function is Here!
 * @version 0.1
 * @date 2023-04-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <map>
#include <fstream>
#include <sstream>
#include "Room.h"
#include "Game.h"
using namespace std;

void Game::play()
{
    initMap();
    Room *currentRoom = &rooms[0];
    prologue();

    /**
     * @brief Infinite loop, unless Save the Princess successfully or 
     * meet monster
     * 
     */
    while (true)
    {
        if (isFindPrincess && currentRoom->getName() == "Lobby")
        {
            cout << "You win!" << endl;
            break;
        }
        cout << "Welcome to the  " << currentRoom->getName() << "." << endl;
        if (currentRoom->princess())
        {
            dialogueWithPrincess();
            isFindPrincess = true;
        }
        else if (currentRoom->monster())
        {
            dialogueWithMonster();
            break;
        }

        currentRoom->printInfo();

        string move, action;
        while (true)
        {
            cout << "Enter your command:" << endl;
            cin >> move >> action;
            if (move == "go" && currentRoom->hasAction(action))
            {
                break;
            }
            cout << "Invalid action. Please try again." << endl;
        }

        currentRoom = currentRoom->getExit(action);
    }
}
void Game::initMap()
{

    ifstream file("./map.txt");
    if (!file)
    {
        cerr << "Ooops, Load Map Error!" << endl;
        exit(-100);
    }

    string line;
    getline(file, line);

    stringstream ss(line);
    ss >> total;

    rooms = new Room[total];

    int i = 0;
    while (i < total)
    {
        getline(file, line);
        rooms[i] = Room(line);
        i++;
    }

    while (getline(file, line))
    {
        int from, to;
        string direction;
        stringstream ss(line);
        ss >> from >> direction >> to;
        rooms[from].addAction(direction, &rooms[to]);
    }

    /**
     * @brief Set the princess and monster randomly 
     * 
     */
    int princessIndex = randomRoomIndex();
    int monsterIndex = randomRoomIndex();
    while (princessIndex == monsterIndex)
    {
        monsterIndex = randomRoomIndex();
    }
    rooms[princessIndex].setPrincess(true);
    rooms[monsterIndex].setMonster(true);
}

int Game::randomRoomIndex()
{
    srand(time(nullptr));
    return rand() % total + 1;
}

Game::Game()
{
    isFindPrincess = false;
}

Game::~Game()
{
    delete[] rooms;
}
void Game::prologue()
{
    cout << "--------------------------------------------------------------------------------------------------------------------------------------"  <<endl;
    cout << "Great warriors from Zhejiang University, your princess's castle is being attacked by monsters at the moment." << endl;
    cout << "Take your sword, which has been contaminated by countless enemies, and find your princess and bring her back!" << endl;
    cout << "Beware, the monster is too powerful to overcome, and you will die if you meet him. So, it's a game of luck, hahaha. " << endl;
    cout << "But, is it not so in life? Go! No hesitate, man!" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void Game::dialogueWithMonster()
{
    cout << "--------------------------------------------------------------------------------------------------------------------------------------"  <<endl;
    cout << "Monster:How dare you! "
         << " Stupid little guy "
         << "? This is my place. Wanna fight with me?" << endl;
    cout << "Hint:Print Y or N" << endl;
    char option;
    cin >> option;
    if (option == 'Y')
    {
        cout << "You lose. And you are eaten by the monster" << endl;
        cout << "Well,"
             << ", why do you think that you can kill the monster?Are you Tony Stark? It's not the Hollywood superhero movies. The leading character never dies" << endl;
    }
    else
    {
        cout << "Monster: You slip into my house and you don't have the bravery to fight with me? Are you Di Maria? That man sucks" << endl;
        cout << "You try to escape.However you are caught and eaten by the monster" << endl;
    }
    cout << "--------------------------------------------------------------------------------------------------------------------------------------"  <<endl;
}

void Game::dialogueWithPrincess()
{
    cout << "--------------------------------------------------------------------------------------------------------------------------------------"  <<endl;
    cout << "The princess are really excited that you come to save her. She said:" << endl;
    cout << "Princess: Oh my hero! You come to save me! What's your name?" << endl;
    string n;
    cout << "You: My name is ";
    cin >> n;
    cout << "Princess: Oh " << n << ", you are so brave and strong! I fall in love with you the first time I saw you. Will you marry me if we escape?" << endl;
    cout << "Hint:Print Y or N" << endl;
    char option;
    cin >> option;
    if (option == 'Y')
    {
        cout << "You: Who can deny the love from the beautiful princess Tifa? Believe me, we can escape from here undoubtedly" << endl;
        cout << "Princess: Oh so strong and reliable," << n << " my love, you make my heart beating" << endl;
        cout << "The princess kisses you and arouse a fierce beating in your heart. However, you have to move on and take the princess to leave" << endl;
    }
    else
    {
        cout << "You: Sorry princess Tifa. I come here to save you, not marry you" << endl;
        cout << "Princess:(sad)Huh. Well, we have to leave now" << endl;
        cout << "Though the princess is unhappy, you have to leave now" << endl;
    }
    cout << "--------------------------------------------------------------------------------------------------------------------------------------"  <<endl;
}

int main()
{
    Game game1;
    game1.play();
    return 0;
}