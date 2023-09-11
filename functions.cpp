#include <iostream>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

int mainMenu() {
	/*Function is called to provide main menu interface and to assign user int value */
	//pre-function is called in main
	//Post-function returns user value
	while (true) {
		int userInput; //user selects ints 1-5 assigned to functions
		cout << "Main Menu (Enter one of the following intergers for selected funciton)" << endl;
		cout << "1 - (function1) check if interger exists in array, returns index" << endl;
		cout << "2 - (function2) modifies value of int of array using index, returns new and old value" << endl;
		cout << "3 - (function3) appends new int to end of arry" << endl;
		cout << "4 - (function4) takes index of array and removes assigned int" << endl;
		cout << "5 - Print Array Values" << endl;
		cout << "6 - quits program" << endl;
		cout << "Enter Selection: ";

		if (cin >> userInput) {
			for (int i = 1; i <= 6; ++i) {
				if (i == userInput)
					return userInput;     
			}
			cout << endl << endl << "Invalid Input. Try Again." << endl << endl;
		}
		else {
			//handles input errors with invalid data types
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Input. Try Again." << endl << endl;
		}
	}
}


//Fucnction-asks user to input file name, check, opens, and reads file. file is read to Arry taking 10 lines with 10 int
//pre-empty array is delcared in main, file Text.txt exists 
//post-array is returned with filled with file data 
void readFileToArry(int numArray[], int arrLength) {
	string fileName;
	ifstream fin;
	ofstream fout;

	
	while (true) {

		//cout << endl << endl;
		//cout << "Enter text file name(Text.txt): ";
		//cin >> fileName;
		//cout << endl << endl;

		fin.open("Text.txt");
		if (!fin.is_open()) {
			cout << fileName << "failed to open. Try again." << endl;
			continue;
		}
		if (fin.is_open()) {
			for (int i = 0; i < arrLength; i++) { //for loop iteration end point is 100
				fin >> numArray[i]; //reading data until whitespace and assigns to array. nums are str or ints?
				
			}
			
		}
		
		fin.close();
		break;
	}
}




//Functions 1 takes numArray checks weather int exists in array and returns index postion of int if true. FixMe!!!
//pre-array passed, array size is passed, arrray value exists
//post-array value's index is returned to user
void checkValue(int numArray[], int arraySize) {
	int userNum;
	//int arrLength = 100; //length of array FixMe: find workable code to find array length

	while (true) {
		cout << "Enter the intager would you like to find: ";
		if (cin >> userNum) { // if statements checks if value is a int FixMe convert input check to seperate funciton
			if (isdigit(userNum)) {
				cout << endl << endl;
				cout << "Invalid Input(not intager). Try Again." << endl << endl;
				continue;
			}
			else {
				break;

			}
			break;
		}
		else { //else statement handles input errors
			cout << endl << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignores bad input such as strings
			cout << "Invalid Input. Try Again." << endl << endl;
		}

		
	}
	for (int i = 0; i < arraySize; ++i) { //for loop checks 
		if (numArray[i] == userNum) {
			cout << "Intager: " << userNum << "   " << "Index: " << i << endl << endl;
			return;
		}

	}
	cout << "Intager: " << userNum << " (could not be found in array)" << endl << endl;
	return;

}

//print array to users. Used for testing array data
//pre-array and array size is passed
//post-all values of the array are outputed to user
void printArray(int numArray[], int arraySize) {
	cout << "Array Data:" << endl;
	for (int i = 0; i < arraySize; i++) {
		if ((i % 10) == 0)
			cout << endl;
		cout << numArray[i] << " ";
	}
	cout << endl << endl;
	return;
}

//Function2-changeValue
//pre- array and size passed, userValue exists in array
//psot- array returns with new value in selected indext postion
void changeValue(int numArray[], int arraySize) {
	//int length = 100; //array length number FixMe: mutable lengths
	int userIndex;
	int userNewVal = 0;

	while (true) { //loop user for checking input data !!!!!!FixMe: index of Array need work for mutable lengths
		cout << "Input the index number of the value to be changed: ";
		if (cin >> userIndex) {
			if (userIndex >= arraySize || userIndex < 0) {
				cout << "Invalid Index. Try Again." << endl;
				continue;
			}
			
		}
		else {
			//handles input errors with invalid data types
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Input. Try Again." << endl;
			continue;
		}

		cout << endl << endl;
		cout << "Input the value to change for index(" << userIndex << ") : ";
		if (cin >> userNewVal) {
			if (isdigit(userNewVal)) {
				cout << "Invalid Value. Try Again." << endl;
				continue;
			}
			
		}
		else {
			//handles input errors with invalid data types
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Input. Try Again." << endl;
			continue;
		}
		break;
	}
	try {
		for (int i = 0; i < arraySize; ++i) {
			if (i == userIndex) {
				cout << "Index: " << userIndex << " New Value: " << userNewVal << " Old Value: " << numArray[i] << endl << endl;
				numArray[i] = userNewVal; //!!!!!!FixMe: suspect for Runtime error, values -1 < x < 255 crash program (using Visual Studio, works on replit)
				return;  //function exit

			}

		}
	}

	catch (...) {
		cout << "Out_or_bounds exception captured" << endl;
	}

	

}

//Function3-appendValue
//pre- array, temporary array, and size exist
//Post- array returns with appended value size is updated
void appendValue(int numArray[], int newSize) {
	int userVal;
	int tempArray[200];
	
	 
	while (true) {
		cout << "What intager would you like to append to the array? Enter: ";
		if (cin >> userVal) {
			if (isdigit(userVal)) { //FixMe: check isdigit statement
				cout << "Invalid Value. Try Again." << endl;
				continue;
			}

		}
		else {
			//handles input errors with invalid data types
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Input. Try Again." << endl;
			continue;
		}
		break;
	}
	try {
		for (int j = 0; j < 200; ++j) { //zeros out array data
			tempArray[j] = 0;
		}

		for (int i = 0; i < newSize; ++i) {
			tempArray[i] = numArray[i];
		}
		tempArray[newSize - 1] = userVal; //appends to temporary array

		for (int i = 0; i < 200; i++) {
			numArray[i] = tempArray[i];
		}
		return;
	}
	catch (...) {
		cout << "Out_of_bounds expection captured" << endl;
		
	}
}



//Function4-removeValue
//Pre- Takes Array and tracked index postion
//Post- returns Array with selected value turned to zero
void deleteValue(int numArray[], int arraySize) {
	int userVal;
	while (true) {
		cout << "What index postion would you like to delete from the array? Enter: ";
		if (cin >> userVal) {
			if ((userVal < 0) || (userVal > arraySize)) { //FixMe: check isdigit statement
				cout << "Invalid Index. Try Again." << endl;
				continue;
			}

		}
		else {
			//handles input errors with invalid data types
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Input. Try Again." << endl;
			continue;
		}
		break;
	}

	for (int i = 0; i < arraySize; i++){
		if (i == userVal) {
			cout << "Deleted Value: " << numArray[i] << endl;
			numArray[i] = 0;
			return;
		}



	}
	return;
	

}