#pragma once
#include "Ñontainer.h"
#include <Windows.h>
#include <mutex>
/*
The Singleton menu class provides the 'Getinstance' method, 
which acts as an alternative constructor and allows customers 
to receive the same class instance at each call.
 */
class Menu
{
private:
    /*
    The Singlton constructor must always be hidden 
    to prevent the creation of an object through the new operator.
    */
    Menu() {}
    static Menu* Menu_;
    Ñontainer all_workshops;
    int choice;
public:
    //Menus should not be assignable.
    Menu(Menu& other) = delete;
    void operator=(const Menu&) = delete;
    /*
    It’s a static method that controls access to a Singleton.
    At the first launch, it creates a single instance and places 
    it in a static field. In subsequent runs, it returns an object
    stored in a static field to the client.
    */
    static Menu* GetInstance();

    void Start(); // menu function that gives a choice to user (UI)

    void Create_sewing_workshop(Ñontainer* Data);
    void Create_furniture_workshop(Ñontainer* Data);
    void Show() const; // show all elements
    void Delete(); // delete one element by the title
    void Save() const; // save all elements to file
    void Load(); // save all elements from file
    void Sort(); // sort elements by titles
    void Capacity() const; // count capacity of all workshops by type
    void Full_delete(); // delete all elements
    void Exit(); // exit from the program
};