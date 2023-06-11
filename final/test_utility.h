#include <iostream>
#include <string>
using namespace std;

static int test = 0;
template <typename T>
void expect_eqal(T t1, T t2, string name) {
    if (t1 == t2) {
        std::cout << "[" << test << "]:  " << name << " test pass\n";
    } else {
        std::cout << name << "test fail\n";
    }
    test++;
}