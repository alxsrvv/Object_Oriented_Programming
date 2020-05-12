#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <D:\4 semester\Object-oriented programming\Labs\Lab_01\Lab_01\House.h>
using namespace std;

int input(void)
{
	int num = 0;
	while (!(cin >> num) || num < 0)
	{
		cout << "Try correct number!\n";
		cin.clear();
		cin.ignore();
		fflush(stdin);
	}
	return num;
}

void main()
{
	House Appartment;

	Appartment.SetAddress("St. Zhmishenko 229");
	Appartment.SetFloor(2);
	cout << "Enter number of rooms in the appartment\n\tNotice, it is must be positive number: ";
	Appartment.SetRooms(input());
	cout << "Enter area of the appartment\n\tNotice, it is must be positive number too: ";
	Appartment.SetArea(input());

	cout << "Info:\n" << Appartment.GetAddress() << '\n'
		<< "Floor: " << Appartment.GetFloor() << '\n'
		<< "Rooms: " << Appartment.GetRooms() << '\n'
		<< "Area: " << Appartment.GetArea() << endl;

	Appartment.SetAddress("St. Groove 13");
	Appartment.SetFloor(3);
	cout << "\nEnter number of rooms in the appartment\n\tNotice, it is must be positive number: ";
	Appartment.SetRooms(input());
	cout << "Enter area of the appartment\n\tNotice, it is must be positive number too: ";
	Appartment.SetArea(input());

	cout << "\nUpdated Info:\n" << Appartment.GetAddress() << '\n'
		<< "Floor: " << Appartment.GetFloor() << '\n'
		<< "Rooms: " << Appartment.GetRooms() << '\n'
		<< "Area: " << Appartment.GetArea() << '\n' << endl;

	system("pause");
}