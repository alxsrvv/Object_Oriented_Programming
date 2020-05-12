//#define _CRT_SECURE_NO_WARNINGS
#pragma once
class House
{
	char* _address;
	short _floor;
	unsigned short _rooms;
	unsigned int _area;

public:
	House();
	House(const char* address, short floor, unsigned short rooms, unsigned area);
	~House();

	const char* GetAddress() const { return _address; }
	short GetFloor() const { return _floor; }
	unsigned short GetRooms() const { return _rooms; }
	unsigned GetArea() const { return _area; }

	void SetAddress(const char* address);
	void SetFloor(short floor);
	void SetRooms(unsigned short rooms);
	void SetArea(unsigned area);

	void Print();
};