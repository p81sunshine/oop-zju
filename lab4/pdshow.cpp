#include<iostream>
#include "diary.h"

using namespace std;

int main()
{
    cout << "Welcome to show content of a diary. PLZ input date:\n";
    cout << "Format: xxxxxxxx (eg:20190204) \n";

    Diary d;
    d.Read();
    d.show();
    d.Save();
    
}