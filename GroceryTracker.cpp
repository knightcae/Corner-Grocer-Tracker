//Caelen Knight
//CS 210
//October 15th, 2026

#include "GroceryTracker.h"
#include<iostream>
#include<string>
#include<fstream>
#include <iomanip>


using namespace std;

GroceryTracker::GroceryTracker(){
	isRunning = true; //initalizes Grocery tracker object with isRunning Bool to True
	CreateMap(); //reads input file to create the objects map of produce items

	//if statement to verify CreateMap ran successfully before making a copy
	if (isRunning) {
		CreateOutputFile(); //backups a copy of the map to .dat file
	}
}; 

//Prompts user for item and tells user how many times that item was purhcased
void GroceryTracker::PrintOneItem() {
	string userInput;
	cout << "Please enter the item you are looking for: " << endl;
	cin >> userInput;

	//if-else to verify if item was purchased and/or is valid
	if (currentItems.count(userInput) == 1) {
		cout << userInput << " purchases: " << currentItems.at(userInput) << endl;
	}
	else {
		cout << "Item wasn't purchased today or is invalid" << endl;
	}
	
}

//Prints the entire list of items and how much they were purchased
void GroceryTracker::PrintList() {
	for (auto const& item : currentItems) {
		cout << setw(15) << item.first << ": " << item.second << endl;
	}
}

//Prints the entire list of items and displays a histogram for frequency of purchase
void GroceryTracker::PrintHistogram() {
	for (auto const& item : currentItems) {
		cout << setw(15) << item.first << " ";
		cout << string(item.second, '@') << endl;
	}
}

//Sets isRunning to false didnt name it setter as it will always set to false
void GroceryTracker::ExitProgram() {
	isRunning = false;
}

//returns isRunning for main while loop to know when to exit program
bool GroceryTracker::GetIsRunning() const {
	return isRunning;
}

//Reads text file, counts produceitems, and saves items in a map with count
void GroceryTracker::CreateMap() {
	ifstream inFS;
	string inputItem;
	
	inFS.open("CS210_Project_Three_Input_File.txt");

	//verifies file opened and if it doesnt it informs user and then program exits so user can verify file
	if (inFS.is_open()) {
		//reads the entire file 
		while (inFS >> inputItem) {

			//creates a map element if one does not exits or increments count of map element
			if (currentItems.count(inputItem) == 0) {
				currentItems.emplace(inputItem, 1);
			}
			else {
				currentItems.at(inputItem) += 1;
			}
		}

		inFS.close(); //closes file
	}
	else {

		cout << "File not found. Please verify file CS210_Project_Three_Input_File.txt" << endl;
		cout << " is in the appropriate folder.";
		cout << endl;
		ExitProgram();
		return;

	}
}

//Creates the .dat file with daily item counts
void GroceryTracker::CreateOutputFile() {
	ofstream outFS;

	outFS.open("frequency.dat");


	//Verifies file opens and writes daily items to output file. If file doesnt opens informs user and exits program
	if (outFS.is_open()) {
		for (auto const& item : currentItems) {
			outFS << item.first << " " << item.second << endl;
		}

		outFS.close();
	}

	else {
		cout << "Error writing output file. Exiting program." << endl;
		ExitProgram();
		return;
	}
}
