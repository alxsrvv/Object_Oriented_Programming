#include "Menu.h"

Menu* Menu::single_menu = nullptr; // global variable puts in Singleton class 'Menu' in static field start value

Menu* Menu::GetInstance() //This is a safe way to create an instance
{
	if (single_menu == nullptr) {
		single_menu = new Menu();
	}
	return single_menu;
}

void Menu::Start()
{
	cout << "|--------------------------------------|\n\n" // start window
		<< "This program works with worshops data\n"
		<< "and can help you to manage your info\n"
		<< "about different workshops: Sewing or\n"
		<< "Furniture. In any time you can save\n"
		<< "or load data to file and use it for\n"
		<< "your purposes.\tLet's start!\n\n"
		<< "|--------------------------------------|\n\n";
	system("pause");
	do // menu loop
	{
		system("cls");
		cout << "|--------------------------------------|\n"
			<< ">--------------   MENU   --------------<\n"
			<< "|--------------------------------------|\n"
			<< "[1] Create Sewing workshop object\n"
			<< "[2] Create Furniture workshop object\n"
			<< "[3] Show workshops\n"
			<< "[4] Remove the workshop\n"
			<< "[5] Save to the file\n"
			<< "[6] Load from the file\n"
			<< "[7] Sort objects\n"
			<< "[8] Capacity of all workshops by type\n"
			<< "[9] Remove all workshops\n"
			<< "[0] Leave the program\n"
			<< "|--------------------------------------|\n"
			<< "\n> ";

		while (!(cin >> choice) || choice < 0 || choice > 9)
		{
			cin.clear();
			cin.ignore();
			fflush(stdin);
			cout << "Try number from 0 to 9!\n> ";
		}

		switch (choice)
		{
		case 1:
		{
			Create_sewing_workshop(&all_workshops);
			break;
		}
		case 2:
		{
			Create_furniture_workshop(&all_workshops);
			break;
		}
		case 3:
		{
			Show();
			break;
		}
		case 4:
		{
			Delete();
			break;
		}
		case 5:
		{
			Save();
			break;
		}
		case 6:
		{
			Load();
			break;
		}
		case 7:
		{
			Sort();
			break;
		}
		case 8:
		{
			Capacity();
			break;
		}
		case 9:
		{
			Full_delete();
			break;
		}
		case 0:
		{

			Exit();
			break;
		}
		}
	} while (true);
}

void Menu::Create_sewing_workshop(Сontainer* Data)
{
	Sewing_workshop* new_sewing_workshop = new Sewing_workshop();
	cout << "\nEnter info about sewing workshop (separated by SPACE or ENTER)\n"
		<< "Title   Workbanches   Capacity   Fabric   Rolls\n\n>";
	cin >> *new_sewing_workshop;
	Data->Push(new_sewing_workshop);
	cout << "\nNew sewing workshop added!\n\n";
	system("pause");
	system("cls");
}

void Menu::Create_furniture_workshop(Сontainer* Data)
{
	Furniture_workshop* new_furniture_workshop = new Furniture_workshop();
	cout << "\nEnter info about furniture workshop (separated by SPACE or ENTER)\n"
		<< "Title   Workbanches   Capacity   Wood   Amount\n\n>";
	cin >> *new_furniture_workshop;
	Data->Push(new_furniture_workshop);
	cout << "\nNew furniture workshop added!\n\n";
	system("pause");
	system("cls");
}


void Menu::Show() const
{
	if (all_workshops.Print()) // print workshops and pause if container have at least one element
	{
		system("pause");
		system("cls");
		
	}
	else
	{
		cout << "\nContainer clear. There are no workshops to show!\n\n";
		system("pause");
		system("cls");
	}
	
}

void Menu::Delete()
{
	if (all_workshops.Count_elements() == 0) // delete works only if container is not empty
	{
		cout << "\nWhen workshops container is clear there is nothing to delete!\n\n";
		system("pause");
		system("cls");
	}
	else
	{
		all_workshops.Print(); // show elements before choose for beter UX

		string title_to_delete;
		cout << "\nEnter title of workshop to delete it\n\n>";
		cin >> title_to_delete;

		bool pop_flag = all_workshops.Delete_element(title_to_delete); // deleting element return bool

		if (pop_flag)
			cout << "\nWorkshop '" << title_to_delete << "' has been deleted!\n\n";
		else
			cout << "\nError: Workshop '" << title_to_delete << "' not found!\n\n";
		system("pause");
		system("cls");
	}
}

void Menu::Save() const
{
	if (all_workshops.Save()) // save and pause if container have at least one element
	{
		system("pause");
		system("cls");
	}
	else
	{
		cout << "\nContainer clear. There are no workshops to save some!\n\n";
		system("pause");
		system("cls");
	}
}

void Menu::Load()
{
	all_workshops.Load();
	cout << "\nWorkshops loaded from file 'Workshops_info.txt'!\n\n";
	system("pause");
	system("cls");
}

void Menu::Sort()
{
	if (all_workshops.Sort_elements_by_title()) // sort and pause if container have at least one element
	{
		cout << "\nAll workshops sorted by the title!\n\n";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "\nContainer clear. There are no workshops to sort some!\n\n";
		system("pause");
		system("cls");
	}
}

void Menu::Capacity() const
{
	if (all_workshops.Count_capacity()) // count capacity and pause if container have at least one element
	{
		system("pause");
		system("cls");
	}
	else
	{	
		cout << "\nContainer clear. There are no workshops to count capacity!\n\n";
		system("pause");
		system("cls");
	}
}

void Menu::Full_delete() // delete all elements and pause if container have at least one element
{
	if (all_workshops.Delete_all())
	{
		cout << "\nNow workshops container is clear!\n\n";
		system("pause");
		system("cls");
	}
	else 
	{
		cout << "\nWorkshops container is clear already!\n\n";
		system("pause");
		system("cls");
	}
}

void Menu::Exit()
{
	all_workshops.Delete_all();
	cout << "\nGood luck!\n\n";
	exit(0);
}
