#include "Functions.h"
void fillMatrix(ifstream& inFile, int arr[], int size) {
	for (int r = 0; r < size; r++) {//fills the matrix until it is less than the size. 
		inFile >> arr[r];
	}
}
void returnInd(int arr[], int size, int value) {
	bool foundValue = false;
	int index = 0;
	for (int i = 0; i < size; i++) {//for loop to check the entirity of the array
		if (arr[i] == value) {//if the searched value is found in the array, return the first occurce index of it
			foundValue = true;
			index = i;
		}
	}
	if (foundValue == false) {
		cout << "Searched value could be not be found in array" << endl;
	}
	else {
		cout << value << " was found at index " << index << endl;
	}
}
void returnVal(int arr[], int size, int index, int newValue) {
	try { //try statement to ensure that index is not outside size of array
		if (index >= 0 && index < size) { //checks to make the wanted index is inside the array
			int oldValue = arr[index];
			arr[index] = newValue;
			cout << "Index " << index << "'s old value was: " << oldValue << ". New Value: " << newValue << endl;//prints the old and new value
		}
		else {
			throw (out_of_range("Index is out of range"));//if index is not in array, throw an error
		}
	}
	catch (out_of_range& e) {//catches the out of range error before printing out the error statement
		cout << "An error occured: " << e.what() << endl;
	}
	catch (overflow_error) {//catches the overflow error in case the size is bigger than the array. 
		cout << "Overflow error detected!" << endl;
	}
	catch (...) {//default catch statement
		cout << "An error occured " << endl;
	}
}
void addVal(int arr[], int& size, int max_size, int newVal) {
	try {//try statement to make sure it is not overflowing

		if (size < max_size) {//if size is greater than or equal to max size, throw overflow error
			arr[size] = newVal;//add newVal to end of array
			size++;//increment size for newVal
			cout << newVal << " has been added to the array" << endl;
		}
		else {
			throw overflow_error("Array is past max size");
		}
	}
	catch(overflow_error e){//catch statement for overflow error
		cout << "An error has been detected: " << e.what() << endl;
	}
	catch (...) {//default catch statement in case of other errors
		cout << "An error has been detected: " << endl;
	}
}
int replaceVal(int arr[], int index, int size) {
	/*try {
		if (index >= 0 && index < size) {
			arr[index] = 0;
		}
		else {
			throw (out_of_range("Index is out of range"));
		}
	}
	catch (out_of_range e) {
		cout << 
	}
	*/
	arr[index] = 0; //sets the index's value to zero
	return arr[index];//returns the modified value to the main.cpp
}