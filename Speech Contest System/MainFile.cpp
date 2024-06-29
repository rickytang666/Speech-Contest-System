/*

	Speech Contest Management System
	
	Author: Ricky Tang

	Date Started: June 27th, 2024

	Date Completed: TBD

*/


// Necessary Packages

#include<iostream>
#include<string>

using namespace std;

#include "speechManager.h"



int main()
{
	// Create Manager class object

	SpeechManager sm;

	
	

	
	// Provide options for users

	int choice = 0; // For storing user's input

	while (true)
	{
		sm.show_menu();

		cout << endl; // separation

		cout << "Please enter your choice:  ";

		cin >> choice;

		if (choice == 1) // Start contest
		{
			sm.start_speech();
		}
		else if (choice == 2) // See past contest records
		{
			
		}
		else if (choice == 3) // Clear contest records
		{

		}
		else if (choice == 0) // Quit application
		{
			sm.exit_system();
		}
		else // Invalid Input
		{
			system("cls");
		}

	}
	
	system("pause");
	return 0;
}