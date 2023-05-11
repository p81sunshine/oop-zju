#include <iostream>
#include "fraction.h"
#include <string>

int main() {
    Fraction f1(2, 3), f2(3, 4), f3, f4;
    std::cout << "f1 = " <<  f1 << " f2 = " << f2 << '\n';
    f3 = f1;
    std::cout << "f3 = f1, f3 = " << f3 << '\n';

    std::cout << "f3 = f1+-*/f2 (The following four number) \n";
    f3 = f1 + f2;
    std::cout << f3 << " = " << static_cast<double>(f3) << '\n';

    f3 = f2 - f1;
    std::cout << f3 << " = " << static_cast<double>(f3) << '\n';

    f3 = f1 * f2;
    std::cout << f3 << " = " << static_cast<double>(f3) << '\n';

    f3 = f1 / f2;
    std::cout << f3 << " = " << static_cast<double>(f3) << '\n';

    std::cout << std::to_string(f1 < f2) << "\n"; 
    std::cout << std::to_string(f1 <= f2) << "\n"; 
    std::cout << std::to_string(f1 > f2) << "\n"; 
    std::cout << std::to_string(f1 >= f2) << "\n"; 
    std::cout << std::to_string(f1 == f2) << "\n"; 
    std::cout << std::to_string(f1 != f2) << "\n"; 

    Fraction fn = Fraction::from_decimal(1.414);
    std::cout << fn << "\n";
}