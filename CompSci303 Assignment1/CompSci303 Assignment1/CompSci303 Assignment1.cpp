// CompSci303 Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Functions.h"

int main()
{
    ifstream inFile;
    inFile.open("Numbers.txt");
    if (!inFile.is_open()) { //This is to catch to see if there is a text file for the array
        cout << "Unable to open file\n";
        return 1;
    }
    int find_Val = 0;
    const int max_size = 150; //max size of the array
    int size = 100; //initial size of the array after implementing all numbers from txt file
    int arr[150] = { }; //initalizing array with max size
    fillMatrix(inFile, arr, size); //filling the array with the text file
    inFile.close();
    int index = 0;//variable that stores user's input for index
    int modifyVal = 0;//variable that stores user's input for new value of chosen index
    int newVal = 0;//variable that stores user's input for adding new value of array.
    bool go_again = true;//variable that determines if user wants to continue adjusting the array
    int getOption = 0;//variable that stores user's input for what function to run. 

    while (go_again == true) {
        cout << "What would you like to check for the array?" << endl;
        cout << "1: Find index of chosen value in array" << endl;
        cout << "2: Modify value of index in array" << endl;
        cout << "3: Add integer to end of array" << endl;
        cout << "4: Remove value of an index from array" << endl;
        cout << "5: Print Array" << endl;
        cout << "6: End program" << endl;
        cin >> getOption;
        if (getOption == 6) {
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            go_again = false;
            break;
        }
        else if (getOption == 1) {
            cout << "What number would you like to find in the array?" << endl;
            cin >> find_Val;
            if (find_Val == -1) {
                cout << "Number " << find_Val << " could not be found in array.";
            }
            returnInd(arr, size, find_Val);
        }
        else if (getOption == 2) {
            cout << "What index would you like to modify?" << endl;
            cin >> index;
            cout << "What value would you like it to be?" << endl;
            cin >> modifyVal;
            //void returnVal(int arr[], int size, int index, int newVal)
            returnVal(arr, size, index, modifyVal);
        }
        else if (getOption == 3) {
            cout << "What value would you like to append to the array?" << endl;
            cin >> newVal;
            //int addVal(int arr[], int& size, int max_size, int newVal)
            addVal(arr, size, max_size, newVal);
        }
        else if (getOption == 4) {
            cout << "What index would you like to remove from the array?" << endl;
            cin >> index;
            //void replaceVal(int arr[], int index, int size);
            replaceVal(arr, index, size);
            cout << "Value at Index " << index << " is now " << arr[index] << endl;
        }
        else if (getOption == 5) {//prints the array to keep track of changes
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else {
            cout << "Not an availabile option" << endl;
        }
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
