#define _CRT_SECURE_NO_WARNINGS
#include "Appartment.h"
#include <iostream>
using namespace std;

Appartment::Appartment() : m_address(0), m_floor(0), m_rooms(0), m_area(0)
{}

Appartment::Appartment(const char* address, short floor, unsigned short rooms, unsigned area) :
	m_address(0), m_floor(floor), m_rooms(rooms), m_area(area)
{
	SetAddress(address);
}

Appartment::~Appartment()
{
	delete[] m_address;
}

void Appartment::SetAddress(const char* address)
{short _floor;
	unsigned short _rooms;
	unsigned int _area;
	delete[] m_address;
	m_address = new char[strlen(address) + 1];
	strcpy(m_address, address);
}

void Appartment::SetFloor(short floor)
{
	m_floor = floor;
}

void Appartment::SetRooms(unsigned short rooms)
{
	m_rooms = rooms;
}

void Appartment::SetArea(unsigned area)
{
	m_area = area;
}

void Appartment::Print()
{
	cout << "\nInfo:\n" << Appartment::GetAddress() << '\n'
		<< "Floor: " << Appartment::GetFloor() << '\n'
		<< "Rooms: " << Appartment::GetRooms() << '\n'
		<< "Area: " << Appartment::GetArea() << '\n' << endl;
}