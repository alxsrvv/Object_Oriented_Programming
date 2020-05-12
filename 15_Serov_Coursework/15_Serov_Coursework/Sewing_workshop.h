#pragma once
#include "Workshop.h"
/*
	Derived class with basic workshop info and sewing info
*/
class Sewing_workshop : public Workshop
{
private:
	string fabric_type;
	unsigned rolls_of_fabric;
public:
	Sewing_workshop();
	Sewing_workshop(string title, unsigned short workbench, int capacity, string fabric, unsigned rolls);
	~Sewing_workshop();

	string Get_fabric() const;
	unsigned Get_rolls() const;

	void Set_fabric(string new_fabric);
	void Set_rolls(unsigned new_rolls);

	friend istream& operator >> (istream& is, Sewing_workshop& sew_is); // overloaded input operator
	friend ostream& operator << (ostream& os, Sewing_workshop& sew_os); // overloaded output operator

	void Print_workshop();
};