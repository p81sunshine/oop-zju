#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main()
{

    double a = 1.414;
    a = a * 1000;
    if (ceil(a) == floor(a)) cout << "H\n";
    std::cout << ceil(a) << " " << floor(a) << "\n";
}
