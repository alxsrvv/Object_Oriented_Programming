//#define _CRT_SECURE_NO_WARNINGS
#include "Furniture_workshop.h"
#include <string>
#include <iostream>
using namespace std;

Furniture_workshop::Furniture_workshop() : wood_type("None"), amount_of_wood(0)
{}
Furniture_workshop::Furniture_workshop(string title, unsigned short workbench, float capacity, string wood, unsigned amount) :
	Workshop(title, workbench, capacity), wood_type(wood), amount_of_wood(amount)
{}
Furniture_workshop::~Furniture_workshop()
{}
string Furniture_workshop::Get_wood() const
{
	return wood_type;
}
unsigned Furniture_workshop::Get_amount() const
{
	return amount_of_wood;
}
void Furniture_workshop::Set_wood(string new_wood)
{
	wood_type = new_wood;
}
void Furniture_workshop::Set_amount(unsigned new_amount)
{
	amount_of_wood = new_amount;
}
void Furniture_workshop::Print_furniture_workshop()
{
	Workshop::Print_workshop();
	cout << Furniture_workshop::Get_wood() << '\n'
		<< Furniture_workshop::Get_amount() << '\n' << endl;
}