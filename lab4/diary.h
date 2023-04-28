#pragma once
#include<vector>
#include<string>
#include<map>
#include"entity.h"

using namespace std;

class Diary
{
    private:
        map<string,Entity> content;
    
    public:
        void Read(string name = "data.txt");
        /**
         * @brief Read diary from file 
         * 
         * @param name file name. @Defalut = "data.txt"
         */
        void Save(string name = "data.txt");

        /**
         * @brief Add an entity to diary 
         * 
         */
        void add();

        void list();

        void list(int year_s, int month_s, int day_s, int year_e, int month_e, int day_e);

        void show();

        int remove(string date);

};