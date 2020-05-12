#pragma once
#include "Building.h"

class Depository : public Building
{
private:
	char* m_condition;
public:
	Depository(const char* adrs, unsigned area, const char* use, const char* cond);

	const char* Get_condition();
	void Set_condition(const char* cond);

	void Print();
};