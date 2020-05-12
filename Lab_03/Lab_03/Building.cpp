#define _CRT_SECURE_NO_WARNINGS
#include "Building.h"
#include <iostream>
using namespace std;

Building::Building(const char* adrs, unsigned area, const char* use) :
	m_area(area)
{
	m_address = new char[strlen(adrs) + 1];
	strcpy(m_address, adrs);

	m_use = new char[strlen(use) + 1];
	strcpy(m_use, use);
}
Building::~Building()
{
	delete[]m_address;
	delete[]m_use;
}

const char* Building::Get_address()
{	return m_address;	}
unsigned Building::Get_area()
{	return m_area;	}
const char* Building::Get_use()
{	return m_use;	}

void Building::Set_address(const char* adrs)
{
	m_address = new char[strlen(adrs) + 1];
	strcpy(m_address, adrs);
}
void Building::Set_area(unsigned area)
{
	m_area = area;
}
void Building::Set_use(const char* use)
{
	m_use = new char[strlen(use) + 1];
	strcpy(m_use, use);
}

void Building::Print()
{
	cout << "\tBuilding " << Building::Get_address()
		<< "\tArea : " << Building::Get_area()
		<< "\tUse : " << Building::Get_use();
}