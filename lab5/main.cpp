#include <iostream>
#include "fraction.h"
#include <string>

int main() {
    Fraction f1(2, 3), f2(3, 4);
    std::cout << "f1 = " <<  f1 << " f2 = " << f2 << '\n';
    Fraction f3 = f1;
    std::cout << "f3 = f1, f3 = " << f3 << '\n';
    Fraction f4;
    std::cin >> f4;
    std::cout << "Input result: " << f4 << "\n";

    std::cout << "\n\n\nf3 = f1+-*/f2 (The following four number) \n";
    f3 = f1 + f2;
    std::cout << f3 << " = " << static_cast<double>(f3) << '\n';

    f3 = f1 - f2;
    std::cout << f3 << " = " << static_cast<double>(f3) << '\n';

    f3 = f1 * f2;
    std::cout << f3 << " = " << static_cast<double>(f3) << '\n';

    f3 = f1 / f2;
    std::cout << f3 << " = " << static_cast<double>(f3) << '\n';

    std::cout << "\n\n\nAll possible comparsion between f1 and f2: < , <=, >, >=, ==, !=\n";
    std::cout << std::to_string(f1 < f2) << "\n"; 
    std::cout << std::to_string(f1 <= f2) << "\n"; 
    std::cout << std::to_string(f1 > f2) << "\n"; 
    std::cout << std::to_string(f1 >= f2) << "\n"; 
    std::cout << std::to_string(f1 == f2) << "\n"; 
    std::cout << std::to_string(f1 != f2) << "\n"; 

    std::cout << "\n\n\n 从1.414向Fraction转换\n";
    Fraction fn = Fraction::from_decimal(1.414);
    std::cout << fn << "\n";
}