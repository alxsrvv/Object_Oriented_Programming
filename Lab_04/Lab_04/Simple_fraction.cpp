#include "Simple_fraction.h"
#include <iostream>
using namespace std;

Simple_fraction::Simple_fraction(int numerator, int denominator)
{
    if (denominator == 0) // делитель равен 0
        throw std::runtime_error("zero division error");
    this->numerator = numerator;
    this->denominator = denominator;
}

Simple_fraction::~Simple_fraction() {}

int Simple_fraction::Get_num() const 
{ return this->numerator; }

int Simple_fraction::Get_denom() const 
{ return this->denominator; }

Simple_fraction Simple_fraction::Simplify() const
{ 
    int num = Get_num();
    int denom = Get_denom();
    for (int i = denom * num; i > 1; i--) 
    {
        if ((denominator % i == 0) && (num % i == 0))
        {
            denom /= i;
            num /= i;
        }
    }
    Simple_fraction tmp(num, denom);
    return tmp;
}

void Simple_fraction::Print() const
{
    cout << "\nThe fraction : \n\t" << Get_num() << " /\n\t" << Get_denom() << "\n\n";
}

Simple_fraction Simple_fraction::operator+ (const Simple_fraction& fr)
{
    Simple_fraction tmp(this->numerator * fr.denominator + this->denominator * fr.numerator, this->denominator * fr.denominator);
    return tmp; 
}

Simple_fraction Simple_fraction::operator- (const Simple_fraction& fr)
{
    Simple_fraction tmp(this->numerator * fr.denominator - this->denominator * fr.numerator, this->denominator * fr.denominator);
    return tmp;
}

Simple_fraction Simple_fraction::operator* (const Simple_fraction& fr)
{
    Simple_fraction tmp(this->numerator * fr.numerator, this->denominator * fr.denominator);
    return tmp;
}

Simple_fraction Simple_fraction::operator/ (const Simple_fraction& fr)
{
    if (fr.numerator == 0) // делитель равен 0
    {
        throw std::runtime_error("zero division error"); 
    }
    else
    {
        Simple_fraction tmp(this->numerator * fr.denominator, this->denominator * fr.numerator);
        return tmp;
    }
}