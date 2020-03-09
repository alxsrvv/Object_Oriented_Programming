//#define _CRT_SECURE_NO_WARNINGS
#include "Sewing_workshop.h"
#include <string>
#include <iostream>
using namespace std;

Sewing_workshop::Sewing_workshop() : fabric_type("None"), rolls_of_fabric(0)
{}
Sewing_workshop::Sewing_workshop(string title, unsigned short workbench, float capacity, string fabric, unsigned rolls) :
	Workshop(title, workbench, capacity), fabric_type(fabric), rolls_of_fabric(rolls)
{}
Sewing_workshop::~Sewing_workshop()
{}
string Sewing_workshop::Get_fabric() const
{
	return fabric_type;
}
unsigned Sewing_workshop::Get_rolls() const
{
	return rolls_of_fabric;
}
void Sewing_workshop::Set_fabric(string new_fabric)
{
	fabric_type = new_fabric;
}
void Sewing_workshop::Set_rolls(unsigned new_rolls)
{
	rolls_of_fabric = new_rolls;
}
void Sewing_workshop::Print_sewing_workshop()
{
	Workshop::Print_workshop();
	cout << Sewing_workshop::Get_fabric() << '\n'
		<< Sewing_workshop::Get_rolls() << '\n' << endl;
}