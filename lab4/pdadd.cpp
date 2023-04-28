#include"diary.h"
#include<iostream>

using namespace std;

int main()
{

    cout << "WELCOME TO INPUT YOUR DIARY! PLZ NOTE:\n";
    cout << "Date format: xxxxxxxx(eg:20190205)\n";
    cout << "Input '.' in a single line to stop input\n";
    Diary d;
    d.Read();
    d.add();
    d.Save();
}