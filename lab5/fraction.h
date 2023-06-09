#include<string>
#include<iostream>
class Fraction
{
public:
    int denominator;
    int numerator;

public:
    Fraction() = default;
    Fraction(int n, int d) : denominator(d), numerator(n){}
    Fraction(const Fraction &f) : denominator(f.denominator), numerator(f.numerator) {}

    bool operator<(const Fraction &rhs) const;
    bool operator>(const Fraction &rhs) const;
    bool operator<=(const Fraction &rhs) const;
    bool operator>=(const Fraction &rhs) const;
    bool operator==(const Fraction &rhs) const;
    bool operator!=(const Fraction &rhs) const;
    

    Fraction operator+(const Fraction &rhs) const;
    Fraction operator-(const Fraction &rhs) const;
    Fraction operator*(const Fraction &rhs) const;
    Fraction operator/(const Fraction &rhs) const;
    Fraction& operator=(const Fraction &rhs) ;

    operator double() const;
    operator std::string() const; 

    static Fraction from_decimal(double x);
    friend std::istream& operator>>(std::istream& is, Fraction& fraction);
    friend std::ostream& operator<<(std::ostream& os, Fraction& fraction);

};