//Caelen Knight
//CS 210
//October 15th, 2026

#include "GroceryTracker.h"
#include<string>
#include<iostream>
#include <iomanip>

using namespace std;

//Function verifies user choice is an int within range
void InputVerifyInt(int& userChoice) {
	string throwAway; //to clear invalid input

	while (cin.fail() || cin.peek() != '\n' || (userChoice <= 0 || userChoice >= 5)) {
		cin.clear();
		getline(cin, throwAway);//clears any input left over
		cout << "Please enter a valid number between 1 and 4: ";
		cin >> userChoice;
	}
}

//Runs the menu and uses input verification
int UserSelection() {
	int userChoice;


	cout << string(70, '=') << endl;
	cout << left;
	cout << '=' << string(5, ' ') << setw(63) << "Please select an option by entering a number:" << '=' << endl;
	cout << '=' << string(5, ' ') << setw(63) << "Option [1]: Select a single item's count" << '=' << endl;
	cout << '=' << string(5, ' ') << setw(63) << "Option [2]: Display all items with counts" << '=' << endl;
	cout << '=' << string(5, ' ') << setw(63) << "Option [3]: Display histogram of all item's purchase counts" << '=' << endl;
	cout << '=' << string(5, ' ') << setw(63) << "Option [4]: Exit Program" << '=' << endl;
	cout << string(70, '=') << endl;
	cout << "Enter choice: ";
	cin >> userChoice;

	InputVerifyInt(userChoice);
	cout << string(70, '=') << endl;
	return userChoice;
	
}


int main() {
	int userChoice;

	cout << string(70, '=') << endl;
	cout << '='<< string(14, ' ') << "Welcome! Please wait while the files load" << string(13, ' ') << '=' << endl;
	cout << string(70, '=') << endl;
	GroceryTracker todaysTracker;

	//Used if statement to verify the input file loaded.
	if (todaysTracker.GetIsRunning()) {
		cout << '=' << string(28, ' ') << "Files Loaded!" << string(27, ' ') << '=' << endl;
		cout << string(70, '=') << endl;

	}

	while (todaysTracker.GetIsRunning()) {

		userChoice = UserSelection();

		//switch statements run through menu options and call appropriate functions
		switch (userChoice) {
		case 1:
			todaysTracker.PrintOneItem();
			break;

		case 2:
			todaysTracker.PrintList();
			break;

		case 3:
			todaysTracker.PrintHistogram();
			break;

		case 4:
			todaysTracker.ExitProgram();
			break;

		//default case should never really run due to user input verification but included for good practice
		default:
			cout << "Error please try selecting another option." << endl;
		}
	}
	

	return 0;
}