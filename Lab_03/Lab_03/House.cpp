#define _CRT_SECURE_NO_WARNINGS
#include "House.h"
#include <iostream>
using namespace std;

House::House(const char* adrs, unsigned area, const char* use, unsigned short aprt) :
	Building(adrs, area, use), m_apartments(aprt)
{	}

unsigned short House::Get_apartments()
{
	return m_apartments;
}
void House::Set_apartments(unsigned short aprt)
{
	m_apartments = aprt;
}

void House::Print()
{
	Building::Print();
	cout << " \tApartments : " << House::Get_apartments() << endl;
}