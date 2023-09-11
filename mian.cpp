

#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"
using namespace std;

/*Progam: Reads data file that has 10 lines, and each line contains 10 integers into an array*/

int main() {
	//program introduction information to user
	cout << "CS303 Assignment 1" << endl;
	cout << "Instructor: Jawad" << endl;
	cout << "Name: Thomas Reilly" << endl;

	//Variables:
	string fileName;
	int arraySize = 100; // starting size tracker for the arrays. This variable will act as a mutable value for looping purposes 
	int numArray[200]; //starting array will take file data



	//readFileToArry Function call takes Array as parameter, asks user to input file name opens, checks, and reads file to Array
	readFileToArry(numArray, arraySize);
	//cout << numArray[3] << endl; //testing


	
	while (true) {

		//main menu function
		int userNum = mainMenu();

		//Exits program
		if (userNum == 6) {  
			cout << "Exiting program. Goodbye!";
			return 0;
		}

		//Prints array for user and testing
		if (userNum == 5) {
			printArray(numArray, arraySize);
		
		}

		//Functions 1 call takes array and checks if number exists and returns index position
		if (userNum == 1) {
			checkValue(numArray, arraySize);
			continue;
		}

		//Functions 2 Takes index value and changes values of array and outputs to user
		if (userNum == 2) {
			changeValue(numArray, arraySize);
		}

		//Function 3 Takes array, copyies to new array double sized, appends to new array, returns new array
		if (userNum == 3) {
			arraySize += 1;
			appendValue(numArray, arraySize);
		}

		//Function 4 Takes numArray, deletes elemant based on index postion
		if (userNum == 4) {
			deleteValue(numArray, arraySize);
		}

	


	}
	

	
}