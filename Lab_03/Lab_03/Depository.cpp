#define _CRT_SECURE_NO_WARNINGS
#include "Depository.h"
#include <iostream>
using namespace std;

Depository::Depository(const char* adrs, unsigned area, const char* use, const char* cond) :
	Building(adrs, area, use)
{	
	m_condition = new char[strlen(cond) + 1];
	strcpy(m_condition, cond);
}

const char* Depository::Get_condition()
{
	return m_condition;
}
void Depository::Set_condition(const char* cond)
{
	m_condition = new char[strlen(cond) + 1];
	strcpy(m_condition, cond);
}

void Depository::Print()
{
	Building::Print();
	cout << " \tCondition : " << Depository::Get_condition() << endl;
}