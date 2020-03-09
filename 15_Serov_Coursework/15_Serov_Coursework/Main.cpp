#include "Sewing_workshop.h"
#include "Furniture_workshop.h"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	Sewing_workshop newclass1("cherevechki", 123, 987, "wool", 124);
	unsigned short i;
	char s[10];

	do
	{
		system("cls");
		cout << "<---------------- MENU ---------------->\n"
			<< "[1] Create sewing workshop object\n"
			<< "[2] Create furniture workshop object\n"
			<< "[3] Show the workshop\n"
			<< "[4] Remove the workshop\n"
			<< "[5] Save to the file\n"
			<< "[6] Load from the file\n"
			<< "[7] Sort objects\n"
			<< "[8] Do request\n"
			<< "[9] Leave the program\n\n>";
		cin.getline(s, 10);
		i = atoi(s);

		switch (i)
		{
		case 1:
		{
			system("cls");
			//Sewing_workshop newclass1;
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			Furniture_workshop newclass2;
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			newclass1.Print_sewing_workshop();
			//Print_furniture_workshop();
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			//~Sewing_workshop();
			//~Furniture_workshop()
			system("pause");
			break;
		}
		/*
		case 5-9:
		{
			in developing...
		}
		*/
		default:
		{
			if (i < 1 || i > 9)
			{
				cout << "Sorry, You choose wrong number\nTry again!" << endl;
				system("pause");
			}
		}
			break;
		}
	}
	while (i != 10);

	system ("pause");
}