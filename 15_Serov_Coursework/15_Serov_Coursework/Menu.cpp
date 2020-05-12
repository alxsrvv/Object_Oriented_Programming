#include "Menu.h"

Menu* Menu::Menu_ = nullptr;

//This is a safer way to create an instance. instance = new Menu is
//dangeruous in case two instance threads wants to access at the same time
Menu* Menu::GetInstance()
{
	if (Menu_ == nullptr) {
		Menu_ = new Menu();
	}
	return Menu_;
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
	do
	{
		system("cls");
		cout << "|--------------------------------------|\n"
			<< ">--------------   MENU   --------------<\n"
			<< "|--------------------------------------|\n"
			<< "[1] Create sewing workshop object\n"
			<< "[2] Create furniture workshop object\n"
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
	Sewing_workshop* data = new Sewing_workshop();
	cout << "\nEnter info about sewing workshop (separated by SPACE or ENTER)\n"
		<< "Title   Workbanches   Capacity   Fabric   Rolls\n\n>";
	cin >> *data;
	Data->Push(data);
	cout << "\nNew sewing workshop added!\n\n";
	system("pause");
	system("cls");
}

void Menu::Create_furniture_workshop(Сontainer* Data)
{
	Furniture_workshop* data = new Furniture_workshop();
	cout << "\nEnter info about furniture workshop (separated by SPACE or ENTER)\n"
		<< "Title   Workbanches   Capacity   Wood   Amount\n\n>";
	cin >> *data;
	Data->Push(data);
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
			cout << "\nWorkshop '" << title_to_delete << "' has been deleted!\n";
		else
			cout << "\nError: Workshop '" << title_to_delete << "' not found!\n";
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
		cout << "\nContainer clear. There are no workshops to save some!\n";
		system("pause");
		system("cls");
	}
}

void Menu::Load()
{
	all_workshops.Load();
	cout << "\nWorkshops loaded from file 'Workshops_info.dat'!\n\n";
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
		cout << "\nContainer clear. There are no workshops to sort some!\n";
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
		cout << "\nContainer clear. There are no workshops to count capacity!\n";
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
	exit(0);
}
