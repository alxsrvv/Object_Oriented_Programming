#pragma once
class Simple_fraction
{
private:
    int numerator;
    int denominator;
public:
    Simple_fraction(int numerator, int denominator);
    ~Simple_fraction();

    int Get_num() const;
    int Get_denom() const;
    Simple_fraction Simplify() const;
    void Print() const;

    Simple_fraction operator+ (const Simple_fraction& fr);
    Simple_fraction operator- (const Simple_fraction& fr);
    Simple_fraction operator* (const Simple_fraction& fr);
    Simple_fraction operator/ (const Simple_fraction& fr);
};