#include "Building.h"
#include "House.h"
#include "Depository.h"
#include <iostream>
using namespace std;

/*
Building* a_ptr;
Depository b = Depository("EGRa", 2, "b", "GGRW");
a_ptr = &b;
a_ptr->Print();
*/
void show(Building** Buildings, unsigned size)
{
	cout << "All buildings:\n";
	for (unsigned i = 0; i < size; i++)
		Buildings[i]->Print();
}
void del(Building** Buildings, unsigned size)
{
	for (unsigned i = 0; i < size; i++)
		delete Buildings[i];
	delete[] Buildings;
}
Building** init(unsigned b_num)
{
	Building** Buildings = new Building * [b_num];
	for (unsigned i = 0; i < b_num; i++)
	{

		if (i % 2 == 0)
			Buildings[i] = new House("st. Pushkina 12", 123, "House", 456);
		else
			Buildings[i] = new Depository("st. Shevchenko 21", 321, "Deposity", "Standart");
	}
	return Buildings;
}

int main()
{
	unsigned size(7);

	Building** Buildings = init(size);
	show(Buildings, size);
	del(Buildings, size);

	return 0;
}