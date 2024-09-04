// CSC1061_IC02_ZIP_codes
// This code demonstrates class templates
//	The StatePair class is defined as a template class
//	The class allows for key-value pairs with 
//	different data types. For example an integer
//	ZIP code key could be paired with a string
//	State appreviation (80122 CO)
// Adapted from zyBooks CSC1060 Lab 13.5
// Kathy Geise
// Date: 9/4/24

#include<iostream>
#include<fstream>
#include<vector>
#include"StatePair.h"

using namespace std;

int main() {
	// Variables
	int zip;
	string abbrev;
	int index = -1; // Default is not found

	// Declare a vector to hold sample data
	// ZIP code - state abbreviation pairs
	vector<StatePair <int, string>> zipCodeState;

	// File handling
	// Load the vector from a file 
	ifstream inFS;
	string filename = "zip_code_state.txt";

	inFS.open(filename);
	if (!inFS.is_open()) {
		cout << "Could not open file: " << filename << endl;
		return 1;
	}
	while (!inFS.eof()) {
		//Create a temporary StatePair object
		StatePair<int, string> temp; 

		// Read from the file  
		inFS >> zip;
		if (!inFS.fail()) temp.setKey(zip);
		inFS >> abbrev;
		if (!inFS.fail()) temp.setValue(abbrev);

		// Load the zipCodeState vector
		zipCodeState.push_back(temp);
		// Print the data added to the vector
		//temp.printInfo(); //testing only
	}

	// Test
	cout << "Enter a zip code: ";
	cin >> zip;
	
	// Search the zip code vector for the requested zip code
	for (int i = 0; i < zipCodeState.size(); i++) {
		if (zipCodeState.at(i).getKey() == zip) {
			abbrev = zipCodeState.at(i).getValue();
			index = i;
		}

	}
	// Test that data is found
	cout << "Requested data:  " << endl;
	cout << zip << " : " << abbrev << endl;

	cout << "Print using template function: " << endl;
	if (index != -1) { zipCodeState.at(index).printInfo(); }

	return 0;
}
