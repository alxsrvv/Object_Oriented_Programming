#include "Simple_fraction.h"
#include <iostream>
using namespace std;

void main() {
    cout << "-------------- First and second fractions --------------";
    Simple_fraction fr1(25, 5);
    fr1.Print();
    Simple_fraction fr2(4, 3);
    fr2.Print();
    cout << "------------- Sum, sub, mult, div fractions ------------";
    Simple_fraction sum = fr1 + fr2;
    sum.Print();
    Simple_fraction sub = fr1 - fr2;
    sub.Print();
    Simple_fraction mult = fr1 * fr2;
    mult.Print();
    Simple_fraction div = fr1 / fr2;
    div.Print();
    cout << "---------------- Simplify first fraction  ---------------";
    Simple_fraction simp_fr1 = fr1.Simplify();
    simp_fr1.Print();

    system("pause");
}