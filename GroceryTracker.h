//Caelen Knight
//CS 210
//October 15th, 2026

//Declares Grocery Tracker class that runs menu, holds map of produce items, and interacts with user

#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H
#include <map>
#include <string>

using namespace std;


class GroceryTracker {
	public:
		GroceryTracker(); //default constructor
		void PrintOneItem(); //Prints Produce item and count user requested
		void PrintList(); //Prints entire list of produce items and their itemCount
		void PrintHistogram(); //Displays a histogram of all Produce Items and itemcounts
		void ExitProgram(); //sets bool to false to exit program
		bool GetIsRunning() const; //returns bool to main for program exit

	private:
		map<string, int>currentItems; //map of items and the items' counts
		bool isRunning;//Used for program running and exiting
		void CreateMap(); //reads txt file and creates map of items as keys and counts as value
		void CreateOutputFile(); //outputs map into frequency.dat file

};

#endif
