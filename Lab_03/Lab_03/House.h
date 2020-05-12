#pragma once
#include "Building.h"

class House : public Building
{
private:
	unsigned short m_apartments;
public:
	House(const char* adrs, unsigned area, const char* use, unsigned short aprt);

	unsigned short Get_apartments();
	void Set_apartments(unsigned short aprt);

	void Print();
};