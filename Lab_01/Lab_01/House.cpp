#define _CRT_SECURE_NO_WARNINGS
#include <D:\4 semester\Object-oriented programming\Labs\Lab_01\Lab_01\House.h>
#include <iostream>
using namespace std;

House::House() : _floor(0), _rooms(0), _area(0)
{
	_address = new char[1]; _address[0] = '\0';
}

House::House(const char* address, short floor, unsigned short rooms, unsigned int area):
	_address(0), _floor(floor), _rooms(rooms), _area(area)
{
	SetAddress(address);
}

House::~House()
{
	delete[] _address;
}

void House::SetAddress(const char* address)
{
	delete[] _address;
	_address = new char[strlen(address) + 1];
	strcpy(_address, address);
}

void House::SetFloor(short floor)
{// иногда встречаются отрицательные этажи
	_floor = floor;
}

void House::SetRooms(unsigned short rooms)
{
	_rooms = rooms;
}

void House::SetArea(unsigned int area)
{
	_area = area;
}