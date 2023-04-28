#include <iostream>
#include "diary.h"
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    Diary d;
    d.Read();
    if(argc == 1)
    {
        d.list();
    }
    else
    {
        int y_s, m_s, d_s;
        int y_e, m_e, d_e;

        string start(argv[1]);
        string end(argv[2]);
        d.list(stoi(start.substr(0,4)), stoi(start.substr(4,2)), stoi(start.substr(6,2)),
        stoi(end.substr(0,4)), stoi(end.substr(4,2)), stoi(end.substr(6,2)));
    }
}