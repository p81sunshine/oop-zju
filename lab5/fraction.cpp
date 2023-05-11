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
    return Fraction();
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

std::istream &operator>>(std::istream &is, Fraction &fraction)
{
    int n,d;
    char slash;
    is >> fraction.numerator >> slash >> fraction.denominator;
    return is;
}

std::ostream &operator<<(std::ostream &os, Fraction &fraction)
{
    os << static_cast<std::string>(fraction);
    return os;
}
