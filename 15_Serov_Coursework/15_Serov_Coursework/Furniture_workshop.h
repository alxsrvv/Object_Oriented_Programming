#pragma once
#include "Workshop.h"
/*
	Derived class with basic workshop info and furniture info
*/
class Furniture_workshop : public Workshop
{
private:
	string wood_type;
	unsigned amount_of_wood;
public:
	Furniture_workshop();
	Furniture_workshop(string title, unsigned short workbench, int capacity, string wood, unsigned amount);
	~Furniture_workshop();

	string Get_wood() const;
	unsigned Get_amount() const;

	void Set_wood(string new_wood);
	void Set_amount(unsigned new_amount);

	friend istream& operator >> (istream& is, Furniture_workshop& fur_is); // overloaded input operator
	friend ostream& operator << (ostream& os, Furniture_workshop& fur_os); // overloaded output operator

	void Print_workshop();
};