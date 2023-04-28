#include<iostream>
#include<string>
#include"Diary.h"

int main()
{
    std::cout << "Welecom to remove a entry from diary\n";
    std::cout << "Date format: xxxxxxxx(eg:20200101)\n";
    std::string s;
    std::cin >> s;

    Diary d;
    d.Read();
    int t = d.remove(s);
    d.Save();

    return t;
}