#include "fraction.h"
#include <iostream>
#include <string>
#include <cmath>


Fraction::operator double() const
{
    return static_cast<double>(numerator) / denominator;
}

Fraction::operator std::string() const
{
    std::string s ="\\";
    return std::to_string(numerator) + s + std::to_string(denominator);
}

Fraction Fraction::from_decimal(double x)
{
    int sign = x < 0 ? -1 : 1;

    x *= sign;
    int power = 1;
    int count = 1;
    while (floor(x * power) != ceil(x * power) && count <= 10)
    {
        power *= 10;
        count++;
    }

    return Fraction(x * power, power);
    
}

bool Fraction::operator<(const Fraction &rhs) const
{
    return static_cast<double>(*this) < static_cast<double>(rhs);
}

bool Fraction::operator>(const Fraction &rhs) const
{
    return rhs < *this;
}

bool Fraction::operator<=(const Fraction &rhs) const
{
    return !(rhs < *this);
}

bool Fraction::operator>=(const Fraction &rhs) const
{
    return !(*this < rhs);
}

bool Fraction::operator==(const Fraction &rhs) const
{
    return numerator == rhs.numerator && denominator == rhs.denominator;
}

bool Fraction::operator!=(const Fraction &rhs) const
{
    return !(*this == rhs);
}

Fraction Fraction::operator+(const Fraction &rhs) const
{
    return Fraction(numerator * rhs.denominator + rhs.numerator * denominator, denominator * rhs.denominator);
}

Fraction Fraction::operator-(const Fraction &rhs) const
{
    return Fraction(numerator * rhs.denominator - rhs.numerator * denominator, denominator * rhs.denominator);
}

Fraction Fraction::operator*(const Fraction &rhs) const
{
    return Fraction(numerator *  rhs.numerator , denominator * rhs.denominator);
}

Fraction Fraction::operator/(const Fraction &rhs) const
{
    return Fraction(numerator * rhs.denominator, denominator * rhs.numerator);
}

Fraction& Fraction::operator=(const Fraction &rhs) 
{
    if (this != &rhs)
    {
        this->denominator = rhs.denominator;
        this->numerator = rhs.numerator;
    }

    return *this;
}

std::istream &operator>>(std::istream &is, Fraction &fraction)
{
    char slash;
    is >> fraction.numerator >> slash >> fraction.denominator;
    return is;
}

std::ostream &operator<<(std::ostream &os, Fraction &fraction)
{
    os << static_cast<std::string>(fraction);
    return os;
}
