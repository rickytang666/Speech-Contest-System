/*

	Speech Contest Management System
	
	Author: Ricky Tang

	Date Started: June 27th, 2024

	Date Completed: June 29th, 2024

*/


// Necessary Packages

#include<iostream>
#include<string>
#include<ctime>
#include "speechManager.h"

using namespace std;



int main()
{

	// Add random seed

	srand((unsigned int)time(NULL));



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

		cout << endl; // separation

		if (choice == 1) // Start contest
		{
			sm.start_speech();
		}
		else if (choice == 2) // See past contest records
		{

			sm.show_records();
		}
		else if (choice == 3) // Clear contest records
		{

			sm.clear_records();
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
